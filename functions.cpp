#include <Includes.h>


int defineChoice (){
    int choice = -1;
    while (1){
        std::cout<<"What you want to do?\n"
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
        if (choice >= 0 && choice <= 8)
            break;
        else {
            system("cls");
            std::cout<<"Wrong choice. Try again\n\n";
        }
    }
    return choice;
}

