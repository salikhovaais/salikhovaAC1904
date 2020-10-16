#include <iostream>
#include <fstream>
using namespace std;
struct Pipeline
{
	int length;
	int diametr;
	bool remont;
	int ident;
};
struct KC
{
	int ident;
	string name;
	int zeh;
	int workzeh;
	string eff;
};
Pipeline createpipe()            //создание трубы
{
	Pipeline x;
	ifstream fin;
	fin.open("pipe.txt", 'r');

	cout << "введите длину  трубы\n";
	cin >> x.length ;
	cout << "введите диаметр трубы\n";
	cin >> x.diametr;
	x.ident = 0;
	x.remont = false;
	return x;
	
}
KC createkc()   //создание компрессорной станции
{
	KC y;
	cout << "введите название уомпрессорной станции \n"; //????
	cin >> y.name;


	cout << "введите количество цехов \n";
	cin >> y.zeh;
	cout << "введите количество цехов в работе\n";
	cin >> y.workzeh;
	y.eff = (y.zeh / y.workzeh) * 100;

	return y;
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

