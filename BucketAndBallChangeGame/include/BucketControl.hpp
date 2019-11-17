/**
* @file test.cpp
* @description Top sınıfını kod içeriği.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#ifndef BUCKETCONTROL_HPP
#define BUCKETCONTROL_HPP
#include "Bucket.hpp"
#include "Ball.hpp"
#include "windows.h"
#include <iostream>

using namespace std;

class BucketControl {

private:
	Bucket** buckets;		//Kovaların dizisini işaret eden pointer
	int enteredQuantity;	//Kova listesi uzunluğu

public:
	//Toplam kova sayısını ayarlayan metod
	void setBucketQuantity();
	//Boş kovaları oluşturan metod
	void createNullBuckets();
	//Bir kovayı basan metod
	void printBucket(Bucket* bucket);
	//Çöpleri temizleyen metod
	void cleanAllTrashes();
	//Tüm kovaları yazdıran metod
	void printAllBuckets();
	//Ana menü metodu
	void mainMenu();
	//Kovalara top yerleştirme metodu
	void addBallsForBuckets();
	//Topları yok etme metodu
	void destroyBalls();
	//Kovaları değiştirme metodu
	void changeBuckets();
	//Topları değiştirme metodu
	void changeBalls();
	//Kovaları tersten yerleştirme metodu
	void reverseBuckets();
	//Topları tersten yerleştirme metodu
	void reverseBalls();
};
#endif