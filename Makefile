mytests: list mytests.o
	g++ -o mytests mytests.o doublylinkedlist
	./mytests

list: DoublyLinkedList.cpp DoublyLinkedList.hpp
	g++ DoublyLinkedList.cpp -c -o doublylinkedlist 

mytests.o: mytests.cpp
	g++ -o mytests.o mytests.cpp -c