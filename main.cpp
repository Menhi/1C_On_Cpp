#include <Product.h>
#include <FunctionsSaveLoad.h>
#include <Purchase_Invoice.h>
#include <Sale_Invoice.h>
#include <General_Documents.h>
#include <Сounterparties.h>




int main()
{
    int choice = -1;

    std::vector<Product> allProducts;
    std::vector<Purchase_Invoice> allPurchase_Invoices;
    std::vector<Sale_Invoice> allSale_Invoices;
    std::vector<Сounterparty> allCounterparties;

    loadProductsFromFile(allProducts);
    loadPurchase_InvoicesFromFile(allPurchase_Invoices);
    loadSale_InvoicesFromFile(allSale_Invoices);
    loadCounterpartiesFromFile(allCounterparties);

    while (choice != 0){
        while (1){std::cout<<"What you want to do?\n"
                             "1 - add product\n"
                             "2 - add doc Purchase Invoice\n"
                             "3 - add doc Sale Invoice\n"
                             "4 - show all products\n"
                             "5 - show all doc Purchase Invoice\n"
                             "6 - show all doc Sale Invoice\n"
                             "7 - add counterparty"
                             "0 - save and exit\n";

            std::cin>>choice;
            std::cin.ignore();
            if (choice > 0 && choice < 8)
                break;
            else {
                std::cout<<"Wrong choice. Try again\n\n";
            }
        }


        switch (choice) {
        case 1:
            std::cout<<"Enter name of Product: ";
        {std::string tempName;
            std::getline(std::cin, tempName);
            allProducts.emplace_back(allProducts.back().getCode()+1, tempName, 0, 0);
            saveProductsToFile(allProducts);
            std::cout<<"\n";}
            break;
        case 2:
            std::cout<<"2";
            break;
        case 3:
            std::cout<<"3";
            break;
        case 4:
            for (auto product : allProducts) std::cout<<product.getCode()<<" "<<product.getName()<< " " <<product.getAmount()<< " " <<product.getPrice()<<std::endl;
            std::cout<<"\n";
            break;
        case 5:
            for (auto purchase_Invoice : allPurchase_Invoices) std::cout<<purchase_Invoice.getCode()<<" "
                                                                       <<purchase_Invoice.getDay()<<"."
                                                                      <<purchase_Invoice.getMonth()<< "."
                                                                     <<purchase_Invoice.getYear()<<std::endl;
            std::cout<<"\n";
            break;
        case 6:
            for (auto sale_Invoice : allSale_Invoices) std::cout<<sale_Invoice.getCode()<<" "
                                                               <<sale_Invoice.getDay()<<"."
                                                              <<sale_Invoice.getMonth()<< "."
                                                             <<sale_Invoice.getYear()<<std::endl;
            std::cout<<"\n";
            break;
        case 7:
            std::cout<<"Enter name of Counterparty: ";
        {std::string tempName;
            std::getline(std::cin, tempName);
            allCounterparties.emplace_back(allCounterparties.back().getCode()+1, tempName, 0);
            saveCounterpartiesToFile(allCounterparties);
            std::cout<<"\n";}
            break;
        }
    }
    return 0;
}
