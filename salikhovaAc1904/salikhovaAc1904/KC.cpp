#include "KC.h"
#include "Utilus.h"
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int KC::idK = 0;//уникальна€ идентификаци€ станций
static int idK;

int KC::GetidK()
{
	return idK;
}

int KC::getID() const
{
	return ident;
}

istream& operator>>(istream& in, KC& y) //создание KC
{
	y.ident = ++KC::idK;
	std::cout << "type name kc \n";
	cin.ignore();
	getline(cin, y.name);
	std::cout << " type number of zeh \n";
	y.zeh = Getcorrectnumber(0, 1000);
	std::cout << "type number of working zeh\n";
	y.workzeh = Getcorrectnumber(1, y.zeh);
	std::cout << "type efficiency  of  workzeh (1-10)\n";
	y.eff = Getcorrectnumber(1, 10);
	return in;
}


ostream& operator <<(ostream& out, const KC& y)
{
	out << "\tKC\n";
	out << "the ID of the KC: " << y.ident << endl
		<< "uantity of zeh: " << y.zeh << endl
		<< "quantity of working zeh: " << y.workzeh << endl
		<< "efficiency: : " << y.eff << endl;
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

void KC::RedaktKC()
{
	cout << "do you want to change the number of working zeh?\n";
	char i;
	cin >> i;
	while (i != 'yes' && i != 'no')
	{
		cout << " enter yes or no : ";
		cin >> i;
	}
	switch (i)
	{
	case 'yes':
	{
		cout << "enter the number of working zeh: ";
		int vsego = zeh;
		workzeh = Getcorrectnumber(0, vsego);
		cout << "the information is changed \n";
		break;
	}
	case 'no':
	{
		break;
	}
	}
}