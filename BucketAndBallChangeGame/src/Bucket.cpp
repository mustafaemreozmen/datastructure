/**
* @file test.cpp
* @description Top sınıfını kod içeriği.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#include "Bucket.hpp"
#include <iostream>

Bucket::Bucket() { //Kova kurucu metodu.
	setColor();
}

void Bucket::setColor() { //Renk set etme metodu. windows.h içindeki 1 ve 14 arası tüm renklere random erişim için hazırlanmıştır.
	color = 1 + (rand() % 14);
}

int Bucket::getColor() { //Rengi get etme metodu.
	return color;
}

void Bucket::setBall(Ball* ball) { //Top objesini set etme metodu.
	this->ball = ball;
}

Ball* Bucket::getBall() { //Top objesini get etme metodu.
	return this->ball;
}

Bucket::~Bucket() { //Bucket yok edici metodu.
	delete ball;
}