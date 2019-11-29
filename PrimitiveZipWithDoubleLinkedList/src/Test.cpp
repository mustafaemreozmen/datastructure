/**
* @file test.cpp
* @description Double Linked List example.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#include <ctime>
#include <iostream>
#include "../include/ReadingOperations.hpp"

using namespace std;

int main() {
	
	ReadingOperations* ro = new ReadingOperations(); //Okuma işlemi yapacak metodu oluştur
	DoubleLinkedList* test = ro->readFrom("icerik.txt"); //Icerik.txt den okuma yapmaya başla
	cout << endl << endl;
	test->printAllNodes(); //Düğümleri ekrana bas
	cout << endl;
	cout << "Toplam Kazanc: " << ro->calculateSaving(test) << " Byte" << endl;
	delete test; //Oluşturulan objeleri sil
	delete ro;
	return 0;
}

