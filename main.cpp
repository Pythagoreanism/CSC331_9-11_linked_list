#include <iostream>
using namespace std;

template <class T>
struct node {
    T info;
    node<T>* next;
};

template <class T>
class LinkedList {
private:
    node<T>* first;
    int length;

public:
    void insertItem(T);
    void deleteItem(T);
    int getLength() const;
    bool isEmpty() const;
    bool searchItem(T);
    void printList() const;
    void copy(const LinkedList<T> &);
    void destroy();
    void print() const;
    
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor
    LinkedList(const LinkedList<T> &); // Copy constructor
    const LinkedList<T> & operator=(const LinkedList<T> &); // Operator-overload

};

template <class T>
int LinkedList<T>::getLength() const { return length; }
template <class T>
LinkedList<T>::LinkedList() : length(0), first(nullptr) {}

int main() {

    LinkedList<int> list;
    cout << "List length: " << list.getLength() << endl;

    return 0;
}