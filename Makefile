driver: mytests.o
	g++ -o driver mytests.o
	./driver
	
mytests.o: mytests.cpp DoublyLinkedList.hpp DoublyLinkedList.cpp
	g++ -c mytests.cpp
	
