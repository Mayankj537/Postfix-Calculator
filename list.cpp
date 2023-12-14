#include<iostream>
#include "list.h"
using namespace std;
List::List(){
    sentinel_head=new Node(true);
    sentinel_tail=new Node(true);
    sentinel_head->next=sentinel_tail;
    sentinel_head->prev=nullptr;
    sentinel_tail->prev=sentinel_head;
    sentinel_tail->next=nullptr;
    size=0;
}
List::~List() {
    Node* current = sentinel_head->next;
    while (current != sentinel_tail) {
        Node* temp = current;
        current = current->next;
        temp->prev=nullptr;
        temp->next=nullptr;
        delete temp;
    }
    sentinel_head->next=nullptr;
    sentinel_tail->prev=nullptr;
    delete sentinel_tail;
    delete sentinel_head;
}

void List::insert(int v) {
    Node* n = new Node(v,sentinel_tail,sentinel_tail->prev);
    sentinel_tail->prev->next = n;
    // n->prev = sentinel_tail->prev;
    sentinel_tail->prev = n;
    // n->next = sentinel_tail;
    size+=1;
}

int List::delete_tail(){
    int temp=sentinel_tail->prev->get_value();
    Node* todelete=sentinel_tail->prev;
    todelete->prev->next=sentinel_tail;
    sentinel_tail->prev=todelete->prev;
    todelete->next=nullptr;
    todelete->prev=nullptr;
    delete(todelete);
    size-=1;
    return temp;
}
int List::get_size(){
    return size;
}
Node* List::get_head(){
    Node* ptr=sentinel_head;
    return ptr;
}
