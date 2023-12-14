#include<iostream>
#include<stdexcept>
#include "stack_a.h"
using namespace std;

Stack_A::Stack_A(){
    size=0;
}
int Stack_A::get_size(){
    return size;
}; 
void Stack_A::push(int data){
    if(size<=1024){
        stk[size]=data;
        size+=1;
    }
    else{
    std::runtime_error("Stack Full");
    }
}
int Stack_A::pop(){
    if(size==0){
        throw std::runtime_error("Empty Stack");
    }
    size=size-1;
    return stk[size];
    
}
void Stack_A::print_stack(bool top_or_bottom){
    if(top_or_bottom==true){
        for(int i=size-1;i>=0;i--){
            cout<<stk[i]<<endl;
        }
    }
    else{
        for(int i=0;i<size;i++){
            cout<<stk[i]<<endl;
        }
    }
    }
int Stack_A::add(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else{
        int num1=stk[size-1];
        int num2=stk[size-2];
        int res=num1+num2;
        size=size-2;
        stk[size]=res;
        size+=1;
        return res;
    }
}
int Stack_A::subtract(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else{
        int num1=stk[size-1];
        int num2=stk[size-2];
        int res=num2-num1;
        size=size-2;
        stk[size]=res;
        size+=1;
        return res;
    }
}
int Stack_A::multiply(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else{
        int num1=stk[size-1];
        int num2=stk[size-2];
        int res=num1*num2;
        size=size-2;
        stk[size]=res;
        size+=1;
        return res;
    }
}
int Stack_A::divide(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else if(stk[size-1]==0){
        throw std::runtime_error("Divide by Zero Error");
    }
    else{
        int num1=stk[size-1];
        int num2=stk[size-2];
        if(num1*num2<0){
            int res=num2/num1-1;
            size=size-2;
            stk[size]=res;
            size+=1;
            return res;
        }
        else{
            int res=num2/num1;
            size=size-2;
            stk[size]=res;
            size+=1;
            return res;
        }
    }
   
}
int* Stack_A::get_stack() {
    int *ptr=stk;
    return ptr;
}
int Stack_A::get_element_from_top(int idx){
    return stk[size-idx-1];
}
int Stack_A::get_element_from_bottom(int idx){
    return stk[idx];
}

