#include "ball.hpp"
#include <iostream>
#include <ctime>
using namespace std;

Ball::Ball()
{
	ballName = (char)(rand() % 26) + 97;
}

char Ball::getBallName()
{
	return this->ballName;
}