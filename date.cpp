
#include "date.h"


Date::Date(const string& s): event_date(s){}

bool operator<(const Date& lhs, const Date& rhs){
    return lhs.event_date<rhs.event_date;
}

bool operator==(const Date& lhs, const Date& rhs){
    return lhs.event_date==rhs.event_date;
}
bool operator<=(const Date& lhs, const Date& rhs){
    return lhs.event_date<=rhs.event_date;
}

bool operator>(const Date& lhs, const Date& rhs){
    return lhs.event_date>rhs.event_date;
}

bool operator>=(const Date& lhs, const Date& rhs){
    return lhs.event_date>=rhs.event_date;
}
bool operator!=(const Date& lhs, const Date& rhs){
    return lhs.event_date!=rhs.event_date;
}


ostream& operator<<(ostream& out, const Date& d){
    return out<<d.event_date;
}
Date ParseDate(istream& is){
    string s;
    is>>s;
    string part1;
    string part2;
    string part3;
    int i=0;
    while(s[i]!='-'){
        part1+=s[i];
        i++;
    }
    size_t q=part1.size();
    part1.insert(part1.begin(), 4-q, '0');
    i++;
     while(s[i]!='-'){
        part2+=s[i];
        i++;
    }
    size_t e= part2.size();
    part2.insert(part2.begin(), 2-e, '0');
    i++;
    while(s[i]!='\0'){
        part3+=s[i];
        i++;
    }
    size_t z= part3.size();
    part3.insert(part3.begin(), 2-z, '0');
    Date d(part1+'-'+part2+'-'+part3); 
    return d;
}
