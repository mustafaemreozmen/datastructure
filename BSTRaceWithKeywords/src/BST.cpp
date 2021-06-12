#include "../include/BST.hpp"

BST::BST()
{
	this->root = NULL;
}

Node *BST::getRoot()
{
	return this->root;
}

void BST::findAndAdd(Node *&subNode, int data)
{
	if (subNode == nullptr)
	{
		subNode = new Node(data);
	}
	else if (data <= subNode->data)
	{
		subNode->childCount++;
		return findAndAdd(subNode->left, data);
	}
	else if (data > subNode->data)
	{
		subNode->childCount++;
		return findAndAdd(subNode->right, data);
	}
}

int BST::MaxValue()
{
	Node *current = root;
	while (current->right != nullptr)
		current = current->right;
	return (current->data);
}

bool BST::findAndDelete(Node *&subNode, int eleman)
{
	if (subNode == NULL)
		return false;
	if (subNode->data == eleman)
	{
		subNode->childCount--;
		return removeNode(subNode);
	}
	else if (eleman < subNode->data)
	{
		subNode->childCount--;
		return findAndDelete(subNode->left, eleman);
	}
	else
	{
		subNode->childCount--;
		return findAndDelete(subNode->right, eleman);
	}
}

int BST::getTotalChild()
{
	return totalChild;
}

void BST::clearTotalChild()
{
	totalChild = 0;
}

void BST::postOrder(Node *subNode)
{
	if (subNode != nullptr)
	{
		postOrder(subNode->left);
		postOrder(subNode->right);
		totalChild += subNode->childCount;
		cout << "<" << subNode->data << "," << subNode->childCount << "> ";
	}
}

void BST::Add(int data)
{
	findAndAdd(this->root, data);
}

void BST::PostOrder()
{
	postOrder(root);
}

void BST::DeleteT(int deger)
{
	findAndDelete(root, deger);
}

bool BST::removeNode(Node *&subNode)
{
	Node *removingNode = subNode;
	if (subNode->right == NULL)
	{
		subNode->childCount--;
		subNode = subNode->left;
	}
	else if (subNode->left == NULL)
	{
		subNode->childCount--;
		subNode = subNode->right;
	}
	else
	{
		removingNode = subNode->left;
		Node *parentNode = subNode;
		while (removingNode->right != NULL)
		{
			parentNode = removingNode;
			parentNode->childCount--;
			removingNode = removingNode->right;
		}
		subNode->data = removingNode->data;
		if (parentNode == subNode)
		{
			subNode->left = removingNode->left;
		}
		else
		{
			parentNode->right = removingNode->left;
		}
	}
	delete removingNode;
	return true;
}

bool BST::isNull()
{
	return this->root == NULL;
}

void BST::clear()
{
	while (!isNull())
		removeNode(root);
}

BST::~BST()
{
	clear();
}
