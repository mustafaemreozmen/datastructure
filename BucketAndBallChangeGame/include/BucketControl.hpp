#ifndef BUCKETCONTROL_HPP
#define BUCKETCONTROL_HPP
#include "Bucket.hpp"
#include "Ball.hpp"
#include "windows.h"
#include <iostream>
using namespace std;

class BucketControl {
private:
	Bucket** buckets;		
	int enteredQuantity;	
public:
	void setBucketQuantity();
	void createNullBuckets();
	void printBucket(Bucket* bucket);
	void cleanAllTrashes();
	void printAllBuckets();
	void mainMenu();
	void addBallsForBuckets();
	void destroyBalls();
	void changeBuckets();
	void changeBalls();
	void reverseBuckets();
	void reverseBalls();
};
#endif