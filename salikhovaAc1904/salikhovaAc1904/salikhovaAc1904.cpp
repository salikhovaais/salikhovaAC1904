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
	int workzeh; // кол-во работающих цех
	int eff;//эффективность 
};

 
bool isNumber(char Symbol)           //проверка цифра или нет , взято из https://pyatnitsev.ru/2011/11/21/isnumber/
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
			cin>> x.diametr;
		} while (cin.fail() || isNumber(x.diametr));
	
		return x;
	}


KC inputkc()   //создание компрессорной станции
{
	KC y;
	y.ident = 0;

	cout << "type name kc \n"; 
	cin >> y.name;



	cout << " type number of zeh \n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type a numeric value: ";
		cin >> y.zeh;
	} while (cin.fail() || isNumber(y.zeh)); 
	
	cout << "type number of working zeh\n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type a numeric value: ";
		y.workzeh = (Getcorrectnumber(1, y.zeh));
	} while (cin.fail() || isNumber(y.workzeh)); 
	cout << "type efficiency  of working zeh (1-10)\n";
	do
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type a numeric value: ";
		y.eff= (Getcorrectnumber(1,10));
	} while (cin.fail() || isNumber(y.eff));

	return y;
}


 Pipeline LoadPipeline()            //загрузка в файл  трубы  
{
	ifstream fin;
	fin.open("data.txt", ios::in);
	/*if (fin.is_open())*/

	Pipeline x;
	x.ident = 0;
	fin >> x.remont;
	fin >> x.length;
	fin >> x.diametr;
	fin.close();
	return x;
}
	
	

KC LoadKC()            //загрузка в файл  KC
{
	ifstream fin;
	fin.open("KC.txt", ios::in);
	/*if (fin.is_open())*/

	KC y;
	y.ident = 0;
	fin >> y.name ;
	fin >> y.zeh;
	fin >> y.workzeh;
	fin >> y.eff;
	fin.close();

	return y;

}
	



void PrintAll(const Pipeline & x, const KC & y)
	{
	cout << "\tPipe identification:" << x.ident << endl << "length:" << x.length << endl << "diametr:" << x.diametr << endl
			<< "remont:" << x.remont << endl
			<< "\tKC name:" << y.name << endl << "identification:" << y.ident << endl
			<< "number of workshops:" << y.zeh << endl << "number of operating workshops:" << y.workzeh << endl
			<< "efficiency:" << y.eff << endl;
	}





void SavePipeline(const Pipeline& x)
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
void Save(int f,const Pipeline& p,const KC& kc)
{
	switch (f)
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
	cin >> k;
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
		x.remont = 0;
		cout << "\nnow the pipeline is not in repair\n";
	}
	else {
		x.remont = 1;
		cout << "\nnow the pipeline is  in repair\n";
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
		<< "0. exit" << endl;

}

int main()
{
Pipeline p1; 
KC k;


	
	while (1)
	{
		PrintMenu();
		
		switch (Getcorrectnumber(0, 7))
		{
		case 1:
		{
			p1 = inputPipeline();
			break;
		}
		case 2:
		{
			k = inputkc();
			break;
		}
		case 3:
		{
			PrintAll(p1, k);
			break;
		}
	     case 4:
		{
			Editpipeline(p1);
			break;
		}
		case 5:
		{
			EditKC(k);
			break;
		}
		case 6:
		{cout << "choose what to save 1.pipeline \t2.kc  \t3.all";
			int a;
			a = Getcorrectnumber(1, 3);
			Save(a,p1, k);
			break;
		}
		case 7:
		{
			LoadPipeline();
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
	
	return 0;
}

