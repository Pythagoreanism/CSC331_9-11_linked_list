#include <iostream>
#include "node.h"
using namespace std;


template <class T>
class LinkedList {
private:
    node<T>* first;
    int length;

public:
    int getLength() const;
    void insertItem(T);
    void deleteItem(T);
    bool isEmpty() const;
    bool searchItem(T) const;
    void printList() const;
    void copy(const LinkedList<T> &);
    void destroy();
    
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor
    LinkedList(const LinkedList<T> &); // Copy constructor
    const LinkedList<T> & operator=(const LinkedList<T> &); // Operator-overload

};

template <class T>
int LinkedList<T>::getLength() const { return length; }
template <class T>
void LinkedList<T>::insertItem(T itemToInsert) {
    node<T>* p = new node<T>; // New node to hold item to insert
    p->info = itemToInsert;

    if (first == nullptr || itemToInsert < first->info) {
        p->next = first;
        first = p;
    }
    else {
        node<T>* q = nullptr; // Traversing pointer
        node<T>* r = nullptr; // Lagging temporary pointer
        q = first->next;
        r = first;

        while (q != nullptr && q->info < itemToInsert) {
            r = q;
            q = q->next; // Points to next node
        }

        p->next = q;
        r->next = p;
    }
    length++;
}
template <class T>
void LinkedList<T>::deleteItem(T itemToDelete) {
    if (length == 0) {
        cout << "List is empty!" << endl;
    }
    else if (itemToDelete < first->info) {
        cout << "Item not found" << endl;
    }
    else {
        node<T>* p = first;

        if (itemToDelete == first->info) { // If first node contains item
            first = first->next;
            delete p;
            length--;
        }
        else {
            node<T>* r = nullptr;

            while (p != nullptr && p->info < itemToDelete) { // Pointers traverse nodes
                r = p;
                p = p->next;
            }

            if (p->info == itemToDelete) { // "Rewiring" for deletion. Works with last node
                r->next = p->next;
                delete p;
                length--;
            }
            else {
                cout << "Item not found" << endl;
            }
        }
    }
}
template <class T>
bool LinkedList<T>::isEmpty() const { return length == 0; }
template <class T>
void LinkedList<T>::printList() const {

    if (length == 0) {
        cout << "List is empty!" << endl;
    }
    else {
        node<T>* p = first;

        int i = 0;
        while (p != nullptr) {
            cout << "Item " << i + 1 << ": " << p->info << endl;
            p = p->next;
            i++;
        }
    }
}
template <class T>
bool LinkedList<T>::searchItem(T itemToSearch) const {
    node<T>* p = first;

    while (p != nullptr) {
        if (p->info == itemToSearch) {
            return true;
        }
        else {
            p = p->next;
        }
    }

    return false;
}
template <class T>
void LinkedList<T>::copy(const LinkedList<T> & other) {
    length = other.length;

    if (other.first == nullptr) { // If original list is empty
        first = nullptr;
    }
    else {
        first = new node<T>;
        first->info = other.first->info;

        node<T>* p = other.first->next; // Points nodes of `other` object
        node<T>* r = first; // Points to nodes of current object

        while (p != nullptr) {
            r->next = new node<T>;
            r->next->info = p->info;
            p = p->next;
            r = r->next;
        }

        r->next = nullptr;        
    }
}
template <class T>
void LinkedList<T>::destroy() {
    node<T>* p = nullptr;

    while (p != nullptr) {
        p = first;
        first = first->next;
        delete p;
    }

    cout << "Deleting list..." << endl;
    length = 0;
}

template <class T>
LinkedList<T>::LinkedList() : length(0), first(nullptr) {}
template <class T>
LinkedList<T>::~LinkedList() { destroy(); }
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & other) { copy(other) ;}
template <class T>
const LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & right) {
    if (this != &right) {
        destroy();
        copy(right);
    }

    return *this;
}

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