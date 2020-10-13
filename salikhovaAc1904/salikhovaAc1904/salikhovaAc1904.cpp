#include <iostream>
#include <fstream>
using namespace std;
struct Pipeline
{
	int dlina;
	int diametr;
	bool remont;
	int ident;
};
struct KC
{
	int ident;
	string name;
	int kolvo;
	int zeh;
	int rabzeh;
	string effect;
};
Pipeline createpipe(string name) {
	Pipeline x;
	ifstream fin;
	fin.open("pipe.txt", 'r');

	cout << "введите длину  трубы\n";
	cin >> x.dlina ;
	cout << "введите диаметр трубы\n";
	cin >> x.diametr;
	
}

void savepipe(Pipeline& x)  
{
	ofstream fout;
	fout.open("data.txt" );
	fout << "dlina" << x.dlina
		<< "\tdiametr" << x.diametr
		<< "\tident" << x.ident;
}
int main()
{
	
	Pipeline pipe1;
	createpipe(pipe1);
	savepipe(pipe1);
	return 0;
}

