#ifndef COUNTERPARTY_H
#define COUNTERPARTY_H


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

    void show() {
        std::cout<<getCode()<<"    "<<getName()<<" "<<getDiscount()<<"%\n";
    }



};

void addCounterparty (std::vector <Counterparty> &allCounterparties);

int showCounterparties (std::vector <Counterparty> allCounterparties);

void saveCounterpartiesToFile(std::vector<Counterparty>& counterparties);

int loadCounterpartiesFromFile(std::vector<Counterparty>& counterparties);


#endif // СOUNTERPARTIES_H
