#ifndef PURCHASE_INVOICE_H
#define PURCHASE_INVOICE_H

#include <Includes.h>
#include <General_Documents.h>
#include <Product.h>

class Purchase_Invoice : public Document{
    std::vector<Product> Products;
public:
    Purchase_Invoice(int Code, int Day, int Month, int Year) : Document(Code, Day, Month, Year){}
    void setVectorProduct(int productAmount){
        int tempCode;
        int tempAmount;
        double tempPrice;

        for (int i=0; i<productAmount; i++){
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




#endif // PURCHASE_INVOICE_H
