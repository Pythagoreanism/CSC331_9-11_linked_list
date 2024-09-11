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
    void copy(const List<Type> &);
    void destroy();
    void print() const;
    
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<Type> &);
    const LinkedList<Type> & operator=(const LinkedList<Type> &);

};


int main() {

    cout << "Hello world" << endl;

    return 0;
}