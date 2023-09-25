#include <Includes.h>
#include <Product.h>

void addProduct (std::vector <Product> &allProducts){
    system("cls");
    std::cout<<"Enter name of Product: ";
    std::string tempName;
    std::cin>>tempName;
    std::cin.ignore();
    allProducts.emplace_back(allProducts.back().getCode()+1, tempName, 0, 0.f);
    system("cls");
    std::cout<<"Product saved.\n\n";
}

void showProduct (std::vector <Product> &allProducts){
    system("cls");
    std::cout<<"Code Name Amount Price\n";
    for (auto product : allProducts){
        if (product.getCode() != 0)
            product.show();
    }
    std::cout<<"\n\n";
}




