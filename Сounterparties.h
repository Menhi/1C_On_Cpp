#ifndef СOUNTERPARTIES_H
#define СOUNTERPARTIES_H


#include <Includes.h>

class Сounterparty{
    int code;
    std::string name;
    int discount_Percentage;
public:
    Сounterparty(int Code, std::string Name, int discount) : code(Code), name(Name), discount_Percentage(discount){}

    int getCode() {return code;}
    std::string getName() {return name;}
    int getDiscount() {return discount_Percentage;}
};




#endif // СOUNTERPARTIES_H
