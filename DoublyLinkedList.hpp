//=========================================================
// DoublyLinkedList.hh
// Trinity Meckel, Son Nguyen, Thomas
// September 20, 2024
// This is the header file for the DoublyLinkedList class
//=========================================================

#include <iostream>

using namespace std;

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

template <class T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T val;
        Node *next;
        Node *prev;
    };

    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList ( void );
    DoublyLinkedList ( const DoublyLinkedList<T> &aList );
    ~DoublyLinkedList ( void );
    void prepend ( const T &item );
    void append ( const T &item );
    void insert ( const T &item, int index );
    void remove ( int index );
    int search ( const T &item ) const;
    T & operator[] ( int index );
    int length ( void ) const;
    bool empty ( void ) const;
    DoublyLinkedList<T> concat ( const DoublyLinkedList<T> &list ) const;
    friend ostream & operator<< ( ostream &os, DoublyLinkedList<T> &list );
};

// #include "DoublyLinkedList.cpp"


#endif