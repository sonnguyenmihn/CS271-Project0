#include<iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(void) 
{
    head = NULL;
    tail = NULL;
    length = 0;
}

template <class T>
void DoublyLinkedList<T>::prepend(const &item)
{
    // Create new node
    Node *newNode = new Node;
    newNode->val = item;
    newNode->prev = NULL; // New node will be head, so no previous node
    newNode->next = head; // New node next is current head

    // Check if the list is empty
    if ( head == NULL )
    {
        tail = newNode; // if list is empty, both tail & head should point to new node
    }
    else:
    {
        head->prev = newNode; // Update prev head to new node
    }

    head = newNode; // New node becomes head of list
    length++; 
}



