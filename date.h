#pragma once
#include<memory>
#include<iostream>
#include<sstream>
using namespace std;




class Date{
    
public:
    Date(const string& s);
    const string event_date;
};

bool operator<(const Date& lhs, const Date& rhs);


bool operator<=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
Date ParseDate(istream& is);


ostream& operator<<(ostream& out, const Date& d);
