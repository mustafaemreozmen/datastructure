/**
* @file DoubleLinkedList.hpp
* @description Double Linked List example.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/


#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include <iostream>
#include <string>
#include "Node.hpp"
using namespace std;

//İkili bağıl listenin tanımının yapıldı
class DoubleLinkedList {
private:
	Node* root = nullptr; //Ana düğümü işaret eden pointer
	Node* tail = nullptr; //Kuyruk düğümünü işaret eden pointer
	Node* iter = root; //Ana düğümü işaret eden iterator
public:
	void setRoot(Node*); //Ana düğüm değerini ata
	Node* getRoot(); //Ana düğüm değerini göster
	Node* getTail(); //Kuyruk değer değerini göster
	void setIter(Node*); // Itarator değerini ata
	Node* getIter(); //Itarator değerini göster
	void append(Node*); //Okunan değerin sonraki düğüme ekleyen metod
	void printAllNodes(); //Düğümleri ekrana çıkar
	~DoubleLinkedList(); //Oluşturulan nesneleri sil
};

#endif
