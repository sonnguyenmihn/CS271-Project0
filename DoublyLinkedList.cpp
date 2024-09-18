//====================================================
// DoublyLinkedList.cpp
// Trinity Meckel,  , 
// September 20, 2024
// Explain what this .cpp file does / program
//====================================================


#include<iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

//====================================================
// default constructor
// initializes an empty doubly linked list
// Parameters:
// none
// Return Value:
// None. Initializes head & tail to NULL, length to 0
//====================================================
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(void) 
{
    head = NULL;
    tail = NULL;
    length = 0;
}
//====================================================
// Prepend
// This function adds a new element to the front of the 
// list
// Parameters:
// item: the element to be added to the front of the list
// Return Value:
// None. Element is inserted to become new head of list.
// If list is empty, both head and tail are updated to
// point to the new node. 
//====================================================
template <class T>
void DoublyLinkedList<T>::prepend(const T &item)
{
    // create new node
    Node *newNode = new Node;
    newNode->val = item;
    newNode->prev = NULL; // new node will be head, so no previous node
    newNode->next = head; // new node next is current head

    // check if the list is empty
    if ( head == NULL )
    {
        tail = newNode; // if list is empty, both tail & head should point to new node
    }
    else:
    {
        head->prev = newNode; // update prev head to new node
    }

    head = newNode; // new node becomes head of list
    length++; 
}

//====================================================
// Remove
// This function removes an item at a specfic position
// indicated by the index
// Parameters:
// index: the position of the element to remove 
// Return Value:
// None. Element at the specfic index is removed.
// If index is out of range, the functions throws
// and out_of_range exception
//====================================================
template <class T> 
void DoublyLinkedList<T>::remove(int index)
{
    // check if the index is out of range
    if (index < 0 || index >= length)
    {
        throw out_of_range( "Index is out of range");
    }

    // special Case: removing the head
    if (index == 0)
    {
        Node *nodeToRemove = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL; // list is now empty
        }

        delete nodeToRemove;
    }

    // special case: removing the tail
    else if (index == length - 1)
    {    
        Node *nodeToRemove = tail;
        tail = tail->prev;

        if (tail != NULL)
        {
            tail->next = NULL;
        }
        else
        {
            head = NULL; // list is now empty
        }
    }

    // removing from the middle
    else
    {
        Node *current = head;
        for (int i = 0 ; i < index : i++)
        {
            current = current->next;
        }

        current->prev->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }

        delete current;
    }

    --length; // decrement from the length of list
}

//====================================================
// Length
// This function returns the number of elements in the list
// Parameters:
// none
// Return Value:
// returns an integer that reperesents the current
// number of elements in the list
//====================================================
template <class T>
int DoublyLinkedList<T>::length(void) const
{
    return length;
}

//====================================================
// Friend 
// This function overloads the << operator to print
// the contents of a DoublyLinkedList object
// Parameters:
// os: an ostream object (such as cout) to which the 
//     list will be printed
// list: a reference to the DoublyLinkedList object 
//       that we want to print
// Return Value:
// returns the ostream object (os) with the contents of
// the list printed, where each element is separated by
// a single space. No trailing space is printed after the
// last element.
//====================================================
template <class T>
ostream &operator<<(ostream &os, const DoublyLinkedList<T> &list)
{
    typename DoublyLinkedList<T>::Node *current = list.head; // start from head of the list

    // go through list and print each item
    while (current != NULL)
    {
        os << current->val; // print the value of the current node

        if (current->next != NULL)
        {
            os << ' '; // print a space if there is another item following
        }

        current = current->next; // move to the new node
    }

    return os;
}

            


            














