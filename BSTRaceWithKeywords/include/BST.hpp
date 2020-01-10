#ifndef BST_HPP
#define BST_HPP
#include "Node.hpp"
using namespace std;
class BST
{
private:

	int totalChild = 0; //Toplam cocuk degiskenini tutan degisken.
	Node* root = nullptr; //Root'u tutan degisken.

	void findAndAdd(Node*&, int); //Bulup ekleme yapan metod.
	bool findAndDelete(Node*&, int); //Bulup silme yapan metod.
	void postOrder(Node*); //postorder cikti icin metod.
	bool removeNode(Node*&); //Dugum silen metod.
	bool isNull(); //Null olup olmadigini kontrol eden metod.
	void clear(); //BST'yi temizleyen metod.

public:
	BST(); //BST yapici metod.

	Node* getRoot(); //Root'u alan metod.


	int MaxValue(); //En buyugu bulan metod.

	int getTotalChild(); //Toplam cocugu donen metod.

	void clearTotalChild(); //Agac degisikliginde temizleme yapan metod.
	
	void Add(int); //ekleme islemini yapan public metod

	void PostOrder(); //Postorder bastirma islemini yapan metod.

	void DeleteT(int); //Degeri silen public metod.

	~BST(); //BST yikici metod.
};

#endif