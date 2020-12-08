#pragma once
#include <iostream>
#include <string>

class Pipeline
{
public:
	double length;
	double diametr;
	bool remont;
	int ident;
	static int idP;
	Pipeline();
};





//
//	int id;
//	static int CountP;
//	float diametr, length;
//	bool repair = false;
//	friend std::string checkRepair(const CPipe& p);
//	CPipe();
//};