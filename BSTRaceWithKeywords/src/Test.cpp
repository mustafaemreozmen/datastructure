#include <iostream>
#include "../include/BST.hpp"
#include "../include/Manager.hpp"
#include <string>


using namespace std;

BST* team1;
BST* team2;

int main()
{
	Manager* mng = new Manager();

	int winTeam1 = 0;
	int winTeam2 = 0; //Takimlarin win sayilari

	team1 = new BST();
	team2 = new BST();

	//Manager.

	mng->readFile("./doc/benim.txt", team1); //Takim 1 ve Takim 2 icin okuma islemi gerceklestirildi.
	mng->readFile("./doc/rakip.txt", team2);

	int i = 0;
	while (i < 20) { //20 tur oynanmaya baslandi.
		

		cout << "\n\nBenim Agac Postorder ADIM " << i+1 <<" :\n";
		team1->PostOrder();
		cout << "\nBenim Agac Toplam Soy Sayisi...:" << team1->getTotalChild();
		cout << "\n-------------------------------------------------------------------------------------------\n";
		cout << "\nRakip agac postorder :\n";
		team2->PostOrder();
		cout << "\nRakip Agac Toplam Soy Sayisi...:" << team2->getTotalChild();


		if (team1->getTotalChild() > team2->getTotalChild())
		{
			cout << "\n\n\n-----------RAKIP AGAC KAZANDI-----------\n\n";
			winTeam2++;
			cout << "Benim...:" << winTeam1 << "\nRakip...:" << winTeam2 << endl;
		}
		else if (team1->getTotalChild() < team2->getTotalChild()) {
			cout << "\n\n\n-----------BENIM AGAC KAZANDI-----------\n\n";
			winTeam1++;
			cout << "Benim...:" << winTeam1 << "\nRakip...:" << winTeam2 << endl;
		}
		else if(team1->getTotalChild() == team2->getTotalChild()){
			cout << "\n\n\n-----------BERABERE KALINDI-----------\n\n";
			cout << "Benim...:" << winTeam1 << "\nRakip...:" << winTeam2 << endl;
		}

		mng->changeNodes(team1, team2);


		
		if (winTeam1 == 5 || winTeam2 == 5) {
			return 0;
		}


		i++;

		system("PAUSE");
	}
	
	delete mng;
	delete team1;
	delete team2;

	return 0;
}