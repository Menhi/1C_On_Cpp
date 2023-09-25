#include <Includes.h>
#include <Sale_Invoice.h>
#include <Product.h>
#include <windows.h>
#include <Counterparty.cpp>
//#include <limits.h>

void showSaleInvoice (std::vector <Sale_Invoice> allSale_Invoices){
    system("cls");
    std::cout<<"Code Date        Counterparty\n";
    for (auto sale_Invoice : allSale_Invoices){
        if (sale_Invoice.getCode() != 0)
            sale_Invoice.show();
        std::cout<<"Code Name Amount Price\n";
        for (auto product : sale_Invoice.getVectorProduct())
            product.show();
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
        showCounterparties(allCounterparties);
        std::cin>>tempCounterpartyCode;
        if (tempCounterpartyCode == 0) {system("cls"); return;}
        if (tempCounterpartyCode <= 0 || tempCounterpartyCode >= allCounterparties.size()) std::cout<<"Wrong code. Try again\n\n";
    }while (tempCounterpartyCode <= 0 || tempCounterpartyCode >= allCounterparties.size());

    std::cout<<"How many type of products you want to buy?\n";
    do{
        std::cin >> tempAmountOfProductsInDoc;
        if (!std::cin >> tempAmountOfProductsInDoc){
            std::cin.clear();
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Wrong value. Try again\n\n";
        }
    }while (!std::cin >> tempAmountOfProductsInDoc);

    int tempCode;
    int tempAmount;
    float tempPrice;
    std::vector <Product> tempProducts;

    for (unsigned i=0; i<tempAmountOfProductsInDoc; i++){
        std::cout<<"Code of product: ";
        std::cin>>tempCode;
        std::cout<<"Amount of product: ";
        std::cin>>tempAmount;
        std::cout<<"Price of product: ";
        std::cin>>tempPrice;
        if (allProducts[tempCode].getCode() == tempCode){
            tempProducts.emplace_back(tempCode, allProducts[tempCode].getName(), tempAmount, tempPrice);

            if (allProducts[tempCode].getPrice() != 0)
                allProducts[tempCode].setPrice((tempPrice*tempAmount + allProducts[tempCode].getAmount()*allProducts[tempCode].getPrice())/
                                               (tempAmount+allProducts[tempCode].getAmount()));
            else
                allProducts[tempCode].setPrice(0);
            allProducts[tempCode].setAmount(tempAmount+allProducts[tempCode].getAmount());
        }
        else {
            std::cout<<"Wrong code. Try again\n\n";
            i--;
        }
    }

    allSale_Invoices.emplace_back(allSale_Invoices.back().getCode()+1, st.wDay, st.wMonth, st.wYear, allCounterparties[tempCounterpartyCode]);
    allSale_Invoices.back().setProductsLikeVector(tempProducts);
    system("cls");
    std::cout<<"Purchase invoice saved.\n\n";
}


void saveSale_InvoicesToFile(std::vector<Sale_Invoice> sale_Invoices) {
    std::ofstream outputFile("Purchase_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& sale_Invoice : sale_Invoices)
            outputFile <<sale_Invoice.getCode()<<" "
                      <<sale_Invoice.getDay()<<" "
                     <<sale_Invoice.getMonth()<<" "
                    <<sale_Invoice.getYear()<<" "
                   <<sale_Invoice.getCounterpartyCode()<<"\n";
        outputFile.close();
        std::cout << "Purchase_Invoices have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Purchase_Invoices." << std::endl;
    }
}

int loadSale_InvoicesFromFile(std::vector<Sale_Invoice> &sale_Invoices, std::vector<Counterparty> allCounterparties)
{
    std::ifstream inputFile("Sale_Invoice.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Sale_Invoice.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 3" << std::endl;
            return 5;
        }
        outputFile << "0 0 0 0 0\n";
        outputFile.close();

        inputFile.open("Sale_Invoice.txt");
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
    std::ofstream outputFile("Products_From_Purchase_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& sale_Invoice : sale_Invoices){
            outputFile <<sale_Invoice.getCode()<<" ";
            for (auto product : sale_Invoice.getVectorProduct())
                outputFile<<product.getCode()<<" "<<product.getName()<<" "<<product.getAmount()<<" "<<product.getPrice()<<"\n";
        }
        outputFile.close();
        std::cout << "Products_From_Purchase_Invoices have been saved to the file." << std::endl;
    }
    else {
        std::cout << "Unable to open the file for saving Products_From_Purchase_Invoices." << std::endl;
    }
}

int loadProductsFromPurchase_InvoicesToFile(std::vector<Sale_Invoice> &sale_Invoices, std::vector<Product> &allProducts)
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
