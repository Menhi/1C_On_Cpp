#ifndef PRODUCT_H
#define PRODUCT_H

#include<Includes.h>

class Product{
    int code;
    std::string name;
    int amount;
    float price;
public:
    Product (int Code, std::string Name, int Amount, float Price) : code(Code), name(Name), amount(Amount), price(Price){};

    void setCode(int Code){code = Code;}
    void setName(std::string Name){name = Name;}
    void setAmount(int Amount){amount = Amount;}
    void setPrice(float Price){price = Price;}

    int getCode(){return code;}
    std::string getName(){return name;}
    int getAmount(){return amount;}
    float getPrice(){return price;}

    void show(){
        std::cout<<getCode()<<"    "<<getName()<< " " <<getAmount()<< " " <<getPrice()<<std::endl;
    }
};


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


#endif // PRODUCT_H
