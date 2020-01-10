#include "../include/Node.hpp"



Node::Node(int sayi, Node* left, Node* right) { //Node kurucu metodu
	this->left = left;
	this->right = right;
	this->data = sayi;
}

