#ifndef SALE_INVOICE_H
#define SALE_INVOICE_H

#include <Includes.h>
#include <General_Documents.h>
#include <Product.h>
#include <Counterparty.h>

class Sale_Invoice : public DocumentWithCounterparty{
    std::vector<Product> products;
public:
    Sale_Invoice(int Code, int Day, int Month, int Year, Counterparty Counterparty) : DocumentWithCounterparty(Code, Day, Month, Year, Counterparty){}

    void setVectorProduct(int productAmount, std::vector <Product> &allProducts){
        int tempCode;
        int tempAmount;
        double tempPrice;

        for (int i=0; i<productAmount; i++){
            std::cout<<"Code of product: ";
            std::cin>>tempCode;
            std::cout<<"Amount of product: ";
            std::cin>>tempAmount;
            std::cout<<"Price of product: ";
            std::cin>>tempPrice;
            if (allProducts[tempCode].getCode() == tempCode){
                products.emplace_back(tempCode, allProducts[tempCode].getName(), tempAmount, tempPrice);
                allProducts[tempCode].setPrice((tempPrice*tempAmount+
                                                allProducts[tempCode].getAmount()*allProducts[tempCode].getPrice())/
                                               (tempAmount+allProducts[tempCode].getAmount()));
                allProducts[tempCode].setAmount(tempAmount+allProducts[tempCode].getAmount());
            }
            else {
                std::cout<<"Wrong code. Try again\n\n";
                i--;
            }
        }
    }

    std::vector<Product> getVectorProduct() {return products;}

    void show (){
        std::cout<<getCode();
        getCode() > 9 ? std::cout<<getDay() : std::cout<<"0"<<getDay();
        getCode() > 9 ? std::cout<<getMonth() : std::cout<<"0"<<getMonth();
        std::cout<<getYear()<<" "<<getCounterpartyName()<<std::endl;
    }

};


#endif // SALE_INVOICE_H
