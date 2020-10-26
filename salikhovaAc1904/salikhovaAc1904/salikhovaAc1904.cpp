#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Pipeline
{
	float length;
	float diametr;
	bool remont;
	int ident;
};
struct KC
{
	int ident;
	string name;
	int zeh; // кол-во цехов
	int workzeh; // кол-во работающих цехов
	string eff;//эффективность 
};
Pipeline LoadPipeline()            //загрузка в файл  трубы
{
	ifstream fin;
	fin.open("data.txt", ios::in);
	/*if (fin.is_open())*/
	
		Pipeline x;
		x.ident = 0;
		fin >> x.remont;
		//cout << "type length\n";
		fin >> x.length;
		//cout << "type diametr\n";
		fin >> x.diametr;
		fin.close();
		return x;
	
}
void PrintPipe(const Pipeline& x)
{
	cout << "identification:" << x.ident << endl
		<< "length:" << x.length << endl
		<< "diametr:" << x.diametr << endl
		<< "remont:" << x.remont << endl;


}


Pipeline inputPipeline()            //создание трубы
{
		Pipeline x;
		x.ident = 0;
		x.remont = false;
		cout << "type the length (2000-8000)\n";
		cin >> x.length;
		cout << "type the diametr(60-140)\n";
		cin >> x.diametr;
		/*do 
		{
			cin.clear();
			cin.ignore(10000, '/n');
			cout << "type diametr(60-140)\n";
			cin >> x.diametr;
		}while (cin.fail()|| x.diametr < 60 || x.diametr > 140);*/
		return x;
	}
//bool IsDcorrect(double d)
//{
//	return d >= 60 && d <= 140;
//}

KC inputkc()   //создание компрессорной станции
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
void SavePipeline(const Pipeline& x)
{
	ofstream fout;
	fout.open("data.txt", ios::out );
	if (fout.is_open())
	{
		fout << x.length << endl
			/*<< "\tDiametr:" */
			<< x.diametr << endl
			<< x.ident << endl
			<< x.remont << endl;
		fout.close();
	}
}
void EditPipeline(Pipeline& x)
{
	x.diametr -= 1;
	/*x.diametr = IsDcorrect(x.diametr) ? x.diametr : 60;*/
}
void PrintMenu()
{
	cout << "1. input pipeline" << endl
		<< "2. print pipeline" << endl
		<< "3. save to file" << endl
		<< "4. load from file" << endl
		<< "5. edit pipeline" << endl
		<< "0. exit" << endl;

}
int main()
{
	Pipeline p1;
	while (1)
	{
		PrintMenu();
		int i = 0;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			p1 = inputPipeline();
			break;
		}
		case 3:
		{
			SavePipeline(p1);
			break;
		}
		case 4:
		{
			p1 = LoadPipeline();
			break;
		}
		case 5:
		{
			EditPipeline(p1);
			break;
		}
		case 0:
		{
			return 0;
			
		}
		default	:
		{cout << "wrong action" << endl; }
		}
	}
	/*Pipeline p1 = LoadPipeline();*/
	KC kc1 = inputkc();
	SavePipeline(p1);
	PrintMenu();
	EditPipeline(p1);
	return 0;
}

