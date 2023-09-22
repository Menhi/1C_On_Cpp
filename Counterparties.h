#ifndef COUNTERPARTIES_H
#define COUNTERPARTIES_H


#include <Includes.h>

class Counterparty{
    int code;
    std::string name;
    int discount_Percentage;
public:
    Counterparty(int Code, std::string Name, int discount) : code(Code), name(Name), discount_Percentage(discount){}

    int getCode() {return code;}
    std::string getName() {return name;}
    int getDiscount() {return discount_Percentage;}

    void showCounterparty() {
        std::cout<<getCode()<<" "<<getName()<<" "<<getDiscount()<<"%\n";
    }



};





#endif // СOUNTERPARTIES_H
