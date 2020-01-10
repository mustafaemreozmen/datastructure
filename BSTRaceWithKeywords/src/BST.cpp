#include "../include/BST.hpp"

BST::BST() {
	this->root = NULL;
} //BST yapici metod.

Node* BST::getRoot() {
	return this->root;
} //Root'u alan metod.

void BST::findAndAdd(Node*& subNode, int data) { //Bulup ekleme yapan metod.


	if (subNode == nullptr) {
		subNode = new Node(data);
	}


	else if (data <= subNode->data) {
		subNode->childCount++;
		return findAndAdd(subNode->left, data);
	}
		
	else if (data > subNode->data) {
		subNode->childCount++;
		return findAndAdd(subNode->right, data);
	}
}

int BST::MaxValue() //En buyugu bulan metod.
{
	Node* current = root;
	while (current->right != nullptr)
		current = current->right;

	return (current->data);
} 

bool BST::findAndDelete(Node*& subNode, int eleman) { //Bulup silme yapan metod.


	if (subNode == NULL) 
		return false;

	if (subNode->data == eleman) {
		subNode->childCount--;

		return removeNode(subNode);
	}
		
	else if (eleman < subNode->data) {
		subNode->childCount--;
		return findAndDelete(subNode->left, eleman);
	}
		
	else {
		subNode->childCount--;
		return findAndDelete(subNode->right, eleman);
	}
}

int BST::getTotalChild() { //Toplam cocugu donen metod.
	return totalChild;
}

void BST::clearTotalChild() { //Agac degisikliginde temizleme yapan metod.
	totalChild = 0;
} 



void BST::postOrder(Node* subNode) { //postorder cikti icin metod.
	if (subNode != nullptr) {
		postOrder(subNode->left);
		postOrder(subNode->right);
		totalChild += subNode->childCount;
		cout << "<" << subNode->data << "," << subNode->childCount << "> ";
	}
} 





void BST::Add(int data) {  //ekleme islemini yapan public metod
	findAndAdd(this->root, data);
}

void BST::PostOrder() { //Postorder bastirma islemini yapan metod.
	postOrder(root);
}


void BST::DeleteT(int deger) { //Degeri silen public metod.
	findAndDelete(root, deger);
}

bool BST::removeNode(Node*& subNode) { //Dugum silme islemini gerceklestiriyor

	Node* removingNode = subNode;

	if (subNode->right == NULL) {
		subNode->childCount--;
		subNode = subNode->left;
	}
		

	else if (subNode->left == NULL) {
		subNode->childCount--;
		subNode = subNode->right;
	}
		

	else { // iki cocuklu dugum siliniyor
		removingNode = subNode->left;
		Node* parentNode = subNode;
		while (removingNode->right != NULL) {
			parentNode = removingNode;
			parentNode->childCount--;
			removingNode = removingNode->right;
		}
		subNode->data = removingNode->data;
		if (parentNode == subNode) {
			subNode->left = removingNode->left;

		}
		else {
			parentNode->right = removingNode->left;
		}
	}


	delete removingNode;
	

	return true;
} //Dugum silen metod.


bool BST::isNull() { //Null olup olmadigini kontrol eden metod.
	return this->root == NULL;
}

void BST::clear() { //BST'yi temizleyen metod.
	while (!isNull()) removeNode(root);
} 

BST::~BST() { //Yikici metod
	clear();
}

