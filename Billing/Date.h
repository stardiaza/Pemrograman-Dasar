#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {}
    
    string toString() const {
        string dd = (day < 10 ? "0" : "") + to_string(day);
        string mm = (month < 10 ? "0" : "") + to_string(month);
        return dd + "-" + mm + "-" + to_string(year);
    }
};

#endif