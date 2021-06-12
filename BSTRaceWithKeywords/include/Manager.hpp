#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "BST.hpp"
#include <string>
#include <fstream>
using namespace std;

class Manager{
private:
	int test;
public:
	 void stringParse(string, BST*&);
	 void changeNodes(BST*&, BST*&);
	 void readFile(string, BST*&);
};
#endif