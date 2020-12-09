#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pipeline.h"
#include "KC.h"
using namespace std;


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

std:: string checkRemont(Pipeline& p)//rename and class
{
	return (p.remont) ? "Unworking \n\n" : "Working \n\n";
}
std::istream& operator>>(std::istream& in, KC& y)
{
	
	std::cout << "type name kc \n";
	 cin.ignore();
	getline(cin, y.name);
	std::cout << " type number of zeh \n";
 y.zeh = Getcorrectnumber(0,1000);
	std::cout << "type number of working zeh\n";
		y.workzeh = (Getcorrectnumber(1, y.zeh));
	std::cout << "type efficiency  of  workzeh (1-10)\n";
		y.eff = (Getcorrectnumber(1, 10));
	return in;
}
std::istream& operator>>(std::istream& in, Pipeline& x) //создание трубы
{
	x.remont = false;
	std::cout << "type the length (m)\n";
	x.length = Getcorrectnumber<double>(0, 1000);
	std::cout << "type the diameter (mm) \n";
	x.diametr = Getcorrectnumber<double>(0, 10000);
	return in;
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
vector<KC> EditAllKC(vector<KC>& kv)
{
	cout << "\n0. Start the workshop\n1. Stop the workshop\nSelect - ";
	int choice = Getcorrectnumber(0, 1);
	cout << endl;
	for (KC& i : kv)
	{
		if (choice == 0 && (i.zeh > i.workzeh))
		{
			i.workzeh += 1;
		}
		else if (i.workzeh > 0)
		{
			i.workzeh -= 1;
		}
	}
	return kv;
}
vector<KC> EditOneKC(vector<KC>& kv)
{
	cout << "id of the KC you want to edit: ";
	int k;
	cin >> k;
	cout << "\n0. start the working zeh\n1. stop the working zeh\nSelect - ";
	if (Getcorrectnumber(0, 1) == 0)
	{
		if (kv[k].zeh > kv[k].workzeh)
			kv[k].workzeh += 1;
	}
	else
	{
		if (kv[k].workzeh > 0)
			kv[k].workzeh -= 1;
	}
	return kv;
}
void EditKC(vector<KC>& kv)
{
	cout << "choose\n1. edit all KC\n2. edit one KC\n";
	if (Getcorrectnumber(1, 2) == 1)
	{
		cout << endl;
		EditAllKC(kv);
	}
	else
	{
		cout << endl;
		EditOneKC(kv);
	}
}
void EditAllPipeline(vector<Pipeline>& pv)
{
	cout << "choose\n0. pipelines working\n1. pipelines  repairing\n";
	int choice = Getcorrectnumber(0, 1);
	cout << endl;
	for (Pipeline& i : pv)
	{
		i.remont = choice;
	}
}
vector<Pipeline> EditOnePipeline(vector<Pipeline>& pv)
{
	cout << "type id you want to edit: ";
	int n;
	cin >> n;
	cout << "0. pipe working\n1. pipe in repairing\nChoose - ";
	int choice = Getcorrectnumber(0, 1);
	pv[n].remont = choice;
	cout << endl;
	return pv;
}
void Editpipeline(vector<Pipeline>& pv)
{  
	cout << "1. Edit all existing pipelines\n2. Edit one pipeline\nSelect - ";
	if (Getcorrectnumber(1, 2) == 1)
	{
		cout << endl;
		EditAllPipeline(pv);
	}
	else
	{
		cout << endl;
		EditOnePipeline(pv);
	}
}

bool SearchById(Pipeline& p, int param)
{
	return p.ident == param;
}
bool SearchByRepair(Pipeline& p, int param)
{
	return p.remont == param - 1;
}
bool SearchByName(KC& k, string name)
{
	return k.name == name;
}
bool SearchByPercent(KC& cs, int param)
{
	return 100 * (1 - (1. * cs.workzeh) / cs.zeh) >= param;
}
template <typename N>
void infoByFilterPipeline(vector<Pipeline>& vect, bool(*f)(Pipeline& p, N param), N param)
{
	for (Pipeline& i : vect)
	{
		if (f(i, param))
		{
			cout << endl << "Pipe id: "
				<< i.ident << endl 
				<< "diametr: " << i.diametr << endl
				<< "length: " << i.length <<endl 
				<< "pipe condition: " << checkRemont(i);
		}
	}
	cout << endl;
}
template <typename N>
void infoByFilterKC(vector<KC>& vect, bool(*f)(KC& p, N param), N param)
{
	for (KC& i : vect)
	{
		if (f(i, param))
		{
			/*cout.precision(2);*/
			cout << "\nKC id: " << i.ident << endl 
				<< "name: " << i.name << endl
				<< "quantity of zeh: " << i.zeh << endl
				<< "quantity of working zeh: " << i.workzeh << endl
				<< "efficiency: " << i.eff << endl
				<< endl;
		}
	}
	cout << endl;
}
void SearchByFilterPipeline(vector<Pipeline>& pipes)
{
	cout << "\nchoose by what\n1.ID\n2.condition\n ";
	if (Getcorrectnumber(1, 2) == 1)
	{
		cout << "Enter ID: ";
		int ch = Getcorrectnumber(0, 100);
		infoByFilterPipeline(pipes, SearchById, ch);
	}
	else
	{
		cout << "\n1. Working\n2. Unworking\nSelect action - ";
		int choice = Getcorrectnumber(1, 2);
		infoByFilterPipeline(pipes, SearchByRepair, choice);
	}
}
void SearchByFilterKC(vector<KC>& kv)
{
	cout << "\nchoose by what\n1.name\n" << "2.percentage of unused workzeh";
	if (Getcorrectnumber(1, 2) == 1)
	{
		int counter = 0;
		cout << "\ntype a name : ";
		string name;
		cin >> name;
		infoByFilterKC(kv, SearchByName, name);
	}
	else
	{
		cout << "\ntype the number of percentages - ";
		int choice = Getcorrectnumber(0, 100);
		infoByFilterKC(kv, SearchByPercent, choice);
	}
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
		<< "8. search by filter " << endl
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

		switch (Getcorrectnumber(0, 8))
		{
		case 1:
		{
			Pipeline p;
			cin >> p ;
			pv.push_back(p);
			break;
		}
		case 2:
		{
			KC k;
			cin >> k;
			kv.push_back(k);
			break;
		}
		case 3:
		
		{
				cout << " choose what to show  1-pipe, 2- KC ";
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
		case 8:
		{
			cout << "choose number to search by\n1.pipelines\n2.KC";
			if (Getcorrectnumber(1, 2) == 1)
				SearchByFilterPipeline(pv);
			else
				SearchByFilterKC(kv);
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
		
