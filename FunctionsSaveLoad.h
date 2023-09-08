#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include<Includes.h>



void saveProductsToFile( std::vector<Product>& products) {
    std::ofstream outputFile("Products.txt");
    if (outputFile.is_open()) {
        for (auto& product : products)
            outputFile <<product.getCode()<<" "
                       <<product.getName()<<" "
                       <<product.getAmount()<<" "
                       <<product.getPrice();
        outputFile.close();
        std::cout << "Products have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Products." << std::endl;
    }
}

int loadProductsFromFile(std::vector<Product> &products)
{
    std::ifstream inputFile("Products.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Products.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 1" << std::endl;
            return 1;
        }
        outputFile << "0 0 0 0\n";
        outputFile.close();

        inputFile.open("Products.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 2" << std::endl;
            return 2;
        }
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int Code;
        std::string Name;
        int Amount;
        double Price;


        if (iss >> Code >> Name >> Amount >> Price) {
            products.emplace_back(Code, Name, Amount, Price);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}



void savePurchase_InvoicesToFile( std::vector<Purchase_Invoice> &purchase_Invoices) {
    std::ofstream outputFile("Purchase_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& purchase_Invoice : purchase_Invoices)
            outputFile <<purchase_Invoice.getCode()<<" "
                       <<purchase_Invoice.getDay()<<" "
                       <<purchase_Invoice.getMonth()<<" "
                       <<purchase_Invoice.getYear();
        outputFile.close();
        std::cout << "Purchase_Invoices have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Purchase_Invoices." << std::endl;
    }
}

int loadPurchase_InvoicesFromFile(std::vector<Purchase_Invoice> &purchase_Invoices)
{
    std::ifstream inputFile("Purchase_Invoices.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Purchase_Invoices.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 3" << std::endl;
            return 3;
        }
        outputFile << "0 0 0 0\n";
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
        int Code;
        int Day;
        int Month;
        int Year;


        if (iss >> Code >> Day >> Month >> Year) {
            purchase_Invoices.emplace_back(Code, Day, Month, Year);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}



void saveSale_InvoicesToFile( std::vector<Sale_Invoice>& sale_Invoices) {
    std::ofstream outputFile("Sale_Invoices.txt");
    if (outputFile.is_open()) {
        for (auto& sale_Invoice : sale_Invoices)
            outputFile <<sale_Invoice.getCode()<<" "
                       <<sale_Invoice.getDay()<<" "
                       <<sale_Invoice.getMonth()<<" "
                       <<sale_Invoice.getYear();
        outputFile.close();
        std::cout << "Sale_Invoices have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Sale_Invoices." << std::endl;
    }
}

int loadSale_InvoicesFromFile(std::vector<Sale_Invoice> &sale_Invoices)
{
    std::ifstream inputFile("Sale_Invoices.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Sale_Invoices.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 5" << std::endl;
            return 5;
        }
        outputFile << "0 0 0 0\n";
        outputFile.close();

        inputFile.open("Sale_Invoice.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 6" << std::endl;
            return 6;
        }
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int Code;
        std::string Name;
        int Amount;
        double Price;


        if (iss >> Code >> Name >> Amount >> Price) {
            sale_Invoices.emplace_back(Code, Name, Amount, Price);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}


#endif // FUNCTIONS_H
