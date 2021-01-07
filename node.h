#pragma once
#include"date.h"


enum class LogicalOperation{
    And,
    Or
};
enum class Comparison{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

class Node{
    public:
    virtual bool Evaluate(const Date& d, const string& s) =0;
};

class EmptyNode: public Node{
    public:
    bool Evaluate(const Date& d, const string& s){
        return true;
    }
};

class DateComparisonNode: public Node{
private:
    Date datecomp;
    Comparison cmp;
public:
    DateComparisonNode(Comparison c, const Date& assigning);
    
     bool Evaluate(const Date& d, const string& s) override{
        //you shoud get comparison_operation from cmp. and compare datecomp with (const Date& d)
        if(cmp==Comparison::Less){
            return d<datecomp;
        }else if(cmp==Comparison::LessOrEqual){
            return d<=datecomp;
        }else if(cmp==Comparison::Greater){
            return d>datecomp;
        }else if(cmp==Comparison::GreaterOrEqual){
            return d>=datecomp;
        }else if(cmp==Comparison::NotEqual){
          return d!=datecomp; 
        }else if(cmp==Comparison::Equal){
            return d==datecomp;
        }
        exit(1);
}
};

class EventComparisonNode: public Node{
private:
    const string event_info;
    Comparison event_cmp;
public:
    EventComparisonNode(Comparison c, const string& w);
    
    bool Evaluate(const Date& d, const string& s) override{
        //you shoud get comparison_operation from cmp. and compare datecomp with (const Date& d)
       if(event_cmp==Comparison::Equal){
            return s==event_info;
        }else if(event_cmp==Comparison::NotEqual){
            return s!=event_info;
        }else if(event_cmp==Comparison::GreaterOrEqual){
            return s>=event_info;
        }else if(event_cmp==Comparison::Greater){
            return s>event_info;
        }else if(event_cmp==Comparison::Less){
            return s<event_info;
        }else if(event_cmp==Comparison::LessOrEqual){
            return s<=event_info;
        }
        exit(1);
}
};
class LogicalOperationNode: public Node{
    LogicalOperation e;
    shared_ptr<Node> pointer1;
    shared_ptr<Node> pointer2;
public:
    LogicalOperationNode(LogicalOperation l, shared_ptr<Node> o, shared_ptr<Node> t);
    
     bool Evaluate(const Date& d, const string& s){
         if(e==LogicalOperation::And){
        return pointer1->Evaluate(d, s) && pointer2->Evaluate(d, s);
       }
         else{
              return pointer1->Evaluate(d, s) || pointer2->Evaluate(d, s);
          }
    }
};
