#include<iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    length = 0;
}