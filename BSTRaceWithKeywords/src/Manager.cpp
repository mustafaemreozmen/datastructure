#include "../include/Manager.hpp"


void Manager::stringParse(string line, BST*& team)
{
	string word = "";
	for (auto x : line)
	{
		if (x == ' ')
		{
			//cout << kelime;
			team->Add(stoi(word));
			word = "";
		}
		else
		{
			word = word + x;
		}
	}
}

void Manager::readFile(string path, BST*& team) {
	string line = "";


	ifstream readAFile(path);

	if (readAFile.is_open())
	{
		while (getline(readAFile, line))
		{
			this->stringParse(line, team);
		}
		readAFile.close();
	}
	else {
		cout << "Dosya yok.";
	}
}

void Manager::changeNodes(BST*& p1, BST*& p2) {


	if (p1->getTotalChild() > p2->getTotalChild()) { //benim kaybetme durumu
		int p1Max = p1->MaxValue();
		int p2Root = p2->getRoot()->data;


		p2->Add(p1Max);
		p1->DeleteT(p1->MaxValue());

		p1->Add(p2Root);
		p2->DeleteT(p2->getRoot()->data);



	}

	if (p1->getTotalChild() < p2->getTotalChild()) //rakip kaybetme durumu
	{
		int p2Max = p2->MaxValue();
		int p1Root = p1->getRoot()->data;

		p1->Add(p2Max);
		p2->DeleteT(p2Max);

		p2->Add(p1Root);
		p1->DeleteT(p1Root);


	}
	if (p1->getTotalChild() == p2->getTotalChild()) { //berabere gelmesi

		int p2Root = p2->getRoot()->data;
		int p1Root = p1->getRoot()->data;

		p2->Add(p1Root);

		p1->Add(p2Root);

		p2->DeleteT(p2Root);

		p1->DeleteT(p1Root);

	}



	p1->clearTotalChild();
	p2->clearTotalChild();




}


