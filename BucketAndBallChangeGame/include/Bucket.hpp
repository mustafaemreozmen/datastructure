#ifndef BUCKET_HPP
#define BUCKET_HPP
#include "Ball.hpp"

class Bucket {
private:
	Ball* ball = nullptr;
	int color;
public:
	Bucket(); 
	void setColor(); 
	int getColor(); 
	void setBall(Ball*);
	Ball* getBall();
	~Bucket(); 
};

#endif