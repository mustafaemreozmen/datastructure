#include "../include/DoubleLinkedList.hpp"

void DoubleLinkedList::setRoot(Node *root)
{
	this->root = root;
	root->setPreviousNode(nullptr);
	root->setNextNode(nullptr);
	this->tail = root;
}

Node *DoubleLinkedList::getRoot()
{
	return this->root;
}

Node *DoubleLinkedList::getTail()
{
	return this->tail;
}

void DoubleLinkedList::setIter(Node *iter)
{
	this->iter = iter;
}

Node *DoubleLinkedList::getIter()
{
	return this->iter;
}

void DoubleLinkedList::append(Node *node)
{

	if (this->root == nullptr)
	{
		setRoot(node);
	}
	else
	{
		iter = root;
		while (iter->getNextNode() != nullptr)
			iter = iter->getNextNode();
		node->setPreviousNode(iter);
		iter->setNextNode(node);
		node->setNextNode(nullptr);
		this->tail = node;
	}
}

void DoubleLinkedList::printAllNodes()
{
	if (this->root == nullptr)
	{
		cout << "File is empty." << endl;
	}
	else
	{
		iter = root;
		while (iter != nullptr)
		{
			if (iter->getPreviousNode() == nullptr)
			{
				cout << "NULL"
					 << "<-:" << iter->getWord() << " - " << iter->getHowManyNodeBefore() << ":";
			}
			else if (iter->getNextNode() == nullptr)
			{
				cout << "<->:" << iter->getWord() << " - " << iter->getHowManyNodeBefore() << ":->"
					 << "NULL";
			}
			else
			{
				cout << "<->:" << iter->getWord() << " - " << iter->getHowManyNodeBefore() << ":";
			}
			iter = iter->getNextNode();
		}
	}
}

DoubleLinkedList::~DoubleLinkedList()
{
	iter = root->getNextNode();
	while (this->iter != nullptr)
	{
		delete iter->getPreviousNode();
		iter = iter->getNextNode();
	}
}
