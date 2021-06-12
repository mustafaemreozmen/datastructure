#include "Bucket.hpp"
#include <iostream>

Bucket::Bucket() { 
	setColor();
}

void Bucket::setColor() {
	color = 1 + (rand() % 14);
}

int Bucket::getColor() { 
	return color;
}

void Bucket::setBall(Ball* ball) { 
	this->ball = ball;
}

Ball* Bucket::getBall() { 
	return this->ball;
}

Bucket::~Bucket() { 
	delete ball;
}