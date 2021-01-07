#include "node.h"

 
    
 DateComparisonNode::DateComparisonNode(Comparison c, const Date& assigning): datecomp(assigning), cmp(c){}
 


EventComparisonNode::EventComparisonNode(Comparison c, const string& w): event_info(w), event_cmp(c) {}



LogicalOperationNode::LogicalOperationNode(LogicalOperation l, shared_ptr<Node> o, shared_ptr<Node> t)
                                                :e(l), pointer1(o), pointer2(t) {}





















