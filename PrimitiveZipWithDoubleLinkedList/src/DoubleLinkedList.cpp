/**
* @file DoubleLinkedList.cpp
* @description Double Linked List example.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/


#include "../include/DoubleLinkedList.hpp"

//Ana düğüm için atamaları yapan metod
void DoubleLinkedList::setRoot(Node* root) {
	this->root = root;
	root->setPreviousNode(nullptr);
	root->setNextNode(nullptr);
	this->tail = root;
}
//Ana düğümü döndüren metod
Node* DoubleLinkedList::getRoot() {
	return this->root;
}
//Kuyruk düğümünü döndüren metod
Node* DoubleLinkedList::getTail() {
	return this->tail;
}
//Iter değerini atayan metod
void DoubleLinkedList::setIter(Node* iter) {
	this->iter = iter;
}
//Iter değerini döndüren metod
Node* DoubleLinkedList::getIter() {
	return this->iter;
}
// Okunan değeri liste sonuna ekleyen fonksiyon
void DoubleLinkedList::append(Node* node) {

	if (this->root == nullptr) {
		setRoot(node);
	} else {
		iter = root;
		while (iter->getNextNode() != nullptr) {
			iter = iter->getNextNode();
		}
		node->setPreviousNode(iter);
		iter->setNextNode(node);
		node->setNextNode(nullptr);
		this->tail = node;

	}
}
//Düğümleri ekrana basan metod
void DoubleLinkedList::printAllNodes() {
	if (this->root == nullptr) {
		cout << "Dosya bos oldugu icin cift yonlu bagli liste olusturulamamis." << endl;
	} else {
		iter = root;
		while (iter != nullptr) {
			if (iter->getPreviousNode() == nullptr) {
				cout << "NULL" << "<-:" << iter->getWord() << " - " << iter->getHowManyNodeBefore() << ":";
			}
			else if (iter->getNextNode() == nullptr) {
				cout << "<->:" << iter->getWord() << " - " << iter->getHowManyNodeBefore() << ":->" << "NULL";
			}
			else {
				cout << "<->:" << iter->getWord() << " - " << iter->getHowManyNodeBefore() << ":";
			}

			iter = iter->getNextNode();
		}
	}
}
//Çöp toplama işini yapan metod 
DoubleLinkedList::~DoubleLinkedList() {
	
	iter = root->getNextNode();
	while (this->iter != nullptr) {
		delete iter->getPreviousNode();
		iter = iter->getNextNode();
	}
}

