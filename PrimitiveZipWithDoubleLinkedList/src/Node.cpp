/**
* @file Node.cpp
* @description Double Linked List example.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/


#include "../include/Node.hpp"

//Düğümün içine kelime ataması yapan metod		
Node::Node(string word="", int howManyNodeBefore=0) {
	this->word = word; 
	this->howManyNodeBefore = howManyNodeBefore;
}

//Sonraki düğümü atayan metod
void Node::setNextNode(Node* nextNode) {
	this->nextNode = nextNode;
}

//Sonraki Düğüm Değerini döndüren metod
Node* Node::getNextNode() {
	return this->nextNode;
}

//Önceki düğümü atayan metod
void Node::setPreviousNode(Node* previousNode) {
	this->previousNode = previousNode;
}

//Önceki Düğüm Değerini döndüren metod
Node* Node::getPreviousNode() {
	return this->previousNode;
}

//Düğümün tuttuğu kelimeyi döndüren metod
string Node::getWord() {
	return this->word;
}

//Önceki düğüm sayısını tutan metod
int Node::getHowManyNodeBefore() {
	return this->howManyNodeBefore;
}