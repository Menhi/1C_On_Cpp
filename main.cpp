#include <Product.h>
#include <FunctionsSaveLoad.h>
#include <Purchase_Invoice.h>
#include <Sale_Invoice.h>
#include <General_Documents.h>
#include <Counterparties.h>
#include <windows.h>
#include <limits>




int main()
{
    SYSTEMTIME st;
    GetLocalTime(&st);

    std::vector<Product> allProducts;
    std::vector<Purchase_Invoice> allPurchase_Invoices;
    std::vector<Sale_Invoice> allSale_Invoices;
    std::vector<Counterparty> allCounterparties;

    loadProductsFromFile(allProducts);
    loadCounterpartiesFromFile(allCounterparties);
    loadPurchase_InvoicesFromFile(allPurchase_Invoices, allCounterparties);
    loadSale_InvoicesFromFile(allSale_Invoices, allCounterparties);

    int choice = -1;
    while (choice != 0){
        while (1){std::cout<<"What you want to do?\n"
                             "1 - add product\n"
                             "2 - show all products\n\n"
                             "3 - add doc Purchase Invoice\n"
                             "4 - show all doc Purchase Invoice\n\n"
                             "5 - add doc Sale Invoice\n"
                             "6 - show all doc Sale Invoice\n\n"
                             "7 - add counterparty\n"
                             "8 - show all counterparties\n\n"
                             "0 - save and exit\n";

            std::cin>>choice;
            std::cin.ignore();
            if (choice >= 0 && choice < 9)
                break;
            else {
                std::cout<<"Wrong choice. Try again\n\n";
            }
        }



        unsigned tempCounterpartyCode;
        unsigned tempAmountOfProducts;
        std::vector<Product> productsInDoc;

        switch (choice) {
        case 1:
            std::cout<<"Enter name of Product: ";
        {std::string tempName;
            std::getline(std::cin, tempName);
            allProducts.emplace_back(allProducts.back().getCode()+1, tempName, 0, 0);
            std::cout<<"\n\n";}
            break;


        case 2:
            for (unsigned i = 1; i < allProducts.size(); i++) std::cout<<allProducts[i].getCode()<<" "<<allProducts[i].getName()<< " " <<allProducts[i].getAmount()<< " " <<allProducts[i].getPrice()<<std::endl;
            std::cout<<"\n\n";
            break;


        case 3:
            do{
                std::cout<<"Choose and enter code of counterparty:\n";
                for (auto counterpatry : allCounterparties) counterpatry.showCounterparty();
                std::cin>>tempCounterpartyCode;
                if (tempCounterpartyCode <= 0 || tempCounterpartyCode >= allCounterparties.size()) std::cout<<"Wrong code. Try again\n\n";
            }while (tempCounterpartyCode <= 0 || tempCounterpartyCode >= allCounterparties.size());

            std::cout<<"How much products you want to buy?\n";
            do{
                std::cin>>tempAmountOfProducts;
                if (!std::cin >> tempAmountOfProducts){
                    std::cin.clear();
                    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout<<"Wrong value. Try again\n\n";
                }
            }while (!std::cin >> tempAmountOfProducts);

            allPurchase_Invoices.emplace_back(allPurchase_Invoices.back().getCode()+1, st.wDay, st.wMonth, st.wYear, allCounterparties[tempCounterpartyCode]);
            allPurchase_Invoices.back().setVectorProduct(tempAmountOfProducts, allProducts);
            std::cout<<"\n\n";
            break;


        case 4:
            for (unsigned i = 1; i < allPurchase_Invoices.size(); i++) allPurchase_Invoices[i].showDocument();
            std::cout<<"\n\n";
            break;


        case 5:
            std::cout<<"\n\n";
            break;


        case 6:
            for (unsigned i = 1; i < allSale_Invoices.size(); i++) allSale_Invoices[i].showDocument();
            std::cout<<"\n\n";
            break;


        case 7:
            std::cout<<"Enter name of Counterparty: ";
        {std::string tempName;
            std::getline(std::cin, tempName);
            allCounterparties.emplace_back(allCounterparties.back().getCode()+1, tempName, 0);
            std::cout<<"\n\n";}
            break;

        case 8:
            for (unsigned i = 1; i < allCounterparties.size(); i++) allCounterparties[i].showCounterparty();
            std::cout<<"\n\n";
            break;
        }
    }
    saveProductsToFile(allProducts);
    savePurchase_InvoicesToFile(allPurchase_Invoices);
    saveSale_InvoicesToFile(allSale_Invoices);
    saveCounterpartiesToFile(allCounterparties);
    return 0;
}
