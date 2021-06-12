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
	Node(string, int); 
	void setPreviousNode(Node*); 
	Node* getPreviousNode(); 
	void setNextNode(Node*);
	Node* getNextNode();
	string getWord(); 
	int getHowManyNodeBefore();
};

#endif
