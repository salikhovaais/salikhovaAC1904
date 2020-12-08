#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pipeline.h"
#include "KC.h"
using namespace std;
//struct Pipeline
//{
//	double length;
//	double diametr;
//	bool remont;
//	int ident;
//	bool havep;
//};
//struct KC
//{
//	int ident;
//	string name;
//	int zeh; // кол-во цехов
//	int workzeh; // кол-во работающих цех
//	double eff;//эффективность 
//	bool havekc;
//};

bool isNumber(char Symbol)           //проверка цифра или нет 
{
	if (Symbol >= '0' && Symbol <= '9')
		return true;
	return false;
}

template <typename T>
T Getcorrectnumber(T min, T max)//проверка на введение нужной цифры 
{
	int x;
	while ((cin >> x).fail() || x<min || x> max)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type number (" << min << "-" << max << "):";
	}
	return x;
}
Pipeline inputPipeline()            //создание трубы
{
	Pipeline x;
	x.ident = 0;
	x.remont = false;

	cout << "type the length (m)\n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "type a numeric value: ";
		cin >> x.length;
	} while (cin.fail() || isNumber(x.length));
	cout << "type the diameter (mm) \n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "type a numeric value: ";
		cin >> x.diametr;
	} while (cin.fail() || isNumber(x.diametr));

	return x;
}
KC inputkc()   //создание компрессорной станции пробел
{
	KC y;
	y.ident = 0;
	cout << "type name kc \n";
	cin >> y.name;
	cout << " type number of workshop \n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type a numeric value: ";
		cin >> y.zeh;
	} while (cin.fail() || isNumber(y.zeh));

	cout << "type number of working workshops\n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type a numeric value: ";
		y.workzeh = (Getcorrectnumber(1, y.zeh));
	} while (cin.fail() || isNumber(y.workzeh));
	cout << "type efficiency  of  workshops (1-10)\n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type a numeric value: ";
		y.eff = (Getcorrectnumber(1, 10));
	} while (cin.fail() || isNumber(y.eff));
	return y;
}
void PrintPipeline(vector<Pipeline>& pv)
{
	for (Pipeline x : pv)
	cout << "\tPipe identification:" << x.ident << endl
		<< "length:" << x.length << endl
		<< "diametr:" << x.diametr << endl
		<< "remont:" << checkRemont(x);

}
void PrintKC(vector<KC>& kv)
{
	for (KC y : kv)
	cout << "\tKC name:" << y.name << endl 
		<< "identification:" << y.ident << endl
		<< "number of workshop:" << y.zeh << endl
		<< "number of operating workshops:" << y.workzeh << endl
		<< "efficiency:" << y.eff << endl;
}
void PrintAll(vector<Pipeline> pv, vector<KC> kv) // показать все
{
	int a;
	a = Getcorrectnumber(1, 2);
	switch (a)
	{
	case 1:
		PrintPipeline(pv);
		break;
	case 2:
		PrintKC(kv);
		break;
	}
}
void LoadPipeline(vector<Pipeline>& pv)            //загрузка из файла   
{
	ifstream fin;
	fin.open("data.txt", ios::in);
	fin.open("Pipeline.txt", ios::in);
	if (fin.is_open())
	{
		int lp;
		fin >> lp;
		pv.resize(lp);

		for (Pipeline& x : pv)
		{

			fin >> x.remont;
			fin >> x.ident;
			fin >> x.length;
			fin >> x.diametr;
			fin.close();

		}

	}
}
void LoadKC(vector<KC>& kv)
{
	ifstream fin;
	fin.open("KC.txt", ios::in);
	if (fin.is_open())
	{
		int lk;
		fin >> lk;
		kv.resize(lk);
		for (KC& y : kv)
		{
			y.ident = 0;
			fin >> y.name;
			fin >> y.zeh;
			fin >> y.workzeh;
			fin >> y.eff;

			fin.close();
		}
	}
}


void LoadAll(vector<Pipeline>& pv, vector<KC>& kv)
{
	
	
		switch (Getcorrectnumber(1, 3))
		{
		case 1:
			LoadPipeline(pv);
			break;
		case 2:
			LoadKC(kv);
			break;

		case 3:
			LoadAll(pv, kv);
			break;
		}
}
	
	

void SavePipeline(vector<Pipeline>& pv) // сохр в файл трубу
{
	ofstream fout;
	fout.open("pipe.txt", ios::out);
	if (fout.is_open())
	{
		fout << pv.size() << endl;
		if (pv.size() != 0)
		{
			for (const Pipeline& x : pv)
			{
				fout << x.ident << endl 
					<< x.diametr << endl
					<< x.length << endl
					<< x.remont << endl 
					<< endl;
				fout.close();
			}
		}

	}
}

void SaveKC(vector<KC>& kv)
{
	ofstream fout;
	fout.open("KC.txt", ios::out);
	if (fout.is_open())
	{
		fout << kv.size() << endl;
		if (kv.size() != 0)
		{
			for (const KC& y : kv)
			{
				fout << y.ident << endl
					<< y.name << endl
					<< y.zeh << endl
					<< y.workzeh << endl
					<< y.eff << endl;
				fout.close();
			}
		}
	}
}
void Saveall(vector<Pipeline>& pv, vector<KC>& kv)
{
	ofstream fout;
	fout.open("ALL.txt", ios::out);
	if (fout.is_open())
		fout << pv.size() << endl;
	fout << kv.size() << endl;
	fout << endl;

	if (pv.size() != 0 ||kv.size() != 0)
	{
		for (const Pipeline& x : pv)
		{
			fout << "Pipeline:" << endl 
				<< x.ident << endl
				<< x.diametr << endl
				<< x.length << endl
				<< x.remont << endl
				<< endl;
		}
		for (const KC& y : kv)
		{
			fout 
				<< "KC:" << endl 
				<< y.ident << endl
			<< y.name << endl
			<< y.zeh << endl
			<< y.workzeh << endl
			<< y.eff << endl;
		}
	
	}
	fout.close();
}

void Save(int a, vector<Pipeline>& pv, vector<KC>& kv)
{
	switch (a)
	{
	case 1:
		SavePipeline(pv);
		break;
	case 2:
		SaveKC(kv);
		break;
	case 3:
		Saveall(pv, kv);
		break;
	}
}
KC  EditKC(KC& y)

{   
	cout << "press 1 to add the operating workshop";
	cout << "\npress 2 to remove the operating workshop  ";
	int  k;
	k= Getcorrectnumber(1,2);
	if (k==1)
	{
		y.workzeh += 1;
	}
	else
	{
		y.workzeh -= 1;
	}
	return y;
}

void Editpipeline(Pipeline& x)
{
	if (x.remont == 1) {
		cout << "\nnow the pipeline is  in repair\n";
	}
	else {
		x.remont = 0;
		cout << "\nnow the pipeline is  not in repair\n";
	}
}
string checkRemont(Pipeline& p)//rename and class
{
	return (p.remont) ? "Unworking \n\n" : "Working \n\n";
}
template<typename C>
ostream& operator << (ostream& out, const vector<C>& object)// вектор 
{
	for (const C& i : object)
	{
		out << i;
	}
	return out;
}
template<typename C>
ofstream& operator << (ofstream& fout, const vector<C>& object)
{
	for (const C& c : object)
	{
		fout << c;
	}
	return fout;
}
template <typename C>
ifstream& operator >> (ifstream& in, vector<C>& object)
{
	for (C& c : object)
	{
		in >> c;
	}
	return in;
}
void PrintMenu()
{
	cout << "1. input pipeline" << endl
		<< "2. input KC" << endl
		<< "3. view  " << endl
		
		<< "4. edit pipeline" << endl
		<< "5. edit KC" << endl

		<< "6. save to file" << endl
		<< "7. load from file" << endl
		<< "0. exit" << endl
		<< "choose action" << endl;

}

int main()
{
	
	
	vector <Pipeline> pv;
	vector <KC> kv;
	
	while (1)
	{
		PrintMenu();

		switch (Getcorrectnumber(0, 7))
		{
		case 1:
		{
			Pipeline p;
			p = inputPipeline();
		
			break;
		}
		case 2:
		{
			KC k;
			k = inputkc();
			
			break;
		}
		case 3:
		
		{
				cout << " choose what to show  1-pipe, 2- KC ";
				int a = 0;
				cin >> a;
				PrintAll( pv, kv);
				break;
		}
		



		case 4: 
		
		{
			Editpipeline(pv);
			break;
		}
		
		

		case 5:
		
		{
			EditKC(kv);
			break;
		}
	
		case 6:
			
		{
			cout << "choose what to save 1.pipeline \t2.kc  \t3.all";
			int a;
			a = Getcorrectnumber(1, 3);
			Save(a,pv, kv);
			break;
		}
		case 7:
		{
			LoadAll(pv, kv);
			break;
		}
		case 0:
		{
			return 0;

		}
		default:
		{cout << "wrong action" << endl; }
		}
			}

			return 0;
		}
		
