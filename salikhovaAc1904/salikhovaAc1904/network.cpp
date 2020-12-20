#include "network.h"
#include<set>
#include <unordered_map>
#include<vector>
#include "KC.h"

void network :: editnetwork (unordered_map <int, Pipeline>& Truboprovod)
{
	while (true)
	{
		cout << "1 - connect KC\n";
		cout << "0 - exit\n";
		int i = Getcorrectnumber( 0, 1);
		switch (i)
		{
		case 1:
		{cout << "type 1 KC ID";
			unsigned int ks = Getcorrectnumber(0, KC::GetidK());
			idks.insert(ks);
			unsigned int t;
			while (true)
			{
				cout << "type pipe  ID ";
				t = Getcorrectnumber(0, Pipeline::GetidP());//
				if (Truboprovod[t].getinputks() == 0 && Truboprovod[t].getoutputks() == 0)
					break;
				else
					cout << "this pipe already using \n";
			}
			idt.insert(t);
			Truboprovod[t].setinputks(ks);
			unsigned int ks1;
			while (true)
			{
				cout << "type 2 KC ID";
				ks1 = Getcorrectnumber(0, KC::GetidK());//2 KC
				if (ks1 != ks)
					break;
				else
					cout << "one KC can not be output and input";
			}
			idks.insert(ks1);
			Truboprovod[t].setoutputks(ks1);
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "error\n";
		}
		}
	}
}

void network:: savefilenetwork(std::ofstream& fout)
{
	if (idks.size() > 0)
	{
		for (auto& n : idks)
		{
			fout << n << endl;
		}
	}
	if (idks.size() > 0)
	{
		for (auto& n : idt)
		{
			fout << n << endl;
		}
	}
}

int network::inputfilenetwork(std::ifstream& fin)
{
	int n;
	fin >> n;
	return n;
}

int** network::creatematrix(int n)
{
	matrix = new int* [n]();
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n]();
	}
	return matrix;
}

void network::deletematrix(int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void network::editmatrix(unordered_map<int, Pipeline>& Truboprovod)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : Truboprovod)
	{
		int first = -1;
		int second = -1;
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getinputks() == sortedidks[i])
				first = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getoutputks() == sortedidks[i])
				second = i;
		}
		if (first > -1 && second > -1)
			matrix[first][second] = 1;
	}
}

vector<unsigned int> network::tgtssort(unordered_map<int, Pipeline>& Truboprovod)
{
	vector<unsigned int> sorted;
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	int n = idks.size();
	matrix = creatematrix(n);
	editmatrix(Truboprovod);
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += matrix[i][j];
			}
			if (sum == 0)
			{
				sorted.push_back(vks[i]);
				for (int j = 0; j < n; j++)
				{
					matrix[j][i] = 0;
				}
				matrix[i][i] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	deletematrix(n);
	reverse(sorted.begin(), sorted.end());
	return sorted;
}

void network::deleteidks(int value)
{
	idks.erase(idks.find(value));
}

set<int> network::getidks()
{
	return idks;
}

set<int> network::getidt()
{
	return idt;
}

void network::setidks(int value)
{
	idks.insert(value);
}

void network::setidt(int value)
{
	idt.insert(value);
}

