#include"database.h"


void Database::Add(const Date& d, const string& s){
     /*auto it=object.lower_bound(d);
    if(it==object.end()){
        object.insert({d, s});
    }else if(it->second!=s){
         object.insert({d, s});
    }*/
      if(checker_set.insert({d,s}).second){
        object.insert({d, s});
    }
}

void Database::Print(ostream& out) const{
    for(const auto& i: object){
        out<<i.first<<" "<<i.second<<endl;
    }
}



pair<Date, string> Database::Last(const Date& last_date) const{
    auto it_up= object.upper_bound(last_date);
    if(it_up==object.begin()){
        throw invalid_argument("invalid");
    }
         auto it = --object.upper_bound(last_date);
        pair<Date, string> ret = *it;
        return ret;
    
}
ostream& operator<<(ostream& out, const pair<Date, string>& p){
    out<<p.first<<" "<<p.second;
    return out;
}
