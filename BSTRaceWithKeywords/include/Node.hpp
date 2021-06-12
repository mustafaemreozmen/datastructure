#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

struct Node
{
	Node(int sayi, Node* = nullptr, Node* = nullptr);
	int childCount = 0; 
	int data = 0;
	Node* left;
	Node* right; 
};
#endif