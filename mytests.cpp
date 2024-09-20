#include<iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

// function to test the constructor and initial list
void testConstructor(DoublyLinkedList<int>& list) 
{
    cout << "Initial list length: " << list.length() << endl;
}

// function to test the prepend function
void testPrepend(DoublyLinkedList<int>& list) 
{
    cout << "Prepending values to the list.." << endl;
    list.prepend(10);
    list.prepend(20);
    list.prepend(30);
    cout << "List length after prepends: " << list.length() << endl;
}

// function to test the << operator
void testPrintList(const DoublyLinkedList<int>& list) 
{
    cout << "Current list: " << list << endl;
}

// function to test the remove function and handle exceptions
void testRemove(DoublyLinkedList<int>& list) 
{
    try 
    {
        cout << "Removing element at index 1 ..." << endl;
        list.remove(1);
        cout << "List after removal: " << list << endl;
        cout << "List length after removal: " << list.length() << endl;

        // remove head and tail
        cout << "Removing head ( index 0 ) ..." << endl;
        list.remove(0);
        cout << "List after removing head: " << list << endl;

        cout << "Removing tail (last element) ..." << endl;
        list.remove(list.length() - 1);   // remove last element
        cout << "List after removing tail: " << list << endl;

        // try out-of-range removal
        cout <<  "Try out-of-range removal (index 5)..." << endl;
        list.remove(5);
    }
    catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}


int main() 
{
    // create an empty doubly linked list
    DoublyLinkedList<int> list;

    // test the functions
    testConstructor(list);
    testPrepend(list);
    testPrintList(list);
    testRemove(list);

    return 0;  
}
