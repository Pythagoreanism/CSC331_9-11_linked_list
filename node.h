#ifndef NODE_H
#define NODE_H

template <class T>
struct node {
    T info;
    node<T>* next;
};

#endif