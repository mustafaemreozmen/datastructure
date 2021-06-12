#include <ctime>
#include "BucketControl.hpp"

int main() {
	srand(time(0));
	BucketControl* bc = new BucketControl();
	bc->setBucketQuantity();
	system("CLS||CLEAR");
	bc->createNullBuckets();
	bc->printAllBuckets();
	bc->mainMenu();
	delete bc;
	return 0;
}

