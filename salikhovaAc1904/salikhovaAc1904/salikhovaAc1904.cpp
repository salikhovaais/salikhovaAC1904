#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pipeline.h"
#include "KC.h"
#include "Utilus.h"
#include "network.h"
#include <unordered_map>
using namespace std;




std:: string checkRemont(Pipeline& p)//rename and class
{
	return (p.remont) ? "Unworking \n\n" : "Working \n\n";
}



void EditAllKC(unordered_map<int, KC>& kv)
{
	cout << "\n0. add workzeh \n1. remove workzeh\n ";
	int choice = Getcorrectnumber(0, 1);
	cout << endl;
	for ( KC& i : kv)
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
void EditOneKC(unordered_map<int, KC>& kv)
{
	cout << "id of the KC you want to edit: ";
	int k;
	cin >> k;
	cout << "\n0. start the working zeh\n1. stop the working zeh\n ";
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
void EditKC(unordered_map<int, KC>& kv)
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
//void EditAllPipeline(unordered_map< int, Pipeline>& pv)
//{
//	cout << "choose\n0. pipelines working\n1. pipelines  repairing\n";
//	int choice = Getcorrectnumber(0, 1);
//	cout << endl;
//	for ( Pipeline& i : pv)/*nordered_map<int, Pipeline>::iterator got = Pipeline_s.find(choice);*/
//	//		if (got == Pipeline_s.end())
//	{
//		i.remont = choice;
//	}
//}

unordered_map<int, Pipeline> EditOnePipeline(unordered_map<int, Pipeline>& pv)
{
	cout << "type id you want to edit: ";
	int n;
	n = Getcorrectnumber(0,1000);
	cout << "\nchoose\n0. pipe not repairing \n1. pipe in repairing";
	int choice = Getcorrectnumber(0, 1);
	pv[n].remont = choice;
	cout << endl;
	return pv;
}
//void PackEditPipeline(unordered_map<int, Pipeline>& pv ) 
//{
//	cout << "edit pipeline by\n" << endl
//		<< "1.unworking\n" << endl
//		<< "2.working\n" << endl
//		<< "3.by ID" << endl;
//	switch (Getcorrectnumber(1,3))
//	{
//	case 1:
//		for (int i : )





template <typename T>
bool del(unordered_map<int, T>& pv, int ident)
{
	return pv.erase(ident);
}

void Editpipeline(unordered_map<int, Pipeline>& pv)
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
	return p.getID() == param;
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
void infoFilterPipeline(unordered_map<int, Pipeline>& pv, bool(*f)(Pipeline& p, N param), N param)
{
	for (Pipeline& i : vect)
	{
		if (f(i, param))
		{
			cout << endl << "Pipeline id: "
				<< i.ident << endl 
				<< "diametr: " << i.diametr << endl
				<< "length: " << i.length <<endl 
				<< "pipe working: " << checkRemont(i);
		}
	}
	cout << endl;
}
template< typename N>
void infoFilterKC(unordered_map<int, KC>& kv, bool(*f)(KC& p, N param), N param)
{
	for ( KC& i : vect)
	{
		if (f(i, param))
		{
			cout.precision(2);
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
void SearchByFilterPipeline(unordered_map<int, Pipeline>& pv)// показ труб по филтру
{
	cout << "\nchoose by what\n1.ID\n2.working or no\n ";
	if (Getcorrectnumber(1, 2) == 1)
	{
		cout << "Enter ID: ";
		int ch = Getcorrectnumber(0, 100);
		infoFilterPipeline(pv, SearchById, ch);
	}
	else
	{
		cout << "\nchoose \n1. working\n2. unworking ";
		int choice = Getcorrectnumber(1, 2);
		infoFilterPipeline(pv, SearchByRepair, choice);
		cout << "\nedit this pipelines? \n1. yes\n2. no ";
		if  (Getcorrectnumber(1, 2)==1)
			/////////////////////////////////////////////////////////////////////////////////////////////

	}
}
void SearchByFilterKC(unordered_map<int, KC>& kv)
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
void Delete(unordered_map<int,network>& pv, unordered_map<int, network>& kv)
{
	cout << "\nchoose what delete\n1.pipeline\n2.KC ";
	int choice = Getcorrectnumber(1, 2);
	if (choice == 1)
	{
		cout << "enter ID: ";
		int ch = Getcorrectnumber(0, 100);
		
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
	unordered_map<int, Pipeline> pv;
	unordered_map<int, KC> kv;
	KC k;
	Pipeline p;
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
			if (pv.size())
			
				for (const auto& p : pv) cout << p << endl;

			else cout << "there is no information about pipelines \n ";
			if (kv.size())
			for (const auto& k : kv) cout << k << endl;
			else cout << "there is no information about KC\n ";
			break;
		}
		case 4:

		{
			if (pv.size())
			Editpipeline(pv);
			else cout << "there is no information about pipelines \n ";
			break;
		}
		case 5:

		{if (kv.size())
			EditKC(kv);
		else cout << "there is no information about KC\n ";
			break;
		}

		case 6:

		 
		{
			if ((pv.size() != 0) and (kv.size() != 0))
				cout << "there is no pipeline and KC\n ";
			else
			{
				ofstream fout;
				string nameoffile;
				cout << "type name of file";
				cin.ignore();
				getline(cin, nameoffile);
				fout.open(nameoffile, ios::out);
				if (fout.is_open())
				{
					fout << pv.size() << endl;
					fout << kv.size() << endl;
					for (const auto& p : pv)
					{
						fout << p.second;
					}
					for (const auto& k : kv)
					{
						fout << k.second;
					}
					fout.close();
				} 
			}
			break; 
		}
			
			
		case 7:
		
		{
			if ((pv.size() != 0) and (kv.size() != 0))
				cout << "there is no pipeline and KC\n ";
			else {
				ifstream fin;
				string nameoffile;
				cout << "type name of file";
				cin.ignore();
				getline(cin, nameoffile);
				fin.open(nameoffile, ios::in);
				if (fin.is_open())

				{
					int count1;
					int count2;
					fin >> count1;
					fin >> count2;
					while (count1--)
					{
						Pipeline p;
						fin >> p;
					}
					while (count2--)
					{
						KC k;
						fin >> k;
					}

				}
				else cout << "file is not found\n";
				fin.close();
			}
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
		{ int a;
		cout << "type the number of pipeline to delete" << endl;
			a = Getcorrectnumber(0, 10000);
			del(pv);
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

