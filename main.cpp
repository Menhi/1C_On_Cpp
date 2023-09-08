#include <Includes.h>





int main()
{
    int choice = 0;

    std::vector<Product> allProducts;
    std::vector<Purchase_Invoice> allPurchase_Invoices;
    std::vector<Sale_Invoice> allSale_Invoice;

    loadProductsFromFile(allProducts);
    loadPurchase_InvoicesFromFile(allPurchase_Invoices);
    loadSale_InvoicesFromFile(allSale_Invoice);

    do{
        do{
            std::cout<<"What you want to do?\n"
                       "1 - add product\n"
                       "2 - add doc Purchase Invoice\n"
                       "3 - add doc Sale Invoice\n"
                       "4 - show all products\n"
                       "5 - show all doc Purchase Invoice\n"
                       "6 - show all doc Sale Invoice\n"
                       "7 - save and exit\n";

            std::cin>>choice;
            std::cin.ignore();

        }while (choice < 1 || choice > 7);



        switch (choice) {
        case 1:
            std::cout<<"Enter name of Product: ";
        {
            std::string tempName;
            std::getline(std::cin, tempName);
            allProducts.emplace_back(allProducts.back().getCode()+1, tempName, 0, 0);
            saveProductsToFile(allProducts);
            std::cout<<"\n";
        }
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
            std::cout<<"5";
            break;
        case 6:
            std::cout<<"6";
            break;
        }
    }while (choice != 7);
    return 0;
}
