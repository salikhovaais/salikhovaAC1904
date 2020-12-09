#pragma once
#include <iostream>
#include <string>

class Pipeline
{
public:
	double length;
	double diametr;
	bool remont = false;
	int ident;
	static int idP;
	friend std::string checkRemont(const Pipeline& p);
	Pipeline();
};

