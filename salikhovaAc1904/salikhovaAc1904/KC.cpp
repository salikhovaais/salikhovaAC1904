#include "KC.h"
#include "Header.h"
#include <vector>
using namespace std;
int KC::idK = 0;//уникальная идентификация станций
KC::KC()
{
	ident= idK;
	idK++;
}
std::istream& operator>>(std::istream& in, KC& y)
{
	std::cout << "type name kc \n";
	cin.ignore();
	getline(cin, y.name);
	std::cout << " type number of zeh \n";
	y.zeh = Getcorrectnumber(0, 1000);
	std::cout << "type number of working zeh\n";
	y.workzeh = (Getcorrectnumber(1, y.zeh));
	std::cout << "type efficiency  of  workzeh (1-10)\n";
	y.eff = (Getcorrectnumber(1, 10));
	return in;
}
istream& operator>>(istream& in, KC& y) //создание трубы
{
	std::cout << "type name kc \n";
	cin.ignore();
	getline(cin, y.name);
	std::cout << " type number of zeh \n";
	y.zeh = Getcorrectnumber(0, 1000);
	std::cout << "type number of working zeh\n";
	y.workzeh = (Getcorrectnumber(1, y.zeh));
	std::cout << "type efficiency  of  workzeh (1-10)\n";
	y.eff = (Getcorrectnumber(1, 10));
	return in;
}


ostream& operator <<(ostream& out, const KC& y)
{
	out << "\tKC\n";
	out << "the ID of the KC: " << y.ident << endl
	 << "uantity of zeh: " << y.zeh << endl
		<< "quantity of working zeh: " << y.workzeh << endl
	 << "efficiency: : " << y.eff<< endl;
	return out;
}
ifstream& operator>>(ifstream& fin, KC& y)
{
	fin >> y.ident >> y.zeh >> y.workzeh >> y.eff;
	return fin;
}
ofstream& operator<<(std::ofstream& fout, const KC& y)
{
	fout << y.ident << endl
		<< y.zeh << endl 
		<< y.workzeh << endl
		<< y.eff << endl;
	return fout;
}