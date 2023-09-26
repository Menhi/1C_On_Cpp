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

void saveProductsToFile(std::vector<Product>& products);

int loadProductsFromFile(std::vector<Product> &products);

void addProduct (std::vector <Product> &allProducts);

int showProduct (std::vector <Product> &allProducts);


#endif // PRODUCT_H
