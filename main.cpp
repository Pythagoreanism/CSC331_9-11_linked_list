#include <iostream>
#include "node.h"
#include "List.cpp" // Compiler struggles with template classes
using namespace std;


int main() {
    LinkedList<int> list;

    list.printList();
    cout << "List length: " << list.getLength() << endl;
    list.insertItem(5);
    cout << "List length: " << list.getLength() << endl;
    list.printList();

    list.insertItem(1);
    list.printList();
    list.insertItem(6);
    list.printList();

    list.deleteItem(0);
    list.deleteItem(1);
    list.deleteItem(6);

    LinkedList<int> list2;
    cout << "Empty: " << list2.isEmpty() << endl;
    list2.insertItem(4);
    cout << "Empty: " << list2.isEmpty() << endl;

    list2.insertItem(1);
    list2.insertItem(15);
    cout << "Search: " << list2.searchItem(0) << endl;
    cout << "Search: " << list2.searchItem(100) << endl;
    cout << "Search: " << list2.searchItem(1) << endl;
    cout << "Search: " << list2.searchItem(15) << endl;

    LinkedList<int> list3(list2);
    cout << "List copied from:" << endl;
    list2.printList();
    cout << "Copied list:" << endl;
    list3.printList();

    return 0;
}