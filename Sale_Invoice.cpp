#include <Includes.h>
#include <Sale_Invoice.h>
#include <Product.h>
#include <windows.h>
#include <Counterparty.h>

void showSaleInvoice (std::vector <Sale_Invoice> allSale_Invoices){
    if (allSale_Invoices.size() <= 1){
        std::cout<<"You have no Sale invoices\n";
        std::cout<<"\n\n";
        return;
    }

    for (auto sale_Invoice : allSale_Invoices){
        if (sale_Invoice.getCode() == 0)
            continue;
        sale_Invoice.show();
        std::cout<<"\n";
    }
    std::cout<<"\n\n";
}



void addSale_Invoice(std::vector <Product> &allProducts, std::vector<Counterparty> allCounterparties, std::vector <Sale_Invoice> &allSale_Invoices){
    SYSTEMTIME st;
    GetLocalTime(&st);

    unsigned tempCounterpartyCode;
    unsigned tempAmountOfProductsInDoc;
    do{
        std::cout<<"Choose and enter code of counterparty or enter 0 for exit\n";
        if (showCounterparties(allCounterparties) == 1)
            return;
        std::cin>>tempCounterpartyCode;
        if (tempCounterpartyCode == 0) {system("cls"); return;}
        if (tempCounterpartyCode <= 0 || tempCounterpartyCode >= allCounterparties.size()) std::cout<<"Wrong code. Try again\n\n";
    }while (tempCounterpartyCode <= 0 || tempCounterpartyCode >= allCounterparties.size());

    do{
        std::cout<<"How many type of products you want to sale?\n";
        std::cin >> tempAmountOfProductsInDoc;
        if (!std::cin >> tempAmountOfProductsInDoc || tempAmountOfProductsInDoc == 0 || tempAmountOfProductsInDoc > allProducts.size() - 1){
            std::cin.clear();
            system("cls");
            std::cout<<"Wrong value. Try again\n\n";
        }
    }while (!std::cin >> tempAmountOfProductsInDoc);

    std::cout<<"\nList of products:\n";
    if (showProduct(allProducts) == 1)
        return;

    int tempCode;
    int tempAmount;
    float tempPrice;
    Sale_Invoice tempSale_invoice(allSale_Invoices.back().getCode()+1, st.wDay, st.wMonth, st.wYear, allCounterparties[tempCounterpartyCode]);

    for (unsigned i=0; i<tempAmountOfProductsInDoc; i++){
        std::cout<<"Code of product: ";
        std::cin>>tempCode;
        std::cout<<"Amount of product: ";
        std::cin>>tempAmount;
        tempPrice = (allProducts[tempCode].getPrice() + allProducts[tempCode].getPrice()*40/100 - allProducts[tempCode].getPrice()*allCounterparties[tempCounterpartyCode].getDiscount()/100);
        if (allProducts[tempCode].getCode() == tempCode && allProducts[tempCode].getAmount() >= tempAmount && tempAmount != 0){
            tempSale_invoice.setProductsLikeLine(tempCode, allProducts[tempCode].getName(), tempAmount, tempPrice);
        }
        else {
            std::cout<<"Wrong code or amount. Try again\n\n";
            i--;
        }
        std::cout<<"\n";
    }

    system("cls");
    std::cout<<"This is your sale invoice. Save it?\n"
               "1 - yes\n"
               "any - no\n\n";
    tempSale_invoice.show();


    char choice;
    std::cin>>choice;
    if (choice != '1'){
        system("cls");
        std::cout<<"Sale didnt save.\n\n";
        return;
    }

    allSale_Invoices.emplace_back(tempSale_invoice);



    for (unsigned i = 0; i < tempSale_invoice.getVectorProduct().size(); i++)
        allProducts[tempSale_invoice.getVectorProduct()[i].getCode()].setAmount(allProducts[tempSale_invoice.getVectorProduct()[i].getCode()].getAmount()-tempSale_invoice.getVectorProduct()[i].getAmount());


    system("cls");
    std::cout<<"Sale invoice saved.\n\n";
}


void saveSale_InvoicesToFile(std::vector<Sale_Invoice> sale_Invoices) {
    std::ofstream outputFile("Sale_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& sale_Invoice : sale_Invoices)
            outputFile <<sale_Invoice.getCode()<<" "
                      <<sale_Invoice.getDay()<<" "
                     <<sale_Invoice.getMonth()<<" "
                    <<sale_Invoice.getYear()<<" "
                   <<sale_Invoice.getCounterpartyCode()<<"\n";
        outputFile.close();
        std::cout << "Sale_Invoices have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Sale_Invoices." << std::endl;
    }
}

int loadSale_InvoicesFromFile(std::vector<Sale_Invoice> &sale_Invoices, std::vector<Counterparty> allCounterparties)
{
    std::ifstream inputFile("Sale_Invoices.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Sale_Invoices.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 3" << std::endl;
            return 5;
        }
        outputFile << "0 0 0 0 0\n";
        outputFile.close();

        inputFile.open("Sale_Invoices.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 4" << std::endl;
            return 6;
        }
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int Code = 0;
        int Day = 0;
        int Month = 0;
        int Year = 0;
        int CounterpartyCode = 0;


        if (iss >> Code >> Day >> Month >> Year >> CounterpartyCode) {
            sale_Invoices.emplace_back(Code, Day, Month, Year, allCounterparties[CounterpartyCode]);
        } else {
            std::cerr << "Sale_Invoices: Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}


void saveProductsFromSale_InvoicesToFile(std::vector<Sale_Invoice> sale_Invoices) {
    std::ofstream outputFile("Products_From_Sale_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& sale_Invoice : sale_Invoices) {

            if (sale_Invoice.getCode() == 0) continue;

            for (auto product : sale_Invoice.getVectorProduct()) {
                outputFile << sale_Invoice.getCode() << " " << product.getCode() << " " << product.getName() << " " << product.getAmount() << " " << product.getPrice() << "\n";
            }
        }
        outputFile.close();
        std::cout << "Products_From_Sale_Invoices have been saved to the file." << std::endl;
    }
    else {
        std::cout << "Unable to open the file for saving Products_From_Sale_Invoices." << std::endl;
    }
}

int loadProductsFromSale_InvoicesToFile(std::vector<Sale_Invoice> &sale_Invoices, std::vector<Product> &allProducts)
{
    std::ifstream inputFile("Products_From_Sale_Invoices.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Products_From_Sale_Invoices.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 9" << std::endl;
            return 11;
        }
        outputFile.close();

        inputFile.open("Products_From_Sale_Invoices.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 10" << std::endl;
            return 12;
        }
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int DocCode;
        int ProductCode;
        std::string Name;
        int Amount;
        float Price;

        if (iss >> DocCode >> ProductCode >> Name >> Amount >> Price) {
            sale_Invoices[DocCode].setProductsLikeLine(ProductCode, allProducts[ProductCode].getName(), Amount, Price);
        } else {
            std::cerr << "Products_From_Sale_Invoices: Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}


void Sale_Invoice :: setProductCostPrice (std::vector<Product> allProducts, Sale_Invoice saleInvoice){
    for (unsigned i = 0; i < saleInvoice.getVectorProduct().size(); i++){
        saleInvoice.productCostPrice[i] = allProducts[saleInvoice.products[i].getCode()].getPrice();
    }
}
