/**
* @file test.cpp
* @description Top sınıfını kod içeriği.
* @author Mustafa Emre Ozmen - mustafa.eozmen@gmail.com
*/

#ifndef BALL_HPP
#define BALL_HPP

class Ball {
private:
	char ballName; //Top objesine random char atayan constructor.
public:
	Ball();
	char getBallName(); //private olan top ismini almak için kullanılan metod.
};

#endif