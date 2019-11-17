/**
* @file test.cpp
* @description Top sınıfını kod içeriği.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#include "ball.hpp"
#include <iostream>
#include <ctime>

using namespace std;

Ball::Ball() //Top objesine random char atayan constructor.
{
	ballName = (char)(rand() % 26) + 97;
}

char Ball::getBallName() //private olan top ismini almak için kullanılan metod.
{
	return this->ballName;
}