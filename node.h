//
// Created by sebastian on 8/28/18.
//

#ifndef DOUBLE_LINKED_LIST_DEVELOP_NODE_H
#define DOUBLE_LINKED_LIST_DEVELOP_NODE_H



#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    void killSelf(){

    };
    void print_next(){
    };
};

#endif //DOUBLE_LINKED_LIST_DEVELOP_NODE_H
