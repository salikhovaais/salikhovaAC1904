#include "Pipeline.h"
#include <iostream>
#include <string>
#include "Header.h"
#include <vector>
using namespace std;
vector <Pipeline> group;
int Pipeline::idP = 0;

Pipeline::Pipeline()
{
	ident = idP++;
}
istream& operator>>(istream& in, Pipeline& x) //создание трубы
{
	x.remont = false;
	std::cout << "type the length (m)\n";
	x.length = Getcorrectnumber(0, 1000);
	std::cout << "type the diameter (mm) \n";
	x.diametr = Getcorrectnumber(0, 10000);
	return in;
}


ostream& operator <<(ostream& out, const Pipeline& x)
{
	out << "\tpipelines:\n";
	out << "the ID of the pipeline: " << x.ident << endl;
	out << "the length: " << x.length << endl;
	out << "the diametr: " << x.diametr << endl;
	(x.remont) ? out << "pipeline is unworking\n" : out << " pipeline is working\n"; 
	return out;
}
ifstream& operator>>(ifstream& fin, Pipeline& x)
{
	fin >> x.ident >> x.length >> x.diametr >> x.remont;
	return fin;
}
ofstream& operator<<(std::ofstream& fout, const Pipeline& x)
{
	fout << x.ident<< endl << x.length << endl << x.diametr << endl << x.remont << endl;
	return fout;
}
std::string checkRemont(const Pipeline& p)
{
	return (p.remont) ? "Unworking \n\n" : "Working \n\n";
}