#include<iostream>
#include "node.h"
using namespace std;
Node::Node(int v, Node* nxt, Node* prv){
    value=v;
    next=nxt;
    prev=prv;
    is_sentinel=false;
}
Node::Node(bool sentinel){
    is_sentinel=true;
}
bool Node::is_sentinel_node(){
    return is_sentinel;
}
int Node::get_value(){
    return value;
}
