/**
* @file test.cpp
* @description Top sınıfını kod içeriği.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#include <ctime>
#include "BucketControl.hpp"


int main() {
	srand(time(0));
	//Bucket Control objesi oluşturuldu
	BucketControl* bc = new BucketControl();
	//Bucket adedi alındı.
	bc->setBucketQuantity();
	system("CLS||CLEAR");
	//Null bucketlar oluşturuldu
	bc->createNullBuckets();
	//Tüm bucketlar basıldı.
	bc->printAllBuckets();
	//Main menu çağırıldı.
	bc->mainMenu();
	//Kontrol sınıfı yok edildi.
	delete bc;
	return 0;
}

