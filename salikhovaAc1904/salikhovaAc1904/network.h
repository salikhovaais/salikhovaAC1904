#pragma once
#include "Pipeline.h"
#include "KC.h"
#include"Utilus.h"
#include <set>
#include <iostream>
#include <fstream>





class network
{
private:
	vector<vector<int>> matrix;
	set<int> idks;
	set<int> idt;
public:
	void editnetwork(unordered_map<int, Pipeline>& pv);
	void savefilenetwork(std::ofstream& fout);
	int inputfilenetwork(std::ifstream& fin);
	vector<vector<int>> creatematrix(int n);
	void deletematrix(int n);
	void editmatrix(unordered_map<int, Pipeline>& pv);
	vector<unsigned int> tgtssort(unordered_map<int, Pipeline>& pv);
	void deleteidks(int value);
	int findindex(vector<unsigned int> v, int value);
	float countpotok(unordered_map<int, Pipeline>& pv, unordered_map<int, KC> kv, int istok, int stok);
	float maxpotok(unordered_map<int, Pipeline >& pv, unordered_map<int, KC>& kv);
	float countpyt(unordered_map<int, Pipeline>& pv, unordered_map<int, KC>& kv, int istok, int stok);
	float minpyt(unordered_map<int, Pipeline>& pv, unordered_map<int, KC>& kv);
	void editmatrixformaxpotok(unordered_map<int, Pipeline>& pv);
	void editmatrixforminpyt(unordered_map<int, Pipeline>& pv);
	set<int> getidks();
	set<int> getidt();
	void setidks(int value);
	void setidt(int value);

};

