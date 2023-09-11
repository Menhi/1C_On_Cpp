#ifndef SALE_INVOICE_H
#define SALE_INVOICE_H

#include <Includes.h>
#include <General_Documents.h>
#include <Product.h>
#include <Counterparties.h>

class Sale_Invoice : public Document{
    std::vector<Product> Products;
    Counterparty counterparty;
public:
    Sale_Invoice(int Code, int Day, int Month, int Year, Counterparty Counterparty) : Document(Code, Day, Month, Year), counterparty(Counterparty){}
    void setVectorProduct(int spareAmount){
        int tempCode;
        int tempAmount;
        double tempPrice;

        for (int i=0; i<spareAmount; i++){
            std::cout<<"Code of spare:";
            std::cin>>tempCode;
            std::cout<<"Amount of spare:";
            std::cin>>tempAmount;
            std::cout<<"Price of spare:";
            std::cin>>tempPrice;
            Products.emplace_back(tempCode, "", tempAmount, tempPrice);
            }
    }
    std::vector<Product> getVectorProduct() {return Products;}

};


#endif // SALE_INVOICE_H
