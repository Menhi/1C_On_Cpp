#include <Includes.h>
#include <Purchase_Invoice.h>
#include <Product.h>
#include <windows.h>
#include <Counterparty.h>


void showPurchaseInvoice (std::vector<Purchase_Invoice> allPurchase_Invoices){
    if (allPurchase_Invoices.size() <= 1){
        std::cout<<"You have no Purchase invoices\n";
        std::cout<<"\n\n";
        return;
    }

    for (auto purchase_Invoice : allPurchase_Invoices){
        if (purchase_Invoice.getCode() != 0){
            purchase_Invoice.show();
            std::cout<<"\n";
        }
    }
    std::cout<<"\n\n";
}





void addPurchase_Invoice(std::vector <Product> &allProducts, std::vector<Counterparty> allCounterparties, std::vector <Purchase_Invoice> &allPurchase_Invoices){
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
        std::cout<<"How many type of products you want to buy?\n";
        std::cin >> tempAmountOfProductsInDoc;
        if (!std::cin >> tempAmountOfProductsInDoc || tempAmountOfProductsInDoc == 0 || tempAmountOfProductsInDoc > allProducts.size() - 1){
            std::cin.clear();
            system("cls");
            std::cout<<"Wrong value. Try again\n\n";
        }
    }while (!std::cin >> tempAmountOfProductsInDoc);

    std::cout<<"List of products:\n";
    if (showProduct(allProducts) == 1)
        return;

    int tempCode;
    int tempAmount;
    float tempPrice;
    Purchase_Invoice tempPurchase_invoice(allPurchase_Invoices.back().getCode()+1, st.wDay, st.wMonth, st.wYear, allCounterparties[tempCounterpartyCode]);

    for (unsigned i=0; i<tempAmountOfProductsInDoc; i++){
        std::cout<<"Code of product "<< i + 1<< ": ";
        std::cin>>tempCode;
        std::cout<<"Amount of product "<< i + 1<< ": ";
        std::cin>>tempAmount;
        std::cout<<"Price of product "<< i + 1<< ": ";
        std::cin>>tempPrice;
        if (allProducts[tempCode].getCode() == tempCode && tempAmount != 0){
            tempPurchase_invoice.setProductsLikeLine(tempCode, allProducts[tempCode].getName(), tempAmount, tempPrice);
        }
        else {
            std::cout<<"Wrong code or amount Try again\n\n";
            i--;
        }
        std::cout<<"\n";
    }

    system("cls");
    std::cout<<"This is your purchase invoice. Save it?\n"
               "1 - yes\n"
               "any - no\n\n";
    tempPurchase_invoice.show();

    char choice;
    std::cin>>choice;
    if (choice != '1'){
        system("cls");
        std::cout<<"Purchase didnt save.\n\n";
        return;
    }

    allPurchase_Invoices.emplace_back(tempPurchase_invoice);

    int tempProductCode;

    for (unsigned i = 0; i < tempPurchase_invoice.getVectorProduct().size(); i++){
        tempProductCode = tempPurchase_invoice.getVectorProduct()[i].getCode();

        allProducts[tempProductCode].setPrice((tempPurchase_invoice.getVectorProduct()[i].getPrice()*tempPurchase_invoice.getVectorProduct()[i].getAmount() +
                                                                                    allProducts[tempPurchase_invoice.getVectorProduct()[i].getCode()].getAmount()*allProducts[tempPurchase_invoice.getVectorProduct()[i].getCode()].getPrice())/
                (tempPurchase_invoice.getVectorProduct()[i].getAmount()+allProducts[tempPurchase_invoice.getVectorProduct()[i].getCode()].getAmount()));

        allProducts[tempPurchase_invoice.getVectorProduct()[i].getCode()].setAmount(tempPurchase_invoice.getVectorProduct()[i].getAmount()+allProducts[tempPurchase_invoice.getVectorProduct()[i].getCode()].getAmount());
    }



    system("cls");
    std::cout<<"Purchase invoice saved.\n\n";
}


void savePurchase_InvoicesToFile(std::vector<Purchase_Invoice> purchase_Invoices) {
    std::ofstream outputFile("Purchase_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& purchase_Invoice : purchase_Invoices)
            outputFile <<purchase_Invoice.getCode()<<" "
                      <<purchase_Invoice.getDay()<<" "
                     <<purchase_Invoice.getMonth()<<" "
                    <<purchase_Invoice.getYear()<<" "
                   <<purchase_Invoice.getCounterpartyCode()<<"\n";
        outputFile.close();
        std::cout << "Purchase_Invoices have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Purchase_Invoices." << std::endl;
    }
}

int loadPurchase_InvoicesFromFile(std::vector<Purchase_Invoice> &purchase_Invoices, std::vector<Counterparty> allCounterparties)
{
    std::ifstream inputFile("Purchase_Invoices.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Purchase_Invoices.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 3" << std::endl;
            return 3;
        }
        outputFile << "0 0 0 0 0\n";
        outputFile.close();

        inputFile.open("Purchase_Invoices.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 4" << std::endl;
            return 4;
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
            purchase_Invoices.emplace_back(Code, Day, Month, Year, allCounterparties[CounterpartyCode]);
        } else {
            std::cerr << "Purchase_Invoices: Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}


void saveProductsFromPurchase_InvoicesToFile(std::vector<Purchase_Invoice> purchase_Invoices) {
    std::ofstream outputFile("Products_From_Purchase_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& purchase_Invoice : purchase_Invoices) {

            int Code = purchase_Invoice.getCode();

            if (Code == 0) continue;

            outputFile << Code << " ";
            for (auto product : purchase_Invoice.getVectorProduct()) {
                outputFile << product.getCode() << " " << product.getName() << " " << product.getAmount() << " " << product.getPrice() << "\n";
            }
        }
        outputFile.close();
        std::cout << "Products_From_Purchase_Invoices have been saved to the file." << std::endl;
    }
    else {
        std::cout << "Unable to open the file for saving Products_From_Purchase_Invoices." << std::endl;
    }
}





int loadProductsFromPurchase_InvoicesToFile(std::vector<Purchase_Invoice> &purchase_Invoices, std::vector<Product> &allProducts)
{
    std::ifstream inputFile("Products_From_Purchase_Invoices.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Products_From_Purchase_Invoices.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 9" << std::endl;
            return 9;
        }
        outputFile.close();

        inputFile.open("Products_From_Purchase_Invoices.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 10" << std::endl;
            return 10;
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
            purchase_Invoices[DocCode].setProductsLikeLine(ProductCode, allProducts[ProductCode].getName(), Amount, Price);
        } else {
            std::cerr << "Products_From_Purchase_Invoices: Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}
