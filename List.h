#ifndef LIST_H
#define LIST_H
#include "node.h"


/**
 * @brief A list made up of a collection of nodes scattered around the memory which are linked together
 */
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


#endif