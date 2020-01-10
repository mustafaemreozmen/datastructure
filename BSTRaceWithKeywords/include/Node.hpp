#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

struct Node
{
	Node(int sayi, Node* = nullptr, Node* = nullptr); //Node kurucu metodu
	
	int childCount = 0; //Soy sayısı
	int data = 0; //Veri
	Node* left; //Sol düğüm
	Node* right; //Sağ düğüm
};
#endif