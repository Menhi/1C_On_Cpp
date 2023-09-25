#include <Product.h>
#include <Product.cpp>

#include <Purchase_Invoice.h>
#include <Purchase_Invoice.cpp>

#include <Sale_Invoice.h>
#include <Sale_Invoice.cpp>

#include <General_Documents.h>

#include <Counterparty.h>
//Counterparty.cpp from Purchase_Invoice.cpp

#include <functions.cpp>
#include <limits>




int main()
{
    std::vector<Product> allProducts;
    std::vector<Purchase_Invoice> allPurchase_Invoices;
    std::vector<Sale_Invoice> allSale_Invoices;
    std::vector<Counterparty> allCounterparties;

    loadProductsFromFile(allProducts);
    loadCounterpartiesFromFile(allCounterparties);
    loadPurchase_InvoicesFromFile(allPurchase_Invoices, allCounterparties);
    loadSale_InvoicesFromFile(allSale_Invoices, allCounterparties);

    unsigned short choice;
    do{
        choice = defineChoice();
        switch (choice) {
        case 1:
            addProduct(allProducts);
            break;

        case 2:
            showProduct(allProducts);
            break;

        case 3:
            addPurchase_Invoice(allProducts, allCounterparties, allPurchase_Invoices);
            break;

        case 4:
            showPurchaseInvoice(allPurchase_Invoices);
            break;

        case 5:
            addSale_Invoice(allProducts, allCounterparties, allSale_Invoices);
            break;

        case 6:
            showSaleInvoice(allSale_Invoices);
            break;

        case 7:
            addCounterparty(allCounterparties);
            break;

        case 8:
            showCounterparties(allCounterparties);
            break;
        }
    }while (choice != 0);

    saveProductsToFile(allProducts);
    savePurchase_InvoicesToFile(allPurchase_Invoices);
    saveSale_InvoicesToFile(allSale_Invoices);
    saveCounterpartiesToFile(allCounterparties);
    return 0;
}
