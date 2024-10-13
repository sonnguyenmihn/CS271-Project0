mytests: mytests.o
	g++ -o mytests mytests.o
	./mytests

mytests.o: list mytests.cpp
	g++ -o mytests.o mytests.cpp -c

list: DoublyLinkedList.cpp DoublyLinkedList.hpp
	g++ DoublyLinkedList.cpp -c -o doublylinkedlist 

clean:
	rm mytests.o doublylinkedlist mytests