#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class KC
{
	int ident;
	static int idK;
 public:
	 
	std::string name;
	int zeh; // кол-во цехов
	int workzeh; // кол-во работающих цех
	double eff;//эффективность 
	
	KC();
	friend std::ostream& operator<<(std::ostream& out, const KC& x);
	friend std::istream& operator >>(std::istream& in, KC& x);
	friend std::ofstream& operator << (std::ofstream& fout, const KC& x);
	friend std::ifstream& operator >> (std::ifstream& fin, KC& x);
};


