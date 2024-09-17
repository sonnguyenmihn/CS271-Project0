CXX = g++

mytests: DLL.o mytests.o
	$(CXX) DLL.o mytests.o -o mytests
	./mytests

list: DLL.o
	$(CXX) DLL.o -o doublylinkedlist

DLL.o:DoublyLinkedList.hpp DoublyLinkedList.cpp 
	$(CXX) -c DoublyLinkedList.cpp -o DLL.o

mytests.o: mytests.cpp
	$(CXX) -c mytests.cpp -o mytests.o

clean: 
	rm -f *.o mytests doublylinkedlist
