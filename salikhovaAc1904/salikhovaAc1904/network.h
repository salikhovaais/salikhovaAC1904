#pragma once
#include "Pipeline.h"
#include "KC.h"
#include"Utilus.h"
#include <set>
#include <iostream>
#include <fstream>



#pragma once

class network
{
private:
	int** matrix;
	set<int> idks;
	set<int> idt;
public:
	void editnetwork(unordered_map<int, Pipeline>& Truboprovod);
	void savefilenetwork(std::ofstream& fout);
	int inputfilenetwork(std::ifstream& fin);
	int** creatematrix(int n);
	void deletematrix(int n);
	void editmatrix(unordered_map<int, Pipeline>& Truboprovod);
	vector<unsigned int> tgtssort(unordered_map<int, Pipeline>& Truboprovod);
	void deleteidks(int value);
	set<int> getidks();
	set<int> getidt();
	void setidks(int value);
	void setidt(int value);

};

