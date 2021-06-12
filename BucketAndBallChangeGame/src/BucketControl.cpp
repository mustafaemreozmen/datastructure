#include "BucketControl.hpp"

void BucketControl::setBucketQuantity()
{
	cout << "Bucket Count:";
	cin >> enteredQuantity;
}

void BucketControl::createNullBuckets()
{
	buckets = new Bucket *[enteredQuantity];
	for (int i = 0; i < enteredQuantity; i++)
	{
		Bucket *tmpBucket = new Bucket();
		buckets[i] = tmpBucket;
	}
}

void BucketControl::printBucket(Bucket *bucket)
{
	int j, k = 0;
	for (int i = 2; i <= 4; i++)
	{
		for (j = i; j < 4; j++)
		{
			cout << " ";
		}
		while (k != (2 * i - 1))
		{
			if (k == 0 || k == 2 * i - 2)
				cout << ".";
			else if (i == 2)
				cout << "|";
			else
				cout << " ";
			k++;
		}
		k = 0;
		cout << endl;
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			if (y == 0 || y == 6 || x == 3)
				cout << "#";
			else if (x == 1 && y == 3)
			{
				if (bucket->getBall() != nullptr)
					cout << bucket->getBall()->getBallName();
				else
					cout << "-";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "Bucket Address...:" << bucket << endl;
	cout << "Ball Address..:";
	if (bucket->getBall() == nullptr)
		cout << "NULL";
	else
		cout << bucket->getBall();

	cout << "\n\n";
}

void BucketControl::cleanAllTrashes()
{
	for (int i = 0; i < enteredQuantity; i++)
	{
		buckets[i]->getBall()->~Ball();
		buckets[i]->~Bucket();
	}
}

void BucketControl::printAllBuckets()
{
	for (int i = 0; i < enteredQuantity; i++)
	{
		cout << i + 1 << ". Bucket" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), buckets[i]->getColor());
		printBucket(buckets[i]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

void BucketControl::mainMenu()
{
	int mainMenuSelection;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Choose: \n\n";
	cout << "[1] Place Balls" << endl;
	cout << "[2] Destroy Balls" << endl;
	cout << "[3] Change Bucket" << endl;
	cout << "[4] Change Ball" << endl;
	cout << "[5] Reverse All Buckets" << endl;
	cout << "[6] Reverse All Balls" << endl;
	cout << "[7] Exit" << endl;
	cin >> mainMenuSelection;
	switch (mainMenuSelection)
	{
	case 1:
		system("CLS");
		addBallsForBuckets();
		printAllBuckets();
		mainMenu();
		break;
	case 2:
		system("CLS");
		destroyBalls();
		printAllBuckets();
		mainMenu();
		break;
	case 3:
		system("CLS");
		changeBuckets();
		printAllBuckets();
		mainMenu();
		break;
	case 4:
		system("CLS");
		changeBalls();
		printAllBuckets();
		mainMenu();
		break;
	case 5:
		system("CLS");
		reverseBuckets();
		printAllBuckets();
		mainMenu();
		break;
	case 6:
		system("CLS");
		reverseBalls();
		printAllBuckets();
		mainMenu();
		break;
	case 7:
		cleanAllTrashes();
		break;
	default:
		system("CLS");
		cout << "Wrong choice." << endl;
		mainMenu();
		break;
	}
}

void BucketControl::addBallsForBuckets()
{

	if (buckets[0]->getBall() == nullptr)
	{
		for (int i = 0; i < enteredQuantity; i++)
		{
			Bucket *tmpBucket = buckets[i];
			Ball *tmpBall = new Ball();
			tmpBucket->setBall(tmpBall);
		}
	}
	else
	{
		cout << "Ball placement has been done before" << endl;
	}
}

void BucketControl::destroyBalls()
{
	if (buckets[0]->getBall() != nullptr)
	{
		for (int i = 0; i < enteredQuantity; i++)
		{
			Ball *tmpBall = buckets[i]->getBall();
			buckets[i]->setBall(nullptr);
			delete tmpBall;
		}
	}
	else
		cout << "Ball placement has been done before" << endl;
}

void BucketControl::changeBuckets()
{
	int with, thisOne = 0;
	cout << "Which:";
	cin >> with;
	cout << endl
		 << "Which one:";
	cin >> thisOne;

	Bucket *tmpBucket;
	tmpBucket = buckets[with - 1];
	buckets[with - 1] = buckets[thisOne - 1];
	buckets[thisOne - 1] = tmpBucket;
}

void BucketControl::changeBalls()
{
	if (buckets[0]->getBall() != nullptr)
	{
		int with, thisOne = 0;
		cout << "Which:";
		cin >> with;
		cout << endl
			 << "Which one:";
		cin >> thisOne;

		Ball *tmpBall;
		tmpBall = buckets[with - 1]->getBall();
		buckets[with - 1]->setBall(buckets[thisOne - 1]->getBall());
		buckets[thisOne - 1]->setBall(tmpBall);
	}
	else
		cout << "You cannot place because the ball is not created" << endl;
}

void BucketControl::reverseBuckets()
{

	Bucket *tmpBucket;
	for (int i = 0; i < enteredQuantity / 2; i++)
	{
		tmpBucket = buckets[i];
		buckets[i] = buckets[enteredQuantity - i - 1];
		buckets[enteredQuantity - i - 1] = tmpBucket;
	}
}

void BucketControl::reverseBalls()
{
	Ball *tmpBall;
	if (buckets[0]->getBall() != nullptr)
	{
		for (int i = 0; i < enteredQuantity / 2; i++)
		{
			tmpBall = buckets[i]->getBall();
			buckets[i]->setBall(buckets[enteredQuantity - i - 1]->getBall());
			buckets[enteredQuantity - i - 1]->setBall(tmpBall);
		}
	}
	else
		cout << "You cannot place because the ball is not created" << endl;
}