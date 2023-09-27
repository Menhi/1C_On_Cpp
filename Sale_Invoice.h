#ifndef SALE_INVOICE_H
#define SALE_INVOICE_H

#include <Includes.h>
#include <General_Documents.h>
#include <Product.h>
#include <Counterparty.h>

class Sale_Invoice : public DocumentWithCounterparty{
    std::vector<Product> products;
    std::vector<float> productCostPrice;
public:
    Sale_Invoice(int Code, int Day, int Month, int Year, Counterparty Counterparty) : DocumentWithCounterparty(Code, Day, Month, Year, Counterparty){}

    void addPurchase_Invoice(int productAmount, std::vector <Product> &allProducts, std::vector <Sale_Invoice> &allSale_Invoices);

    void setProductsLikeVector (std::vector<Product> listOfProduct){products = listOfProduct;}

    void setProductsLikeLine (int Code, std::string Name, int Amount, float Price){
        Product temp (Code, Name, Amount, Price);
        products.emplace_back(temp);}

    std::vector<Product> getVectorProduct() {return products;}

    void setProductCostPrice (std::vector<Product> allProducts, Sale_Invoice saleInvoice);

    void show (){
        std::cout<<"Code    Date    Counterparty\n";
        std::cout<<getCode()<<"    ";
        getDay() > 9 ? std::cout<<getDay() : std::cout<<"0"<<getDay();
        std::cout<<".";
        getMonth() > 9 ? std::cout<<getMonth() : std::cout<<"0"<<getMonth();
        std::cout<<".";
        std::cout<<getYear()<<" "<<getCounterpartyName()<<std::endl;
        std::cout<<"Code Name Amount Price\n";
        for (auto product : this->products)
            product.show();
    }
};

void showSaleInvoice (std::vector <Sale_Invoice> allSale_Invoices);

void addSale_Invoice(std::vector <Product> &allProducts, std::vector<Counterparty> allCounterparties, std::vector <Sale_Invoice> &allSale_Invoices);

void saveSale_InvoicesToFile(std::vector<Sale_Invoice> sale_Invoices);

int loadSale_InvoicesFromFile(std::vector<Sale_Invoice> &sale_Invoices, std::vector<Counterparty> allCounterparties);

void saveProductsFromSale_InvoicesToFile(std::vector<Sale_Invoice> sale_Invoices);

int loadProductsFromSale_InvoicesToFile(std::vector<Sale_Invoice> &sale_Invoices, std::vector<Product> &allProducts);



#endif // SALE_INVOICE_H
