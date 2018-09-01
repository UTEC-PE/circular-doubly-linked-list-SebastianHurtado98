#include <iostream>
#include "list.h"

using namespace std;

int main() {

    List<int> list1;
    list1.front();
    list1.push_front(1);
    list1.push_front(2);
    cout << list1.empty() << endl;
    list1.push_front(3);
    list1.push_front(4);
    list1.push_back(5);
    list1.print();
    List<int> list2;
    list2.push_front(10);
    list2.push_front(10);
    list2.push_front(10);
    list2.print();
    cout << endl;
    list1.concat(list2);
    list1.print();
    cout << endl;
    list2.print();
    Iterator<int> it(list1.begin());
    cout << endl;
    it.print_prueba();
    ++it;
    cout << endl<< *it;
    cout << endl;
    --it; cout << endl << *it;
    Iterator<int> it2(list1.end()); cout << endl;
    cout << *it2 << endl;
    list1.clear();
    list1.print();

    return 0;
}