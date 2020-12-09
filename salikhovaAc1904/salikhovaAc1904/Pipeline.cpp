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
	out << "\t*Pipes*\n";
	out << "the ID of the pipe: " << x.ident << endl;
	out << "the length: " << x.length << endl;
	out << "the diameter: " << x.diametr << endl;
	(x.remont) ? out << "the pipe is under repair\n" : out << "the pipe works\n"; 
	return out;
}