#pragma once
#include <iostream>
#include <string>

class Pipeline
{
private:
	static int idP;
	int ident;
public:
	double length;
	double diametr;
	bool remont = false;
	Pipeline();


	//void LoadPipeline(vector<Pipeline>& pv)
	string  checkRemont(const Pipeline& p)//rename and class
	{
		return (p.remont) ? "Unworking \n\n" : "Working \n\n";

	}
	friend std::ostream& operator<<(std::ostream& out, const Pipeline& x);
	friend std::istream& operator >>(std::istream& in, Pipeline& x);
};