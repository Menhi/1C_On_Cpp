#ifndef PURCHASE_INVOICE_H
#define PURCHASE_INVOICE_H

#include <Includes.h>
#include <General_Documents.h>
#include <Product.h>
#include <Counterparties.h>
#include <FunctionsSaveLoad.h>

class Purchase_Invoice : public Document{
    std::vector<Product> Products;
    Counterparty counterparty;
public:
    Purchase_Invoice(int Code, int Day, int Month, int Year, Counterparty Counterparty) : Document(Code, Day, Month, Year), counterparty(Counterparty){}
    void setVectorProduct(int productAmount, std::vector <Product> allProducts){
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
                Products.emplace_back(tempCode, allProducts[tempCode].getName(), tempAmount, tempPrice);
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
    std::vector<Product> getVectorProduct() {return Products;}





};




#endif // PURCHASE_INVOICE_H
