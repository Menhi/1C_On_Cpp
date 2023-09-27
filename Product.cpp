#include <Includes.h>
#include <Product.h>

void addProduct (std::vector <Product> &allProducts){
    std::cout<<"Enter name of Product: ";
    std::string tempName;
    std::cin>>tempName;
    std::cin.ignore();
    allProducts.emplace_back(allProducts.back().getCode()+1, tempName, 0, 0.f);
    system("cls");
    std::cout<<"Product saved.\n\n";
}

int showProduct (std::vector <Product> &allProducts){
    if (allProducts.size() != 1){
        std::cout<<"Code Name Amount Price\n";
        for (auto product : allProducts){
            if (product.getCode() == 0)
                continue;
            product.show();
        }
        std::cout<<"\n\n";
        return 0;
    }
    else std::cout<<"You have no Products\n";
    std::cout<<"\n\n";
    return 1;
}


void saveProductsToFile(std::vector<Product>& products) {
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
        float Price;


        if (iss >> Code >> Name >> Amount >> Price) {
            products.emplace_back(Code, Name, Amount, Price);
        } else {
            std::cerr << "Error with string: " << line << std::endl;
        }
    }
    inputFile.close();
    return 0;
}
