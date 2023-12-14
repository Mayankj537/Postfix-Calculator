#include<iostream>
#include "stack_c.h"
#include<stdexcept>
using namespace std;
Stack_C::Stack_C(){
    stk=new List();
}
Stack_C::~Stack_C(){
    delete(stk);
}
void Stack_C::push(int data){
    stk->insert(data);
}
int Stack_C::get_element_from_top(int idx){
    int c=stk->get_size();
    return get_element_from_bottom(c-idx-1);
}
int Stack_C::get_element_from_bottom(int idx) {
    Node* temp = stk->get_head()->next; // Skipping the sentinel node
    int c = 0;
    while (c < idx && temp != nullptr) {
        temp = temp->next;
        c++;
    }
    return temp->get_value();
}

void Stack_C::print_stack(bool top_or_bottom){
    if(top_or_bottom==false){
        Node* temp=stk->get_head();
        int c=0;
        int n=stk->get_size();
        while(c!=n){
            cout<<temp->next->get_value()<<endl;
        }
    }
    else{
        Node* temp=stk->get_head();
        int c=0;
        int n=stk->get_size();
        while(c!=n){
            cout<<get_element_from_top(c);
            c++;
        }
    }

}
int Stack_C::add(){
    if(stk->get_size()>=2){
        int a=get_element_from_top(0);
        int b=get_element_from_top(1);
        int res=a+b;
        stk->delete_tail();
        stk->delete_tail();
        stk->insert(res);
        return res;
    }
    else{
        throw std::runtime_error("Not enough arguments");
    }
}
int Stack_C::subtract(){
    if(stk->get_size()>=2){
        int a=get_element_from_top(0);
        int b=get_element_from_top(1);
        int res=b-a;
        stk->delete_tail();
        stk->delete_tail();
        stk->insert(res);
        return res;
    }
    else{
        throw std::runtime_error("Not enough arguments");
    }
}
int Stack_C::multiply(){
    if(stk->get_size()>=2){
        int a=get_element_from_top(0);
        int b=get_element_from_top(1);
        int res=a*b;
        stk->delete_tail();
        stk->delete_tail();
        stk->insert(res);
        return res;
    }
    else{
        throw std::runtime_error("Not enough arguments");
    }
}
int Stack_C::divide(){
    if(stk->get_size()>=2){
        int a=get_element_from_top(0);
        int b=get_element_from_top(1);
        if(a*b>0){
            int res=b/a;
            stk->delete_tail();
            stk->delete_tail();
            stk->insert(res);
            return res;
        }
        else{
            int res=b/a-1;
            stk->delete_tail();
            stk->delete_tail();
            stk->insert(res);
            return res;
        }
    }
    else if(get_element_from_top(0)==0){
        throw std::runtime_error("Divide by Zero Error");
    }
    else{
         throw std::runtime_error("Not enough arguments");
    }
}
List* Stack_C::get_stack(){
    return stk;
}
int Stack_C::get_size(){
    return stk->get_size();
}
int Stack_C::pop(){
    if(stk->get_size()==0){
        throw std::runtime_error("Empty Stack");
    }
    else{
        int c=get_element_from_bottom(stk->get_size()-1);
        stk->delete_tail();
        return c;
    }
}
