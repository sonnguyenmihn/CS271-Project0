//====================================================
// mytests.cpp
// Trinity Meckel, Son Nguyen, Thomas
// September 20, 2024
// This is the test file for DoublyLinkedList class
//====================================================

#include<iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

void test_copy_constructor();
void test_append();

int main() 
{
    // // create an empty doubly linked
    // DoublyLinkedList<int> list;

    // // test default constructor
    // cout << "Initial list length: " << list.length() << endl;

    // // test prepend function
    // cout << "Prepending values to the list.." << endl;
    // list.prepend(10);
    // list.prepend(20);
    // list.prepend(30);

    // // test length function
    // cout << "List length after prepends: " << list.length() << endl;

    // // test overloaded << operator
    // cout << "Cureent list: " << list << endl;

    // // test remove function
    // try 
    // {
    //     cout << "Removing element at index 1 ..." << endl;
    //     list.remove(1);
    //     cout << "List after removal: " << list << endl;
    //     cout << "List length after removal: " << list.length() << endl;

    //     // try remove head & tail
    //     cout << "Removing head ( index 0 ) ..." << endl;
    //     list.remove(0);
    //     cout << "List after removing head: " << list << endl;

    //     cout << "Removing tail (last element) ..." << endl;
    //     list.remove(list.length() - 1);   // remove last element
    //     cout << "List after removing tail: " << list << endl;

    //     // try out-of-range removal
    //     cout <<  "Try out-of-range removal (index 5)..." << endl;
    //     list.remove(5);
    // }

    // catch (const out_of_range &e)
    // {
    //     cout << "Exception caught: " << e.what() << endl;
    // }
    test_copy_constructor();
    test_append();
    return 0;
}

//====================================================
// Test the copy constructor of the DoublyLinkedList class
// This function creates a list, adds a few items, and then
// creates a copy using the copy constructor. It compares
// the original and copied lists to ensure they have the same
// elements but are different objects.
// Parameters:
//  none
// Returns:
//  none
//====================================================
void test_copy_constructor() {    
    cout << "Testing copy constructor" << endl;

    // create a instance of doubly linked list class
    DoublyLinkedList<int> list1;
    for (int i = 0; i < 5; i++) {
        list1.append(i);
    }    
    // Copying list1 to list2
    DoublyLinkedList<int> list2(list1);
    
    // Check if the two lists have the same elements
    for (int i = 0; i < 5; i++) {
        cout << "Original list[" << i << "] = " << list1[i] << " , Copied list[" << i << "] = " << list2[i] << endl;
    }

    // Modify list1 and test that list2 does not change
    list1.append(40);
    cout << "After modifying the original list:" << endl;
    cout << "Original list length: " << list1.length() << ", Copied list length: " << list2.length() << endl;
}

void test_append() {
    cout << "Testing append" << endl;
    
    DoublyLinkedList<int> list;
    
    // Edge case: append to an empty list
    list.append(5);
    cout << "List after appending 5: " << list[0] << endl;
    
    // Appending more elements
    list.append(10);
    list.append(15);
    list.append(20);
    
    for (int i = 0; i < list.length(); i++) {
        cout << "list[" << i << "] = " << list[i] << endl;
    }
}