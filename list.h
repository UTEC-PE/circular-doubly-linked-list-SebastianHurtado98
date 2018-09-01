//
// Created by sebastian on 8/28/18.
//

#ifndef DOUBLE_LINKED_LIST_DEVELOP_LIST_H
#define DOUBLE_LINKED_LIST_DEVELOP_LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* start;
    int nodes;

public:
    List(){
        start= nullptr;
        nodes=0;
    };

    void print(){
        if(start== nullptr){
            cout << "NO HAY DATOS" << endl;
        }
        else {
            Iterator<int> it= begin();
            Iterator<int> it2= end();
            cout << *it << " ";

            while (it != it2) {
                ++it;
                cout << *it << " ";
            }
        }
    };

    T front(){
        if(start== nullptr){
            cout << "No hay datos";
        }
        else{
            return start->data;
        }
    };

    T back(){
        if(start== nullptr){
            cout << "No hay datos";
        }
        else{
            return start->prev->data;
        }
    };
    void push_front(T value){
        auto *n= new Node<T>();
        if(start==nullptr){
            n->data= value;
            n->next= n;
            n->prev= n;
            start=n;
        }
        else{
            n->data= value;
            n->next= start;
            n->prev= start->prev;
            start->prev->next=n;
            start->prev= n;
            start= n;
        }
        nodes++;
    };
    void push_back(T value){
        auto *n= new Node<T>();

        if(start==nullptr){
            n->data= value;
            n->next= n;
            n->prev= n;
            start=n;
        }
        else{
            n->data= value;
            n->next= start;
            n->prev= start->prev;
            start->prev->next=n;
            start->prev= n;
        }
        nodes++;
    };
    void pop_front(){

        if (start==nullptr){
            cout << "La lista esta vacia";
        }
        else{
            auto temp=start;
            start= start->next;
            start->prev= temp->prev;
            temp->next=start;
            delete temp;
            nodes--;
        }

    };

    void pop_back(){
        if (start==nullptr){
            cout << "La lista esta vacia";
        }
        else{
            auto temp= start->prev;
            start->prev= temp->prev;
            temp->prev->next= start;
            delete temp;
            nodes--;
        }

    };

    T get(int position){
        if(position>=nodes)
        {
            cout << "Posicion no existe";
        }
        else{
            Iterator<int> it= begin();
            for (int i=0; i<position; i++){
                ++it;
            }
            return *it;
        }
    };
    void concat(List<T> &other){

        if(!empty() && !other.empty()){
            auto t1       = start->prev ;
            auto h2= other.start;
            auto t2       = h2->prev;
            start->prev = t2 ;
            t1->next = h2 ;
            h2->prev = t1 ;
            t2->next = start ;

            other.start= start;
            nodes=nodes+other.nodes;
            other.nodes= nodes;

        }
        else{
            cout <<"Alguna de las dos listas no contiene elementos.";
        }
    };
    bool empty(){
        return start==nullptr;
    };
    int size(){
        return nodes;
    };
    void clear(){
        if (start== nullptr){
            cout << "Lista vacia";
        }
        else {
            auto n = start;
            Iterator<int> it= begin();
            Iterator<int> it2= end();

            while(it!=it2){
                ++it;
                n=n->next;
                start->next= nullptr;
                start->prev= nullptr;
                delete start;
                start= n;
            }
            start= nullptr;
            nodes = 0;
            cout <<"Se borro la lista";
        }
    };

    Iterator<T> begin(){
        Iterator<T> b(start);
        return b;
    };

    Iterator<T> end(){
        Iterator<T> ending(start->prev);
        return ending;
    };

    ~List(){
        clear();
    };
};
#endif //DOUBLE_LINKED_LIST_DEVELOP_LIST_H
