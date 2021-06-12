#include "../include/Node.hpp"

Node::Node(int sayi, Node* left, Node* right) { 
	this->left = left;
	this->right = right;
	this->data = sayi;
}

