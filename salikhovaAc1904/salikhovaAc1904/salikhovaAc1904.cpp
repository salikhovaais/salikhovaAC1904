#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Pipeline
{
	double length;
	double diametr;
	bool remont;
	int ident;
	bool haveP;
};
struct KC
{
	int ident;
	string name;
	int zeh; // кол-во цехов
	int workzeh; // кол-во работающих цех
	double eff;//эффективность 
	bool haveKC;
};

 
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
		x.haveP = true;
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
			cin>> x.diametr;
		} while (cin.fail() || isNumber(x.diametr));
	
		return x;
	}


KC inputkc()   //создание компрессорной станции пробел
{
	KC y;
	y.ident = 0;
	y.haveKC = true;
	cout << "type name kc \n";
	getline(cin, y.name); 
	cin >> y.name;
	cout << " type number of workshop \n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type a numeric value: ";
		cin >> y.zeh ;
	} while (cin.fail()|| isNumber(y.zeh ));
	
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
		y.eff= (Getcorrectnumber(1,10));
	} while (cin.fail() || isNumber(y.eff));
	return y;
}


Pipeline LoadPipeline()            //загрузка из файла   
{
	ifstream fin;
	fin.open("Pipeline.txt", ios::in);
	if (fin.is_open())
	{
		Pipeline x;
		x.ident = 0;
		fin >> x.remont;
		fin >> x.length;
		fin >> x.diametr;
		fin.close();
		return x;
	}
	
}
KC LoadKC()
{
	ifstream fin;
	fin.open("KC.txt", ios::in);
	if (fin.is_open())
	{
		KC y;
		y.ident = 0;
		fin >> y.name;
		fin >> y.zeh;
		fin >> y.workzeh;
		fin >> y.eff;
		fin.close();
		return y;
	}
	else { cout << "file not founded"; }

}

void PrintAll(const Pipeline & x, const KC & y) // показать все
	{
	cout << "\tPipe identification:" << x.ident << endl << "length:" << x.length << endl << "diametr:" << x.diametr << endl
			<< "remont:" << x.remont << endl
			<< "\tKC name:" << y.name << endl << "identification:" << y.ident << endl
			<< "number of workshop:" << y.zeh << endl << "number of operating workshops:" << y.workzeh << endl
			<< "efficiency:" << y.eff << endl;
	}
void PrintPipeline (const Pipeline & x) // показать p
	{
	cout << "\tPipe identification:" << x.ident << endl << "length:" << x.length << endl << "diametr:" << x.diametr << endl
			<< "remont:" << x.remont << endl;
	}


void PrintKC  (const KC& y)
{cout << "\tKC name:" << y.name << endl << "identification:" << y.ident << endl
<< "number of workshop:" << y.zeh << endl << "number of operating workshops:" << y.workzeh << endl
<< "efficiency:" << y.eff << endl;
}

void SavePipeline(const Pipeline& x) // сохр в файл трубу
{
	ofstream fout;
	fout.open("pipe.txt", ios::out );
	if (fout.is_open())
	{
		fout << x.length << endl
			<< x.diametr << endl
			<< x.ident << endl
			<< x.remont << endl;
		fout.close();
	}
}

void SaveKC(const KC& y)
{
	ofstream fout;
	fout.open("KC.txt", ios::out);
	if (fout.is_open())
	{
		fout << y.ident << endl
			<< y.name << endl
			<< y.zeh << endl
			<< y.workzeh << endl
			<< y.eff << endl;
		fout.close();
	}
}
void Saveall(const Pipeline& x, const KC& y)
{
	ofstream fout;
	fout.open("ALL.txt", ios::out);
	if (fout.is_open())
	{
		fout << "Pipeline:"<< endl
			<< x.ident << endl 
			<< x.length << endl
			<< x.diametr << endl
			<< x.remont << endl
		     << "KC:" << endl
			<< y.ident << endl
			<< y.name << endl
			<< y.zeh << endl
			<< y.workzeh << endl
			<< y.eff << endl;
		fout.close();
	}
}
void Save(const Pipeline& p,const KC& kc)
{
	cout << "choose what to save 1.pipeline \t2.kc  \t3.all";
	int a;
	a = Getcorrectnumber(1, 3);
	switch (a)
	{
		
	case 1:
		SavePipeline(p);
		break;
	case 2:
		SaveKC(kc);
		break;
	case 3:
		Saveall(p, kc);
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

void PrintMenu()
{
	cout << "1. input pipeline" << endl
		<< "2. input KC" << endl
		<< "3. view all " << endl
		
		<< "4. edit pipeline" << endl
		<< "5. edit KC" << endl

		<< "6. save to file" << endl
		<< "7. load from file" << endl
		<< "0. exit" << endl
		<< "choose action" << endl;

}

int main()
{
	Pipeline p;
	KC k;

	bool haveP = 0;
	bool haveKC = 0;

	while (1)
	{
		PrintMenu();

		switch (Getcorrectnumber(0, 7))
		{
		case 1:
		{
			p = inputPipeline();
			haveP = true;
			break;
		}
		case 2:
		{
			k = inputkc();
			haveKC = true;
			break;
		}
		case 3:
		{  if (haveP == true && haveKC == true)
		{
			cout << "choose what to show  1.pipeline \t2.kc  \t3.all";
			int a;
			a = Getcorrectnumber(1, 3);
			switch (a)
			{

			case 1:
				PrintPipeline(p);
				break;
			case 2:
				PrintKC(k);
				break;
			case 3:
				PrintAll(p, k);
				break;
			}
		}
		else { cout << "there are not data, please enter them in action 1 and 2"; }

		}


		case 4:
		{ if (haveP == true && haveKC == true) {
			Editpipeline(p);
			break;
		}
		else { cout << "there are not data, please enter them in action 1 and 2"; }
		}
		case 5:
		{if (haveP == true && haveKC == true) {
			EditKC(k);
			break;
		}
		else { cout << "there are not data, please enter them in action 1 and 2"; }

		}
		case 6:
		{if (haveP == true && haveKC == true) {
			cout << "choose what to save 1.pipeline \t2.kc  \t3.all";
			int a;
			a = Getcorrectnumber(1, 3);
			Save(p, k);
			break;
		}
		else { cout << "there are not data, please enter them in action 1 and 2"; }
		}
		case 7:
		{
			PrintAll(LoadPipeline(), LoadKC());
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


