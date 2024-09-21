#include "node.h"
#include "List.h"
#include <iostream>


/**
 * @returns The number of items in list
 */
template <class T>
int LinkedList<T>::getLength() const { return length; }
/**
 * @brief Inserts an item onto the list.
 * @param itemToInsert The item that is to be inserted onto the list
 */
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
/**
 * @brief Delete an item on the list
 * @param itemToDelete The item that is to be deleted from the list
 */
template <class T>
void LinkedList<T>::deleteItem(T itemToDelete) {
    if (length == 0) {
        std::cout << "List is empty!" << std::endl;
    }
    else if (itemToDelete < first->info) {
        std::cout << "Item not found" << std::endl;
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
                std::cout << "Item not found" << std::endl;
            }
        }
    }
}
/**
 * @retval true If the list is empty
 * @retval false If the list is not empty
 */
template <class T>
bool LinkedList<T>::isEmpty() const { return length == 0; }
/**
 * @brief Displays the contents of the list
 */
template <class T>
void LinkedList<T>::printList() const {

    if (length == 0) {
        std::cout << "List is empty!" << std::endl;
    }
    else {
        node<T>* p = first;

        int i = 0;
        while (p != nullptr) {
            std::cout << "Item " << i + 1 << ": " << p->info << std::endl;
            p = p->next;
            i++;
        }
    }
}
/**
 * @brief Searches for an item that's in the list
 * @param itemToSearch The item that's being searched in the list
 * @retval true If the item is in the list
 * @retval false If the item isn't in the list
 */
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
/**
 * @brief Used in the copy constructor.
 * @param &other A reference to the object being copied from
 */
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
/**
 * @brief Used in the destructor.
 */
template <class T>
void LinkedList<T>::destroy() {
    node<T>* p = nullptr;

    while (p != nullptr) {
        p = first;
        first = first->next;
        delete p;
    }

    std::cout << "Deleting list..." << std::endl;
    length = 0;
}

/**
 * @brief Default constructor
 */
template <class T>
LinkedList<T>::LinkedList() : length(0), first(nullptr) {}
/**
 * @brief Destructor
 */
template <class T>
LinkedList<T>::~LinkedList() { destroy(); }
/**
 * @brief Copy constructor
 */
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & other) { copy(other) ;}
/**
 * @brief Operator overload of `=`. Can be used to copy lists.
 * @param &right The list being copied from
 * @returns An instance of LinkedList
 */
template <class T>
const LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & right) {
    if (this != &right) {
        destroy();
        copy(right);
    }

    return *this;
}