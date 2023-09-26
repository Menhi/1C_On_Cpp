#include <Product.h>

#include <Purchase_Invoice.h>

#include <Sale_Invoice.h>

#include <General_Documents.h>

#include <Counterparty.h>

#include <functions.cpp>




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
            system("cls");
            addProduct(allProducts);
            break;

        case 2:
            system("cls");
            showProduct(allProducts);
            break;

        case 3:
            system("cls");
            addPurchase_Invoice(allProducts, allCounterparties, allPurchase_Invoices);
            break;

        case 4:
            system("cls");
            showPurchaseInvoice(allPurchase_Invoices);
            break;

        case 5:
            system("cls");
            addSale_Invoice(allProducts, allCounterparties, allSale_Invoices);
            break;

        case 6:
            system("cls");
            showSaleInvoice(allSale_Invoices);
            break;

        case 7:
            system("cls");
            addCounterparty(allCounterparties);
            break;

        case 8:
            system("cls");
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
