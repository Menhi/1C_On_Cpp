#ifndef GENERAL_DOCUMENTS_H
#define GENERAL_DOCUMENTS_H


#include <Includes.h>
#include <Counterparty.h>

class Document{
    int code;
    int day;
    int month;
    int year;
public:
    Document(int Code, int Day, int Month, int Year) : code(Code), day(Day), month(Month), year(Year){};

    void setDay(int Day){day = Day;}
    void setMonth(int Month){month = Month;}
    void setYear(int Year){year = Year;}

    int getCode(){return code;}
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}

};


class DocumentWithCounterparty : public Document{
    Counterparty counterparty;
public:

    DocumentWithCounterparty(int Code, int Day, int Month, int Year, Counterparty Counterparty) : Document(Code, Day, Month, Year), counterparty(Counterparty){}

    int getCounterpartyCode() {return counterparty.getCode();}

    std::string getCounterpartyName() {return counterparty.getName();}
};


#endif // GENERAL_DOCUMENTS_H
