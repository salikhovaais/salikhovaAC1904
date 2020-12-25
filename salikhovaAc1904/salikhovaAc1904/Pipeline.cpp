#include "Pipeline.h"
#include <iostream>
#include <string>
#include "Utilus.h"
#include <unordered_map>
using namespace std;

int Pipeline::idP = 0;



int Pipeline::GetidP()
{
	return idP;
}
int Pipeline::getID() const
{
	return ident;
}
void Pipeline::setinputks(unsigned int value)
{
	inputks = value;
}

void Pipeline::setoutputks(unsigned int value)
{
	outputks = value;
}

unsigned int Pipeline::getinputks()
{
	return inputks;
}

unsigned int Pipeline::getoutputks()
{
	return outputks;
}
int Pipeline::getproizv()
{
	return proizv;
}



istream& operator>>(istream& in, Pipeline& x) //создание pipiline
{
	x.ident = ++Pipeline::idP;
	std::cout << " enter the length(in m):\n";
	x.length = Getcorrectnumber(0, 1000);
	std::cout << "enter the diameter(in mm): ";
	x.diametr = Getcorrectnumber(1, 1000);
	(x.remont) ? cout << "the pipe is under repair\n" : cout << "the pipe works\n";
	x.proizv = sqrt(pow(x.diametr, 5 / x.length)) * 10;
	return in;
}

ostream& operator <<(ostream& out, const Pipeline& x)
{
	out << "\tpipelines:\n";
	out << "the ID of the pipeline: " << x.ident << endl;
	out << "the length: " << x.length << endl;
	out << "the diametr: " << x.diametr << endl;
	(x.remont) ? out << "pipeline is unworking\n" : out << " pipeline is working\n"; 
	out << "capacity: " << x.proizv << endl; 
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
	return (p.remont) ? "unworking \n\n" : "working \n\n";
}
void Pipeline::RedaktPipeline()
{
	remont = !remont;
	cout << "the pipe's status is changed";
}
bool Pipeline::getremont() 
{
	return remont;
}
void Pipeline::inputfilepipe(std::ifstream& fin) // Считывание информации о трубе
{
	fin >> ident;
	fin >> inputks;
	fin >> outputks;
	fin >> length;
	fin >> diametr;
	fin >> remont;

}
void Pipeline::savefilepipe(std::ofstream& fout) // Сохранение информации о трубе
{
	fout << ident << endl;
	fout << inputks << endl;
	fout << outputks << endl;
	fout << length << endl;
	fout << diametr << endl;
	fout << remont << endl;
}