/**
* @file ReadingOperations.cpp
* @description Double Linked List example.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/


#include "../include/ReadingOperations.hpp"

DoubleLinkedList* ReadingOperations::readFrom(string path) {
	
	tmpList = new DoubleLinkedList();
	ifstream inFile(path);
	Node* tmpNode;
	string word;

	bool varMi = false;
	int counter = 0;
	
	if (!inFile)
	{
		cout << "Dosya bulunamadi veya acilamadi.\n";
		exit(-1); //Hatalı çıkış.
	}
	//Kelime sayısı kadar tekrar eden bir döngü
	while (inFile >> word)
	{
			//Iter değişkenini kuyruk değeri olarak atama
			tmpList->setIter(tmpList->getTail());
			//Her yeni düğüm için sayacı bir arttır
			while (tmpList->getIter() != nullptr) {
				counter++;
				
				//Eğer düğümde aynı kelime tekrarlandıysa döngüden çık
				if (word == tmpList->getIter()->getWord()) {
					varMi = true;
					break; 
				}
				
				tmpList->setIter(tmpList->getIter()->getPreviousNode());
			}
			//Aynı kelime tekrarlanmış mı kontrolünü yapan ve kelime tekrarlandıysa kaç düğüm öncesinde  yazılmış onu bulan if else karar yapısı
			if (varMi == false) {
				tmpNode = new Node(word, 0);

			}
			else{
				tmpNode = new Node("", counter);
				varMi = false;

			}

		tmpList->append(tmpNode);
		counter = 0;

	}

	inFile.close();

	return tmpList;


}
//Bit Kazanç işlemlerinin yapıldığı yer
int ReadingOperations::calculateSaving(DoubleLinkedList* list) {
	
	int totalSaving = 0;
	
	list->setIter(list->getTail());
	//Kuyruk düğümden geriye doğru giden döngü
	while (list->getIter() != nullptr) {
		//Eğer kelime atanmadıysa yerine kaç düğüm öncesinde aynı kelimenin atandığını yazan if karar yapısı 
		if (list->getIter()->getWord() == "") {
			
			int goTo = list->getIter()->getHowManyNodeBefore();
			int stepValue = goTo;
			int stepByte = 0;

			while (stepValue > 0) {
				stepValue = stepValue / 10;
				stepByte++;
			}

			Node* tmp = list->getIter();

			for (int i = 0; i < goTo; i++) {
				list->setIter(list->getIter()->getPreviousNode());
			}

			totalSaving += (list->getIter()->getWord().length() - stepByte);
			list->setIter(tmp);
		}


		list->setIter(list->getIter()->getPreviousNode());
	}

	return totalSaving;
}




