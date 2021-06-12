#include <iostream>
#include "../include/BST.hpp"
#include "../include/Manager.hpp"
#include <string>
using namespace std;
BST *team1;
BST *team2;

int main()
{
	Manager *mng = new Manager();
	int winTeam1 = 0;
	int winTeam2 = 0;
	team1 = new BST();
	team2 = new BST();
	mng->readFile("./doc/benim.txt", team1);
	mng->readFile("./doc/rakip.txt", team2);
	int i = 0;
	while (i < 20)
	{
		cout << "\n\nMy Tree PostOrder Step " << i + 1 << " :\n";
		team1->PostOrder();
		cout << "\nMy Tree Total Ancestry...:" << team1->getTotalChild();
		cout << "\n-------------------------------------------------------------------------------------------\n";
		cout << "\nYour Tree PostOrder :\n";
		team2->PostOrder();
		cout << "\nYour Tree Total Ancestry...:" << team2->getTotalChild();
		if (team1->getTotalChild() > team2->getTotalChild())
		{
			cout << "\n\n\n-----------YOUR TREE WIN-----------\n\n";
			winTeam2++;
			cout << "My...:" << winTeam1 << "\nYour...:" << winTeam2 << endl;
		}
		else if (team1->getTotalChild() < team2->getTotalChild())
		{
			cout << "\n\n\n-----------MY TREE WIN-----------\n\n";
			winTeam1++;
			cout << "My...:" << winTeam1 << "\nYour...:" << winTeam2 << endl;
		}
		else if (team1->getTotalChild() == team2->getTotalChild())
		{
			cout << "\n\n\n-----------EQUAL!-----------\n\n";
			cout << "My...:" << winTeam1 << "\nYour...:" << winTeam2 << endl;
		}
		mng->changeNodes(team1, team2);
		if (winTeam1 == 5 || winTeam2 == 5)
		{
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