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
Pipeline LoadPipeline()            //создание трубы
{
	ifstream fin;
	fin.open("data.txt", ios::in);
	Pipeline x;
	x.ident = 0;
	x.remont = false;
	//cout << "type length\n";
	fin >> x.length ;
	//cout << "type diametr\n";
	fin >> x.diametr;
	fin.close();
	return x;
	
}
KC createkc()   //создание компрессорной станции
{
	KC y;
	cout << "type name kc \n"; //????
	cin >> y.name;


	cout << " type number of zeh \n";
	cin >> y.zeh;
	cout << "type number of working zeh\n";
	cin >> y.workzeh;
	y.eff = (y.zeh / y.workzeh) * 100;

	return y;
}
void SavePipeline (const Pipeline& x)
{
	ofstream fout;
	fout.open("data.txt", ios::out );
	fout << x.length << endl
		/*<< "\tDiametr:" */ << x.diametr << endl;
	fout.close();
}
//EditPipeline(Pipeline& x)
//{
//}
int main()
{
	
	Pipeline pipe1 = LoadPipeline();
	KC kc1 = createkc();
	/*EditPipeline(pipe1);*/
	SavePipeline(pipe1);
	return 0;
}

