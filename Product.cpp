#include <Includes.h>
#include <Product.h>

void addProduct (std::vector <Product> &allProducts){
    system("cls");
    std::cout<<"Enter name of Product: ";
    std::string tempName;
    std::getline(std::cin, tempName);
    allProducts.emplace_back(allProducts.back().getCode()+1, tempName, 0, 0);
    system("cls");
    std::cout<<"Product saved.\n\n";
}

void showProduct (std::vector <Product> &allProducts){
    system("cls");
    std::cout<<"Code Name Amount Price\n";
    for (auto product : allProducts){
        if (product.getCode() != 0)
            product.show();
    }
    std::cout<<"\n\n";
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

