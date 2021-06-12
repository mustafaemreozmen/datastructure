#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include <iostream>
#include <string>
#include "Node.hpp"
using namespace std;

class DoubleLinkedList {
private:
	Node* root = nullptr;
	Node* tail = nullptr;
	Node* iter = root; 
public:
	void setRoot(Node*); 
	Node* getRoot(); 
	Node* getTail(); 
	void setIter(Node*); 
	Node* getIter(); 
	void append(Node*); 
	void printAllNodes();
	~DoubleLinkedList(); 
};

#endif
