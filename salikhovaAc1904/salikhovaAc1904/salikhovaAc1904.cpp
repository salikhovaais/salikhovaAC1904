#include <iostream>

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
Pipeline createPipeline()            //создание трубы
{
	Pipeline x;
	//ifstream fin;
	//fin.open("pipe.txt", 'r');

	cout << "введите длину  трубы";
	cin >> x.length ;
	cout << "введите диаметр трубы";
	cin >> x.diametr;
	x.ident = 0;
	x.remont = false;
	return x;
	
}
KC createkc()   //создание компрессорной станции
{
	KC y;
	cout << "введите название компрессорной станции \n"; //????
	cin >> y.name;


	cout << "введите общее количество цехов \n";
	cin >> y.zeh;
	cout << "введите количество цехов в работе\n";
	cin >> y.workzeh;
	y.eff = (y.zeh / y.workzeh) * 100;

	return y;
}

////void savepipe(Pipeline& x)  
//{
//	ofstream fout;
//	fout.open("data.txt" );
//	fout << "length" << x.length
//		<< "\tdiametr" << x.diametr
//		<< "\tident" << x.ident;

int main()
{
	
	Pipeline pipe1 = createPipeline();
	
	
	return 0;
}

