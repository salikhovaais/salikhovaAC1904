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

string EnterName()
{
	string filename;
	cout << "\nplease enter a name for the KC: ";
	cin.ignore(1000, '\n');
	getline(cin, filename);
	return filename;
}
//bool SearchById(Pipeline& p, int param)
//{
//	return p.getID() == param;
//}

bool SearchByRepair(const Pipeline& p, int param)
{
	return p.remont == param-1;
}
bool SearchByName(const KC& k, string name)
{
	return k.name == name;
}
bool SearchByPercent(const KC& kv, double param)
{
	return 100 * (1 - (1. * kv.workzeh) / kv.zeh) >= param;
}
template <typename W, typename T>
using Filter = bool(*)(const W& o, T param);
template <typename W, typename T>
vector<int> FindItemsByFilter(const unordered_map <int, W>& g, Filter <W, T> f, T param)
{
	vector<int>res;
	int i = 0;
	for (const auto& obj : g)
	{
		if (f(obj.second, param))
			res.push_back(i);
		i++;
	}
	if (res.size() == 0)
	{
		cout << "error\n";
	}
	return res;
}

void EditOneKC(unordered_map<int, KC>& kv)
{
	cout << "type the ID of  KC that you want to edit: ";
	int k;
	 k=Getcorrectnumber(1,KC::GetidK());
	cout << "\n0. add the working zeh\n1. remove the working zeh\n ";
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



void EditPackPipeline(unordered_map<int, Pipeline>& pv)
{
	cout << "choose by what edit pipelines" << endl;
	cout << "\n1. pipelines wich working \n2. pipelines wich repairing\n3.by ID";
	switch (Getcorrectnumber(1, 3))
	{
	case 1:
	{
		for (int i : FindItemsByFilter(pv, SearchByRepair, 0))
			pv.find(i)->second.RedaktPipeline();
	}
	case 2:
	{
		for (int i : FindItemsByFilter(pv, SearchByRepair, 1))
			pv.find(i)->second.RedaktPipeline();
	}
	case 3:
	{vector<int> v;
	while (1)
	{
		cout << "type id you want to edit: ";
		v.push_back(Getcorrectnumber(1, Pipeline::GetidP()));
		cout << "add more pipeline to edit? " << endl << "\t0.add\n1.no";
		if (Getcorrectnumber(0, 1) == 1)
			break;
	} for (auto i : v)
	{
		if (pv.find(i) != pv.end())
			pv.find(i)->second.RedaktPipeline();
	}
	break;
	}
	}
}






void DelPipes(unordered_map<int, Pipeline>& pipes_p)
{
	if (pipes_p.size() != 0)
	{
		cout << "enter an ID of the pipe you want to delete: ";
		int i;
		cin >> i;
		if (pipes_p.find(i) != pipes_p.end())
			pipes_p.erase(i);
		cout << "the pipe is deleted";
	}
	else
	{
		cout << "error\n";
	}
}

void DelKC(unordered_map <int, KC>& kc_k, network& network, unordered_map<int, Pipeline>& pv)
{
	if (kc_k.size() != 0)
	{
		cout << "enter the ID of the KC you want to delete: ";
		int t=Getcorrectnumber(1,KC::GetidK());
		network.deleteidks(t);
		for (auto& n : pv)
		{
			if (n.second.getinputks() == t)
				n.second.setinputks(0);
		}
		for (auto& n : pv)
		{
			if (n.second.getoutputks() == t)
				n.second.setoutputks(0);
		}
	kc_k.erase(t);
	cout << "the KC is deleted";
	}
	else
	{
		cout << "error\n";
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
		<< "10. connect  KC with  pipeline  " << endl
		<< "11. topological sort" << endl
		<< "12. save sorted network " << endl
		<< "0. exit" << endl
		<< "choose action" << endl;

}

int main()
{
	unordered_map<int, Pipeline> pv;
	unordered_map<int, KC> kv;
	
	network network;
	vector<unsigned int> sortedmatrix;
	KC k;
	Pipeline p;
	while (1)
	{
		PrintMenu();

		switch (Getcorrectnumber(0, 12))
		{
		case 1:
		{
			
			Pipeline p;
			cin >> p;
			pv.insert(pair<int, Pipeline>(p.getID(), p));
			break;
		}
		case 2:
		{
			KC k;
			cin >> k;
			kv.insert(pair<int, KC>(k.getID(), k));
			break;
		}
		case 3:

		{
			if (pv.size() > 0)

				for (const auto& p : pv)
				{
					cout << p.second << endl;
				}

			else
			{
				cout << "there is no information about pipelines \n ";
			}
			if (kv.size() > 0)
				for (const auto& k : kv)
				{cout << k.second << endl; }
			else
			{
				cout << "there is no information about KC, impossible to create network\n ";
			}
			break;
		}
		case 4:

		{
			if (pv.size())
			EditPackPipeline(pv);
			else cout << "there is no information about pipelines \n ";
			break;
		}
		case 5:

		{if (kv.size())
		{
			cout << "please enter an ID of the KC you want to edit: ";
			int n;
			cin >> n;
			kv[n].RedaktKC();
		}
		else 
			cout << "there is no information about KC\n ";
			
		}break;

		case 6:

		 
		{
			if ((pv.size() != 0) and (kv.size() != 0))
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
				}break;
			}
				
			else
			{
				cout << "there is no pipeline and KC\n ";
			}
			
		
			
		}
			
		case 7:
		
		{
			
			 {
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
						p.inputfilepipe(fin);
						/*pv[i] = p;*/
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
			cout << "choose number to search \n1.pipelines by status\n2.KC";
			if (Getcorrectnumber(1, 2) == 1)
			{
				cout << "1. find working pipelines" << endl
					<< "2. find not working pipelines(remont)" << endl;
				if (Getcorrectnumber(1, 2) == 1) {
					for (int i : FindItemsByFilter(pv, SearchByRepair, 0))
						cout << pv[i + 1];
				}
				else
				{
					for (int i : FindItemsByFilter(pv, SearchByRepair, 1))
						cout << pv[i + 1];
				}
			}
			else
				cout << "\nchoose by what\n1.name\n" << "2.percentage of unused workzeh";
			if (Getcorrectnumber(1, 2) == 1)
			{
				
				for (int i : FindItemsByFilter(kv, SearchByName, EnterName()))
					cout << kv[i + 1];
			}
			else
			{
				cout << "\ntype the number of percentages - ";
				for (int i : FindItemsByFilter(kv, SearchByPercent, Getcorrectnumber(0.00, 100.0)))
				cout << kv[ i  + 1];
			}
			break;
		}
		case 9:
		{  cout << "1. Pipelines" << endl
			<< "2. KC" << endl
			<< "please choose what you want to delete: ";
		if (Getcorrectnumber(1, 2) == 1)
		{
			DelPipes(pv);
		}
		else
		{
			DelKC(kv,network,pv);
		}
		break;
		}
		case 10:
		{

			network.editnetwork(pv);
			break;

		}
		case 11:
		{
			sortedmatrix = network.tgtssort(pv);
			if (sortedmatrix.size() > 0)
			{
				int k = 1;
				for (auto& i : sortedmatrix)
				{
					cout <<  k << " ID :" << i << endl;
					k += 1;
				}
			}
			else
				cout << "there is cycle\n";
			break;
		}
		case 12:
		{
			if (network.getidks().size() > 0 || network.getidt().size() > 0)
			{
				ofstream fout;
				fout.open("gts.txt", ios::out);
				if (fout.is_open())
				{
					sortedmatrix = network.tgtssort(pv);
					if (sortedmatrix.size() > 0)
					{
						int k = 1;
						for (auto& i : sortedmatrix)
						{

							fout << k << " ID :" << i << endl;
							k += 1;
						}

					}
					network.savefilenetwork(fout);
					fout.close();
				}
				break;
			}
			else
			{
				cout << "there is no network\n";
				break;
			}

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

