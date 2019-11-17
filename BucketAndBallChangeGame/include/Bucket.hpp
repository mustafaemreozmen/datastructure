/**
* @file test.cpp
* @description Top sınıfını kod içeriği.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#ifndef BUCKET_HPP
#define BUCKET_HPP
#include "Ball.hpp"

class Bucket {
private:

	Ball* ball = nullptr;
	int color;

public:

	Bucket(); //Kova kurucu metodu.
	void setColor(); //Renk set etme metodu.
	int getColor(); //Rengi get etme metodu.
	void setBall(Ball*); //Top objesini set etme metodu.
	Ball* getBall(); //Top objesini get etme metodu.
	~Bucket(); //Bucket yok edici metodu.

};

#endif