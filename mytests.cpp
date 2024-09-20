#include<iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

int main() 
{
    // create an empty doubly linked
    DoublyLinkedList<int> list;

    // test default constructor
    cout << "Initial list length: " << list.length() << endl;

    // test prepend function
    cout << "Prepending values to the list.." << endl;
    list.prepend(10);
    list.prepend(20);
    list.prepend(30);

    // test length function
    cout << "List length after prepends: " << list.length() << endl;

    // test overloaded << operator
    cout << "Cureent list: " << list << endl;

    // test remove function
    try 
    {
        cout << "Removing element at index 1 ..." << endl;
        list.remove(1);
        cout << "List after removal: " << list << endl;
        cout << "List length after removal: " << list.length() << endl;

        // try remove head & tail
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

    catch (const out_of_range &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    //create a list to test the copy constructor
    DoublyLinkedList<int> list1;
    list1.append(10);
    list1.append(20);
    list1.append(30);

    // Use copy constructor to create list2
    DoublyLinkedList<int> list2 = list1;

    // Print both lists to check if they are the same
    cout << "Test Copy Constructor:" << endl;
    cout << "List 1: ";
    for (int i = 0; i < list1.length(); i++) {
        cout << list1[i] << " ";
    }
    cout << endl;

    cout << "List 2 (Copied): ";
    for (int i = 0; i < list2.length(); i++) {
        cout << list2[i] << " ";
    }
    cout << endl;

    // Modify list2 and check that list1 remains unchanged
    list2.append(40);
    cout << "List 2 (After append 40): ";
    for (int i = 0; i < list2.length(); i++) {
        cout << list2[i] << " ";
    }
    cout << endl;

    cout << "List 1 (After modifying List 2): ";
    for (int i = 0; i < list1.length(); i++) {
        cout << list1[i] << " ";
    }
    cout << endl;
    
    return 0;
}
