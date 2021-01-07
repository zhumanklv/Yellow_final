#pragma once
#include<memory>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<stdexcept>
#include"date.h"

using namespace std;

class Database{
    multimap<Date, string> object;
    set<pair<Date, string>> checker_set;
public:
    void Add(const Date& d, const string& s);
    
    void Print(ostream& out) const;
    
    template<class TestFunc>
    int RemoveIf(TestFunc func){
            int counter =0;
        vector<pair<Date, string>> temp_vector;
    for(auto it=object.begin();it!=object.end();){
        bool b=func(it->first, it->second);
        if(b){
           temp_vector.push_back({it->first, it->second});
           it=object.erase(it);
           counter++;
        }else{
            it++;
        }
    }
    for(const auto& i: temp_vector){
        checker_set.erase(i);
    }
    return counter;
    }
    
    pair<Date, string> Last(const Date& last_date) const;
    
    template<class TestFunc>
    multimap<Date, string> FindIf(TestFunc func) const{
        
        multimap<Date, string> findif_map;
        for(auto it=object.begin();it!=object.end();it++){
            if(func(it->first, it->second)){
                findif_map.insert({it->first, it->second}); 
            }
        }
        
        return findif_map;
    }
    
    friend ostream& operator<<(ostream& out, const pair<Date, string>& p);
};

 ostream& operator<<(ostream& out, const pair<Date, string>& p);
