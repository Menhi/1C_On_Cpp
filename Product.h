#ifndef PRODUCT_H
#define PRODUCT_H

#include<Includes.h>

class Product{
    int code;
    std::string name;
    int amount;
    double price;
public:
    Product (int Code, std::string Name, int Amount, double Price) : code(Code), name(Name), amount(Amount), price(Price){};

    void setCode(int Code){code = Code;}
    void setName(std::string Name){name = Name;}
    void setAmount(int Amount){amount = Amount;}
    void setPrice(double Price){price = Price;}

    int getCode(){return code;}
    std::string getName(){return name;}
    int getAmount(){return amount;}
    double getPrice(){return price;}
};




#endif // PRODUCT_H
