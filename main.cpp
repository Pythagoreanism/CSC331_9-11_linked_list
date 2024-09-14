#include <iostream>
using namespace std;

template <class Type>
struct node {
    Type info;
    node<Type>* next;
};

template <class Type>
class LinkedList {
private:
    node<Type>* first;
    int length;

public:
    void insertItem(Type);
    void deleteItem(Type);
    int getLength() const;
    bool isEmpty() const;
    bool searchItem(Type);
    void printList() const;
    void copy(const LinkedList<Type> &);
    void destroy();
    void print() const;
    
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor
    LinkedList(const LinkedList<Type> &); // Copy constructor
    const LinkedList<Type> & operator=(const LinkedList<Type> &); // Operator-overload

};

template <class Type>
int LinkedList<Type>::getLength() const { return length; }
template <class Type>
LinkedList<Type>::LinkedList() : length(0), first(nullptr) {}

int main() {

    LinkedList<int> list;
    cout << "List length: " << list.getLength() << endl;

    return 0;
}