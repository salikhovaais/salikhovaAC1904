#pragma once
#include <iostream>
#include <string>
using namespace std;
class KC
{
	
 public:
	 int ident;
	std::string name;
	int zeh; // кол-во цехов
	int workzeh; // кол-во работающих цех
	double eff;//эффективность 
	static int idK;
	KC();
};


