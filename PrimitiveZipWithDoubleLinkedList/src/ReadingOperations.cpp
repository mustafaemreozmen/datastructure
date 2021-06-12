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
		cout << "File not found.\n";
		exit(-1);
	}
	while (inFile >> word)
	{
			tmpList->setIter(tmpList->getTail());
			while (tmpList->getIter() != nullptr) {
				counter++;
				if (word == tmpList->getIter()->getWord()) {
					varMi = true;
					break; 
				}
				tmpList->setIter(tmpList->getIter()->getPreviousNode());
			}
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

int ReadingOperations::calculateSaving(DoubleLinkedList* list) {
	
	int totalSaving = 0;
	
	list->setIter(list->getTail());
	while (list->getIter() != nullptr) {
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




