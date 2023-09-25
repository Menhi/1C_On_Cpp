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

    void addPurchase_Invoice(int productAmount, std::vector <Product> &allProducts, std::vector <Sale_Invoice> &allSale_Invoices);

    void setProductsLikeVector (std::vector<Product> listOfProduct){products = listOfProduct;}

    void setProductsLikeLine (int Code, std::string Name, int Amount, float Price){
        Product temp (Code, Name, Amount, Price);
        products.emplace_back(temp);}

    std::vector<Product> getVectorProduct() {return products;}

    void show (){
        std::cout<<getCode()<<" ";
        getCode() > 9 ? std::cout<<getDay() : std::cout<<"0"<<getDay()<<".";
        getCode() > 9 ? std::cout<<getMonth() : std::cout<<"0"<<getMonth()<<".";
        std::cout<<getYear()<<" "<<getCounterpartyName()<<std::endl;
    }
};


#endif // SALE_INVOICE_H
