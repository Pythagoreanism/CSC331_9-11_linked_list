#include <iostream>
using namespace std;

template <class Type>
struct node {
    Type info;
    node<Type>* next;
};


int main() {

    cout << "Hello world" << endl;

    return 0;
}