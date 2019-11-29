/**
* @file ReadingOperations.hpp
* @description Double Linked List example.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/


#ifndef READINGOPERATIONS_HPP
#define READINGOPERATIONS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Node.hpp"
#include "DoubleLinkedList.hpp"

using namespace std;

// Okuma işlemlerinin yapıldığı sınıfın tanımı
class ReadingOperations {
private:
	DoubleLinkedList* tmpList;
public:
	DoubleLinkedList* readFrom(string);
	int calculateSaving(DoubleLinkedList*);
};

#endif
