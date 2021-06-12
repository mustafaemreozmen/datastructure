#include "../include/Node.hpp"

Node::Node(string word="", int howManyNodeBefore=0) {
	this->word = word; 
	this->howManyNodeBefore = howManyNodeBefore;
}

void Node::setNextNode(Node* nextNode) {
	this->nextNode = nextNode;
}

Node* Node::getNextNode() {
	return this->nextNode;
}

void Node::setPreviousNode(Node* previousNode) {
	this->previousNode = previousNode;
}

Node* Node::getPreviousNode() {
	return this->previousNode;
}

string Node::getWord() {
	return this->word;
}

int Node::getHowManyNodeBefore() {
	return this->howManyNodeBefore;
}