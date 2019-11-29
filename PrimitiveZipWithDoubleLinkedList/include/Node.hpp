/**
* @file Node.hpp
* @description Double Linked List example.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/


#ifndef NODE_HPP
#define NODE_HPP
#include <string>

using namespace std;

class Node {
private:

	string word;
	int howManyNodeBefore;
	Node* previousNode;
	Node* nextNode;

public:

	Node(string, int); //Düğümün tuttuğu kelime ve düğüm sayısını atayan metod

	void setPreviousNode(Node*); //Sonraki düğümün pointerını atayan metod
	Node* getPreviousNode(); //Sonraki düğümün pointer değerini döndüren metod

	void setNextNode(Node*);//Önceki düğümün pointerını atayan metod
	Node* getNextNode();//Önceki düğümün pointer değerini döndüren metod

	string getWord(); //Düğümün tuttuğu kelimeyi döndüren metod

	int getHowManyNodeBefore(); //Önceki düğümlerin sayısını döndüren metod
};

#endif
