#ifndef READINGOPERATIONS_HPP
#define READINGOPERATIONS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Node.hpp"
#include "DoubleLinkedList.hpp"

using namespace std;

class ReadingOperations {
private:
	DoubleLinkedList* tmpList;
public:
	DoubleLinkedList* readFrom(string);
	int calculateSaving(DoubleLinkedList*);
};

#endif
