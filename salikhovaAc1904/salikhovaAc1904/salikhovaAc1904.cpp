#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pipeline.h"
#include "KC.h"
#include "Header.h"
using namespace std;


bool isNumber(char Symbol)           //проверка цифра или нет 
{
	if (Symbol >= '0' && Symbol <= '9')
		return true;
	return false;
}

//template <typename T>
//T Getcorrectnumber(T min, T max)//проверка на введение нужной цифры 
//{
//	int x;
//	while ((cin >> x).fail() || x<min || x> max)
//	{
//		cin.clear();
//		cin.ignore(1000, '\n');
//		cout << "Type number (" << min << "-" << max << "):";
//	}
//	return x;
//}

std:: string checkRemont(Pipeline& p)//rename and class
{
	return (p.remont) ? "Unworking \n\n" : "Working \n\n";
}




	







	
	

void SavePipeline(vector <Pipeline> pv)
{
	if (pv.size() != 0)
		cout << "there is no  pipeline\n ";
	else
	{
		ofstream fout;
		fout.open("Pipeline.txt", ios::out);
		if (fout.is_open())
		{
			fout << pv.size() << endl;
			for (const auto& k : pv)
				fout << k;
			fout.close();
		}
	}
}
void SaveAll(vector <Pipeline>& pv, vector <KC>& kv)
{
	if ((pv.size() != 0) and (kv.size() != 0))
		cout << "there is no pipeline and KC\n ";
	else
	{
		ofstream fout;
		fout.open("ALL.txt", ios::out);
		if (fout.is_open())
		{
			fout << pv.size() << endl;
			fout << kv.size() << endl;
			for (const auto& p : pv)
				fout << p;
			for (const auto& k : kv)
				fout << k;
			fout.close();
		}
	}
}
void SaveKC( vector <KC> kv)
{
	if  (kv.size() != 0)
		cout << "there is no  KC\n ";
	else
	{
		ofstream fout;
		fout.open("KC.txt", ios::out);
		if (fout.is_open())
		{
			fout << kv.size() << endl;
			for (const auto& k : kv)
				fout << k;
			fout.close();
		}
	}
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
		SaveAll(pv, kv);
		break;
	}
}
void LoadAll(vector <Pipeline>& pv, vector <KC>& kv)
{
	ifstream fin;
	fin.open("ALL.txt", ios::in);
	if (fin.is_open())
	{
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	else cout << "file is not found\n";
	fin.close();
}

void EditAllKC(vector<KC>& kv)
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
	
}
void EditOneKC(vector<KC>& kv)
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
	cout << "\nchoose\n0. pipe not repairing \n1. pipe in repairing";
	int choice = Getcorrectnumber(0, 1);
	pv[n].remont = choice;
	cout << endl;
	return pv;
}
void Editpipeline(vector<Pipeline>& pv)
{  
	cout << "\nchoose\n1. edit all  pipelines\n2. edit one pipeline ";
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
bool SearchByPercent(KC& kv, int param)
{
	return 100 * (1 - (1. * kv.workzeh) / kv.zeh) >= param;
}
template <typename N>
void infoFilterPipeline(vector<Pipeline>& vect, bool(*f)(Pipeline& p, N param), N param)
{
	for (Pipeline& i : vect)
	{
		if (f(i, param))
		{
			cout /*<< endl << "Pipeline id: "
				<< i.ident << endl */
				<< "diametr: " << i.diametr << endl
				<< "length: " << i.length <<endl 
				<< "pipe working?: " << checkRemont(i);
		}
	}
	cout << endl;
}
template< typename N>
void infoFilterKC( vector<KC>& vect, bool(*f)(KC& p, N param), N param)
{
	for ( KC& i : vect)
	{
		if (f(i, param))
		{
			cout.precision(2);
			cout /*<< "\nKC id: " << i.ident << endl */
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
	cout << "\nchoose by what\n1.ID\n2.working or no\n ";
	if (Getcorrectnumber(1, 2) == 1)
	{
		cout << "Enter ID: ";
		int ch = Getcorrectnumber(0, 100);
		infoFilterPipeline(pipes, SearchById, ch);
	}
	else
	{
		cout << "\nchoose \n1. working\n2. unworking ";
		int choice = Getcorrectnumber(1, 2);
		infoFilterPipeline(pipes, SearchByRepair, choice);
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
		infoFilterKC(kv, SearchByName, name);
	}
	else
	{
		cout << "\ntype the number of percentages - ";
		int choice = Getcorrectnumber(0, 100);
		infoFilterKC(kv, SearchByPercent, choice);
	}
}
void Delete(vector <Pipeline>& pv, vector <KC>& kv)
{
	cout << "\nchoose what delete\n1.pipeline\n2.KC ";
	int choice = Getcorrectnumber(1, 2);
	if (choice == 1)
	{
		cout << "enter ID: ";
		int ch = Getcorrectnumber(0, 100);
		pv.erase(pv.begin() + ch);
		cout << endl;
	}
	else
	{
		cout << "enter ID: ";
		int ch = Getcorrectnumber(0, 100);
		kv.erase(kv.begin() + ch);
		cout << endl;
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
		<< "9. delete pipeline or KC " << endl
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

		switch (Getcorrectnumber(0, 9))
		{
		case 1:
		{
			Pipeline p;
			cin >> p;
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
			cout << " choose what to show  1-pipeline, 2- KC ";
			int a;
			a = Getcorrectnumber(1, 2);
			switch (a)
			{
			case 1:
				if (pv.size())
				{
					for (const auto& p : pv) cout << p << endl;
				}
				else cout << "there is no information about pipelines\n ";
				break;
			case 2:
				if (kv.size())
				{
					for (const auto& k : kv) cout << k << endl;
				}
				else cout << "there is no information about KC\n ";
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
			Save(a, pv, kv);
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
		case 9:
		{
			Delete(pv, kv);
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

}