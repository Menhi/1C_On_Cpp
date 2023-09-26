#ifndef PURCHASE_INVOICE_H
#define PURCHASE_INVOICE_H

#include <Includes.h>
#include <General_Documents.h>
#include <Product.h>
#include <Counterparty.h>

class Purchase_Invoice : public DocumentWithCounterparty{
    std::vector<Product> products;
public:
    Purchase_Invoice(int Code, int Day, int Month, int Year, Counterparty Counterparty) : DocumentWithCounterparty(Code, Day, Month, Year, Counterparty){}

    void addPurchase_Invoice(int productAmount, std::vector <Product> &allProducts, std::vector <Purchase_Invoice> &allPurchase_Invoices);

    void setProductsLikeVector (std::vector<Product> listOfProduct){products = listOfProduct;}

    void setProductsLikeLine (int Code, std::string Name, int Amount, float Price){
        Product temp (Code, Name, Amount, Price);
        products.emplace_back(temp);}

    std::vector<Product> getVectorProduct() {return products;}

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

void showPurchaseInvoice (std::vector <Purchase_Invoice> allPurchase_Invoices);

void addPurchase_Invoice(std::vector <Product> &allProducts, std::vector<Counterparty> allCounterparties, std::vector <Purchase_Invoice> &allPurchase_Invoices);

void savePurchase_InvoicesToFile(std::vector<Purchase_Invoice> purchase_Invoices);

int loadPurchase_InvoicesFromFile(std::vector<Purchase_Invoice> &purchase_Invoices, std::vector<Counterparty> allCounterparties);

void saveProductsFromPurchase_InvoicesToFile(std::vector<Purchase_Invoice> purchase_Invoices);

int loadProductsFromPurchase_InvoicesToFile(std::vector<Purchase_Invoice> &purchase_Invoices, std::vector<Product> &allProducts);



#endif // PURCHASE_INVOICE_H
