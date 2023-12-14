#include<iostream>
#include "stack_b.h"
#include<stdexcept>
using namespace std;
Stack_B::Stack_B(){
    size=0;
    capacity=3;
    try {
            stk = new int[capacity];
        } catch (const runtime_error& e) {
            cerr << "Out of Memory: " << e.what() << endl;
}
}
Stack_B::~Stack_B(){
    delete []stk;
}
void Stack_B::push(int data){
    if(size<capacity){
        stk[size]=data;
        size+=1;
    }
    else{
        try{
            capacity=capacity*2;
            int* temp= new int[capacity];
            for(int i=0;i<size;i++){
                temp[i]=stk[i];
            }
            stk=temp;
            stk[size]=data;
            size+=1;
    }catch (const runtime_error& e) {
        cerr << "Out of Memory: " << e.what()<<endl;
    }
}
}
int Stack_B::get_size(){
    return size;
}; 

int Stack_B::pop(){
    if(size==0){
        throw std::runtime_error("Empty Stack");
    }
    else if(size==capacity/4){
        capacity=capacity/4;
        int* temp= new int[capacity];
        for(int i=0;i<size;i++){
            temp[i]=stk[i];
        }
        stk=temp;
        size=size-1; 
        return stk[size]; 

    }
    else{
        size=size-1;
        return stk[size];
    }
}
void Stack_B::print_stack(bool top_or_bottom){
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
int Stack_B::add(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else{
        int num1=pop();
        int num2=pop();
        int res=num1+num2;
        push(res);
        return res;
    }
}
int Stack_B::subtract(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else{
        int num1=pop();
        int num2=pop();
        int res=num2-num1;
        push(res);
        return res;
    }
}
int Stack_B::multiply(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else{
      int num1=pop();
        int num2=pop();
        int res=num1*num2;
        push(res);
        return res;
    }
}
int Stack_B::divide(){
    if(size<2){
        throw std::runtime_error("Not enough arguments");
    }
    else if(stk[size-1]==0){
        throw std::runtime_error("Divide by Zero Error");
    }
    else{
        int num1=pop();
        int num2=pop();
        if(num1*num2<0){
            int res=num2/num1-1;
            push(res);
            return res;
        }
        else{
            int res=num2/num1;
            push(res);
            return res;
        }
    }
   
}
int* Stack_B::get_stack() {
    int *ptr=stk;
    return ptr;
}
int Stack_B::get_element_from_bottom(int idx){
    if(idx>size-1){
        throw std::runtime_error("Index out of range");
    }
    else{
        return stk[idx];
    }
}
int Stack_B::get_element_from_top(int idx){
      if(idx>size-1){
        throw std::runtime_error("Index out of range");
    }
    else{
        return stk[size-1-idx];
    }
}
