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

//Test insert function
void testInsert(DoublyLinkedList<int> &list)
{   
    cout << "List before inserts: " << list << endl;
    list.insert(5, 0); //use values to insert new elements into the list
    list.insert(4, 2);
    list.insert(8, list.length - 1);
    cout << "List after inserts: " << list << endl; //print new list to make sure inserts werer made correctly
    cout << "List length after inserts: " << list.length() << endl; //check that size was updated correctly
}

//Test accessing operator function
void testAccess(DoublyLinkedList<int> &list)
{
    cout << "Value at index 3: " << list[3] << endl; //check values
    cout << "First value in list: " << list[0];
    cout << "Last value in list: " << list[list.length() - 1];
    cout << "Stored values in list: " << list << endl; //check actual list to make sure outputs match
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

//Test the concatenation function
void testConcat(DoublyLinkedList<int> &list)
{
    DoublyLinkedList<int> list2, list3; //make new lists
    list2.append(40); //populate list2
    list2.append(50);
    list2.append(60);
    cout << "List before concat: " << list << endl; //check both lists
    cout << "Values in ist2: " << list2 << endl;
    list3 = list.concat(list2); //concatenate list and list2
    cout << "List3 created after concatenation: " << list << endl; //verify that list3 is the concatenation of list and list2
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
