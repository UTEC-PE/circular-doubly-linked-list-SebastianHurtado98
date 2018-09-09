//
// Created by sebastian on 8/28/18.
//

#ifndef DOUBLE_LINKED_LIST_DEVELOP_ITERATOR_H
#define DOUBLE_LINKED_LIST_DEVELOP_ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
private:
    Node<T>* current;

public:
    void print_prueba(){
        cout << current->data;
    }
    Iterator(){
        current= nullptr;
    };
    Iterator(Node<T>* node){
        current= node;
    };

    Iterator<T> operator=(Iterator<T> node){
        current= node.current; // Falta retornar el iterador, da warning
    };
    bool operator!=(Iterator<T> cmp){
        return current!=cmp.current;
    };
    Iterator<T> operator++(){
        current= current->next; // falta retornar el iterador, da warning
    };
    Iterator<T> operator--(){
        current= current->prev; // Fala retornar el iterador, da warning
    };
    T operator*(){
        return current->data;
    };
};
#endif //DOUBLE_LINKED_LIST_DEVELOP_ITERATOR_H
