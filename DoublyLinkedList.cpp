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
//=====================================================
// destructor
// removes an instance of the DoublyLinkedList class
// Parameters:
// None
// Return Value:
// None. the instance no longer exists
//=====================================================
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(void)
{
    //create pointers to track the head and tail
    Node *ptr = head;
    Node *qtr = tail;
    while (ptr !=NULL && qtr != NULL) //loop until ptr and qtr no longer point to anything
    {
        //move ptr forward and qtr back
        ptr = head->next;
        qtr = tail->prev;
        //delete the elements at head and tail, which ptr and qtr where just pointing to
        delete head;
        delete tail;
        //set the nodes pointed at by ptr and qtr as the new head and tail respectively
        head = ptr;
        tail = qtr;
    }
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
//================================================================
// insert
// This function inserts a new element into the list at
// a specified index
// Parameters:
// item: the element being added to the list
// index: the index at which a new element is being added
// Return Value:
// None. This function only serves to insert a new item into the list
//================================================================
template <class T>
void DoublyLinkedList<T>::insert(const T &item, int index)
{
    //Throw an out_of_range error if the index does not exist within the list
    if (index < 0 || index > length)
        throw out_of_range("That is outside of the list range.");
    
    if (index == 0)
        this.prepend(item); //if index is 0 put the item at the start of list
    else if (index == length)
        this.append(item); // if index is length of the list append item at the end

    else
    {
        //create a new node to be placed where an element is being inserted
        Node *ptr = new Node;
        //create node pointers to track the head and tail of the list
        Node *qtr = head;
        Node *ttr = tail;
        //loop up until one index before the chosen index
        for (int i = 0; i < index - 1; i++) 
            qtr = qtr->next;
        //Loop to move backwards through the list, starting from tail to reach the selected index
        for (int i = 0; i < length - index - 1; i++)
            ttr = ttr->prev;
        //ptr is placed after between the nodes pointed at by qtr and ttr
        //all items following ptr, including ttr, get pushed down, 
        //the new element is where ttr used to point folloing the loops
        ptr->prev = qtr;
        ptr->next = ttr;
        //store the new item as the value in the newly placed node
        ptr->val = item;

    }
    // adjust length to accomodate the new element
    length++
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
// accessing operator []
// overloads the accessing operator. Allows the
// accessing of indices in the doubly linked list to
// access stored values.
// Parameters:
// index: the index being accessed to retrieve a stored value
// Return Value:
// ptr->val: the value being stored at the index being accessed
//====================================================
template <class T>
T & DoublyLinkedList<T>::operator[] (int index)
{
    //Throw an out_of_range error if the index does not exist within the list
    if (index < 0 || index > length - 1)
        throw out_of_range("That is outside of the list range.");
    Node *ptr = head;
    for (int i = 0; i < index; i++) //loop to iterate through the list
        ptr = ptr->next;
    return ptr->val;
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

//=======================================================
// concat
// This function concatenates two doubly linked lists and
// produces a new list with the values stored within the others
// Parameters:
// list: one of the two lists being concatenated, specifically
// the one being placed second after the first list
// const: a constant calling object of the DoublyLinkedList class
// its elements are placed first within the new list
// Return Value:
// newList: A new list comprised of the combined elements from list
// and the calling object.
//=======================================================
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::concat(const DoublyLinkedList<T> &list) const
{
    DoublyLinkedList<T> newList;
    //Append the elements of the calling object into newList
    Node *ptr = head;
    while(ptr != NULL) //loop to iterate through the nodes of the calling object
    {
        newList.append(ptr->val);
        ptr = ptr->next;
    }
    //Append the elements of list into newList
    Node *qtr = list.head;
    while(qtr != NULL) //loop to iterate through the nodes in list
    {
        newList.append(qtr->val);
        qtr = qtr->next;
    }
    return newList;
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

            


            














