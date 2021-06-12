#ifndef BST_HPP
#define BST_HPP
#include "Node.hpp"
using namespace std;
class BST
{
private:
	int totalChild = 0;
	Node *root = nullptr;
	void findAndAdd(Node *&, int);
	bool findAndDelete(Node *&, int);
	void postOrder(Node *);
	bool removeNode(Node *&);
	bool isNull();
	void clear();
public:
	BST();
	Node *getRoot();
	int MaxValue();
	int getTotalChild();
	void clearTotalChild();
	void Add(int);
	void PostOrder();
	void DeleteT(int);
	~BST();
};

#endif