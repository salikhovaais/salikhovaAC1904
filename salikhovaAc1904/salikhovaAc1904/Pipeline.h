#pragma once
#include <iostream>
#include <string>
#include <fstream>
class Pipeline
{
private:
	static int idP;
	int ident;
public:
	double length = 0;
	double diametr= 0;
	bool remont = false;
	Pipeline();
	

	//void LoadPipeline(vector<Pipeline>& pv)
	
	friend std::ostream& operator<<(std::ostream& out, const Pipeline& x);
	friend std::istream& operator >>(std::istream& in, Pipeline& x);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipeline& x);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipeline& x);

}; 