/**
* @file test.cpp
* @description Top sınıfını kod içeriği.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#include "BucketControl.hpp"

//Toplam kova sayısını ayarlama metodu
void BucketControl::setBucketQuantity() {
	cout << "Kova Sayisi:";
	cin >> enteredQuantity;
}

//Boş kovaları oluşturma metodu
void BucketControl::createNullBuckets() {

	buckets = new Bucket*[enteredQuantity];

	for (int i = 0; i < enteredQuantity; i++)
	{
		Bucket* tmpBucket = new Bucket();
		buckets[i] = tmpBucket;
	}
}

//Bir kovayı basma metodu
void BucketControl::printBucket(Bucket* bucket) {
	int j, k = 0;

	for (int i = 2; i <= 4; i++)
	{
		for (j = i; j < 4; j++) {
			cout << " ";
		}

		while (k != (2 * i - 1)) {

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


	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 7; y++) {
			if (y == 0 || y == 6 || x == 3)
				cout << "#";
			else if (x == 1 && y == 3) {
				if (bucket->getBall() != nullptr)
					cout << bucket->getBall()->getBallName();
				else
					cout << "-";
			}
			else cout << " ";
		}
		cout << endl;

	}

	cout << "Kova Adresi...:" << bucket << endl;
	cout << "Topun Adresi..:";
	if (bucket->getBall() == nullptr)
		cout << "NULL";
	else cout << bucket->getBall();

	cout << "\n\n";

}

//Çöpleri temizleme metodu
void BucketControl::cleanAllTrashes() {
	for (int i = 0; i < enteredQuantity; i++)
	{
		buckets[i]->getBall()->~Ball();
		buckets[i]->~Bucket();
	}

}

//Tüm kovaları basma metodu
void BucketControl::printAllBuckets() {
	for (int i = 0; i < enteredQuantity; i++)
	{
		cout << i + 1 << ". Kova" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), buckets[i]->getColor());
		printBucket(buckets[i]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

//Ana menü fonksiyonu metodu
void BucketControl::mainMenu() {
	int mainMenuSelection;
	//İşlemler menüsü çıktısı
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Lutfen secim yapiniz: \n\n";
	cout << "[1] Toplari Yerlestir" << endl;
	cout << "[2] Toplari Yoket" << endl;
	cout << "[3] Kova Degistir" << endl;
	cout << "[4] Top Degistir" << endl;
	cout << "[5] Kovalari Tersten Yerlestir" << endl;
	cout << "[6] Toplari Tersten Yerlestir" << endl;
	cout << "[7] Cikis" << endl;
	cin >> mainMenuSelection;
	//Tercih switch-case'i

	switch (mainMenuSelection)
	{
	case 1:
		/*Kovaları oluşturma işlemi*/
		system("CLS");
		addBallsForBuckets();
		printAllBuckets();
		mainMenu();
		break;
	case 2:
		/* Toplari yoketme işlemi */
		system("CLS");
		destroyBalls();
		printAllBuckets();
		mainMenu();
		break;
	case 3:
		/* Kova degistirme işlemi */
		system("CLS");
		changeBuckets();
		printAllBuckets();
		mainMenu();
		break;
	case 4:
		/* Top degistirme işlemi */
		system("CLS");
		changeBalls();
		printAllBuckets();
		mainMenu();
		break;
	case 5:
		/* Kovalari tersten yerlestirme işlemi */
		system("CLS");
		reverseBuckets();
		printAllBuckets();
		mainMenu();
		break;
	case 6:
		/* Toplari tersten yerleştirme işlemi */
		system("CLS");
		reverseBalls();
		printAllBuckets();
		mainMenu();
		break;
	case 7:
		/*Program çıkış ve çöp yok edilmeleri*/
		cleanAllTrashes();
		break;
	default:
		system("CLS");
		cout << "Yanlis secim yaptiniz. Lutfen tekrar secim yapiniz." << endl;
		mainMenu();
		break;
	}
}

//İşlemler

//Topları kovalara ekleme metodu
void BucketControl::addBallsForBuckets() {

	if (buckets[0]->getBall() == nullptr) {
		for (int i = 0; i < enteredQuantity; i++)
		{
			Bucket* tmpBucket = buckets[i];
			Ball* tmpBall = new Ball();
			tmpBucket->setBall(tmpBall);
		}
	}
	else {
		cout << "Daha once top yerlestirme islemi yapilmis" << endl;
	}
}

//Topları Yoketme metodu
void BucketControl::destroyBalls() {
	if (buckets[0]->getBall() != nullptr) {
		for (int i = 0; i < enteredQuantity; i++)
		{
			Ball* tmpBall = buckets[i]->getBall();
			buckets[i]->setBall(nullptr);
			delete tmpBall;
		}
	}
	else
		cout << "Kovalarda zaten top bulunmamaktadir." << endl;


}

//Kovaları değiştirme metodu
void BucketControl::changeBuckets() {
	int with, thisOne = 0;
	cout << "Hangisi:";
	cin >> with;
	cout << endl << "Hangisiyle:";
	cin >> thisOne;

	Bucket* tmpBucket;
	tmpBucket = buckets[with - 1];
	buckets[with - 1] = buckets[thisOne - 1];
	buckets[thisOne - 1] = tmpBucket;
}

//Topları değiştirme metodu
void BucketControl::changeBalls() {
	if (buckets[0]->getBall() != nullptr)
	{
		int with, thisOne = 0;
		cout << "Hangisi:";
		cin >> with;
		cout << endl << "Hangisiyle:";
		cin >> thisOne;

		Ball* tmpBall;
		tmpBall = buckets[with - 1]->getBall();
		buckets[with - 1]->setBall(buckets[thisOne - 1]->getBall());
		buckets[thisOne - 1]->setBall(tmpBall);
	}
	else
		cout << "Daha once top olusturulmamis, bu yuzden degisim yapamazsiniz" << endl;


}

//Kovaları tersten yerleştirme metodu
void BucketControl::reverseBuckets() {

	Bucket* tmpBucket;
	for (int i = 0; i < enteredQuantity / 2; i++)
	{
		tmpBucket = buckets[i];
		buckets[i] = buckets[enteredQuantity - i - 1];
		buckets[enteredQuantity - i - 1] = tmpBucket;
	}
}

//Topları tersten yerleştirme metodu
void BucketControl::reverseBalls() {
	Ball* tmpBall;
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
		cout << "Daha once top olusturulmamis, bu yuzden ters yerlestirme yapamazsiniz" << endl;



}