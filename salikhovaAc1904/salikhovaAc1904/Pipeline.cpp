#include "Pipeline.h"
#include <iostream>
#include <string>
#include "Utilus.h"
#include <unordered_map>
using namespace std;

int Pipeline::idP = 0;

Pipeline::Pipeline()
{
	ident = idP++;
}

int Pipeline::getID() const
{
	return ident;
}

istream& operator>>(istream& in, Pipeline& x) //создание pipiline
{
	
	std::cout << " enter the length(in m):\n";
	x.length = Getcorrectnumber(0, 1000);
	std::cout << "enter the diameter(in mm): ";
	x.diametr = Getcorrectnumber(1, 1000);
	(x.remont) ? cout << "the pipe is under repair\n" : cout << "the pipe works\n";
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
void Pipeline::RedaktPipeline()
{
	remont = !remont;
	cout << "the pipe's status is changed";
}