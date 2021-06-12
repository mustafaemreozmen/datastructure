#include <ctime>
#include <iostream>
#include "../include/ReadingOperations.hpp"

using namespace std;

int main() {
	ReadingOperations* ro = new ReadingOperations(); 
	DoubleLinkedList* test = ro->readFrom("icerik.txt"); 
	cout << endl << endl;
	test->printAllNodes(); 
	cout << endl;
	cout << "Total Earn: " << ro->calculateSaving(test) << " Byte" << endl;
	delete test;
	delete ro;
	return 0;
}

