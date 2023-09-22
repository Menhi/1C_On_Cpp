#ifndef GENERAL_DOCUMENTS_H
#define GENERAL_DOCUMENTS_H


#include <Includes.h>

class Document{
    int code;
    int day;
    int month;
    int year;
public:
    Document(int Code, int Day, int Month, int Year) : code(Code), day(Day), month(Month), year(Year){};
    //void setCode(int Code){code = Code;}
    void setDay(int Day){day = Day;}
    void setMonth(int Month){month = Month;}
    void setYear(int Year){year = Year;}

    virtual int getCode(){return code;}
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}

};



#endif // GENERAL_DOCUMENTS_H
