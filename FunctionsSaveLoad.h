#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include<Includes.h>

#include <Product.h>
#include <Purchase_Invoice.h>
#include <Sale_Invoice.h>
#include <General_Documents.h>
#include <Counterparties.h>


void saveProductsToFile( std::vector<Product>& products) {
    std::ofstream outputFile("Products.txt");
    if (outputFile.is_open()) {
        for (auto& product : products)
            outputFile <<product.getCode()<<" "
                       <<product.getName()<<" "
                       <<product.getAmount()<<" "
                       <<product.getPrice()<<"\n";
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
                       <<purchase_Invoice.getYear()<<"\n";
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
                       <<sale_Invoice.getYear()<<"\n";
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
        int Day;
        int Month;
        int Year;


        if (iss >> Code >> Day >> Month >> Year) {
            sale_Invoices.emplace_back(Code, Day, Month, Year);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}



void saveProductsInPurchase_InvoiceToFile (std::vector<Product>& products) {
    std::ofstream outputFile("Products_In_Purchase_Invoice.txt");
    if (outputFile.is_open()) {
        for (auto& product : products)
            outputFile <<product.getCode()<<" "
                       <<product.getName()<<" "
                       <<product.getAmount()<<" "
                       <<product.getPrice();
        outputFile.close();
        std::cout << "Products_In_Purchase_Invoice have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Products_In_Purchase_Invoice." << std::endl;
    }
}

int loadProductsInPurchase_InvoiceToFile (std::vector<Product> &products)
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


void saveCounterpartiesToFile( std::vector<Counterparty>& counterparties) {
    std::ofstream outputFile("Сounterparties.txt");
    if (outputFile.is_open()) {
        for (auto& counterparty : counterparties)
            outputFile <<counterparty.getCode()<<" "
                       <<counterparty.getName()<<" "
                       <<counterparty.getDiscount()<<"\n";
        outputFile.close();
        std::cout << "Сounterparties have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Сounterparties." << std::endl;
    }
}

int loadCounterpartiesFromFile(std::vector<Counterparty>& counterparties)
{
    std::ifstream inputFile("Сounterparties.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Сounterparties.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 9" << std::endl;
            return 9;
        }
        outputFile << "0 0 0 0\n";
        outputFile.close();

        inputFile.open("Сounterparties.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 10" << std::endl;
            return 10;
        }
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int Code;
        std::string Name;
        int Discount;

        if (iss >> Code >> Name >> Discount) {
            counterparties.emplace_back(Code, Name, Discount);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}

void saveProductAccountingToFile( std::vector<Product>& productsAccounting, int codeOfDocument, int amountProductsInDocument) {
    std::ofstream outputFile("Products Accounting.txt");
    if (outputFile.is_open()) {
        for (auto& ProductAccounting : productsAccounting)
            outputFile <<codeOfDocument<<" "
                       <<ProductAccounting.getCode()<<" "
                       <<amountProductsInDocument<<"\n";
        outputFile.close();
        std::cout << "Products Accounting have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving Products Accounting." << std::endl;
    }
}

int loadProductAccountingFromFile(std::vector<Product>& productsAccounting)
{
    std::ifstream inputFile("Products Accounting.txt");
    if (!inputFile.is_open()) {
        std::ofstream outputFile("Products Accounting.txt");
        if (!outputFile.is_open()) {
            std::cerr << "Error 11" << std::endl;
            return 9;
        }
        outputFile << "0 0 0 0\n";
        outputFile.close();

        inputFile.open("Products Accounting.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error 12" << std::endl;
            return 10;
        }
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int Code;
        std::string Name;
        int Discount;

        if (iss >> Code >> Name >> Discount) {
            counterparties.emplace_back(Code, Name, Discount);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}





#endif // FUNCTIONS_H
