#include "network.h"
#include<set>
#include <unordered_map>
#include<vector>
#include "KC.h"

void network :: editnetwork (unordered_map <int, Pipeline>& pv)
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
			unsigned int ks = Getcorrectnumber(1, KC::GetidK());//1 KC
			idks.insert(ks);
			unsigned int t;
			while (true)
			{
				cout << "type pipe  ID ";
				t = Getcorrectnumber(1, Pipeline::GetidP());//pipeconnect
				if (pv[t].getinputks() == 0 && pv[t].getoutputks() == 0)
					break;
				else
					cout << "this pipe already using \n";
			}
			idt.insert(t);
			pv[t].setinputks(ks);
			unsigned int ks1;
			while (true)
			{
				cout << "type 2 KC ID";
				ks1 = Getcorrectnumber(1, KC::GetidK());//2 KC
				if (ks1 != ks)
					break;
				else
					cout << "one KC can not be output and input\n";
			}
			idks.insert(ks1);
			pv[t].setoutputks(ks1);
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

vector<vector<int>> network::creatematrix(int n)
{
	matrix.resize(n);
	for (int i = 0; i < n; i++)
	{
		matrix[i].resize(n);
	}
	return matrix;
}

void network::deletematrix(int n)
{
	for (int i = 0; i < n; i++)
	{
		matrix[i].clear();
	}
	matrix.clear();
}

void network::editmatrix(unordered_map<int, Pipeline>& pv)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : pv)
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}

}
void network::editmatrixformaxpotok(unordered_map<int, Pipeline>& pv)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : pv)
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
		if (first > -1 && second > -1 && infotruba.second.getremont() == false)
			matrix[first][second] = infotruba.second.getproizv();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


void network::editmatrixforminpyt(unordered_map<int, Pipeline>& pv)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : pv)
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
		if (first > -1 && second > -1 && infotruba.second.getremont() == false)
			matrix[first][second] = infotruba.second.length;//
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}
vector<unsigned int> network::tgtssort(unordered_map<int, Pipeline>& pv)
{
	vector<unsigned int> sorted;
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	int n = idks.size();
	matrix = creatematrix(n);
	editmatrix(pv);
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
				matrix[i][i] = 1 ;
			}
		}
	/*}*/
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];

		}
		cout << endl;*/
	}
	deletematrix(n);
	reverse(sorted.begin(), sorted.end());
	return sorted;
}

void network::deleteidks(int value)
{
	idks.erase(idks.find(value));
}

int network::findindex(vector<unsigned int> v, int value)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			return i;
	}
}

float network::countpotok(unordered_map<int, Pipeline>& pv, unordered_map<int, KC> kv, int istok, int stok)
{
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	float F = 0;
	while (true)
	{
		vector<int> queue;
		queue.push_back(istok);
		int count = 0;
		int iterator = findindex(vks, istok);
		kv[istok].pometka = INFINITY;
		while (kv[stok].pometka == 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				if (matrix[iterator][i] != 0)
				{
					if (kv[queue[0]].pometka >= matrix[iterator][i])
					{
						kv[vks[i]].pometka = matrix[iterator][i];
						kv[vks[i]].pred = vks[iterator];
						queue.push_back(vks[i]);
					}
					else
					{
						kv[vks[i]].pometka = kv[queue[0]].pometka;
						kv[vks[i]].pred = vks[iterator];
						queue.push_back(vks[i]);
					}
				}
			}
			queue.erase(queue.begin());
			if (queue.size() == 0)
				return F;
			iterator = findindex(vks, queue[0]);
			count++;
		}
		int s = kv[stok].pometka;
		int iter = stok;
		int index1 = findindex(vks, kv[stok].pred);
		int index2 = findindex(vks, stok);
		for (int i = 0; i < count; i++)
		{
			matrix[index1][index2] -= s;
			if (matrix[index1][index2] == s)
				matrix[index1][index2] = 0;
			int pr = index1;
			index2 = index1;
			index1 = findindex(vks, kv[vks[pr]].pred);
			iter = kv[iter].pred;
		}
		for (auto& i : idks)
		{
			kv[i].pometka = 0;
		}
		F += s;
	}
}

float network::maxpotok(unordered_map<int, Pipeline>& pv, unordered_map<int, KC>& kv)
{
	int istok;
	int stok;
	while (true)
	{
		cout << "type  first KC id" << endl;
		istok = Getcorrectnumber(1, KC::GetidK());
		cout << "type  second KC id" << endl;
		stok = Getcorrectnumber(1, KC::GetidK());
		bool f1 = false;
		bool f2 = false;
		for (auto& i : idks)
		{
			if (i == istok)
			{
				kv[i].pometka = INFINITY;
				f1 = true;
			}
			if (i == stok)
			{
				kv[i].pometka = 0;
				f2 = true;
			}
		}
		if (istok == stok || f1 == false || f2 == false)
		{
			cout << "error\n";
		}
		else
			break;
	}
	size_t n = idks.size();
	matrix = creatematrix(n);
	editmatrixformaxpotok(pv);
	float F = countpotok(pv, kv, istok, stok);
	deletematrix(n);
	return F;
}

float network::countpyt(unordered_map<int, Pipeline>& pv, unordered_map<int, KC>& kv, int istok, int stok)
{
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	float F = 0;
	vector< unsigned int> queue;
	queue.push_back(istok);
	int iterator = findindex(vks, istok);
	while (true)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[iterator][i] != 0)
			{
				if (kv[vks[i]].pometka >= (matrix[iterator][i] + kv[queue[0]].pometka))
				{
					kv[vks[i]].pometka = matrix[iterator][i] + kv[queue[0]].pometka;
					bool f = false;
					for (auto& k : queue)
					{
						if (k == vks[i])
							f = true;
					}
					if (f == false)
						queue.push_back(vks[i]);
				}
			}
		}
		queue.erase(queue.begin());
		if (queue.size() == 0)
			return kv[stok].pometka;
		float min = INFINITY;
		int id = 0;
		for (auto& i : queue)
		{
			if (min > kv[i].pometka)
			{
				min = kv[i].pometka;
				id = findindex(queue, i);
			}
		}
		swap(queue[0], queue[id]);
		iterator = findindex(vks, queue[0]);
	}
}

float network::minpyt(unordered_map<int, Pipeline>& pv, unordered_map<int, KC>& kv)
{
	int istok;
	int stok;
	while (true)
	{
		cout << "type  first KC id" << endl;
		istok = Getcorrectnumber(1, KC::GetidK());
		cout << "type  second KC id" << endl;
		stok = Getcorrectnumber(1, KC::GetidK());
		bool f1 = false;
		bool f2 = false;
		for (auto& i : idks)
		{
			kv[i].pometka = INFINITY;
			if (i == istok)
			{
				kv[i].pometka = 0;
				f1 = true;
			}
			if (i == stok)
			{
				kv[i].pometka = INFINITY;
				f2 = true;
			}
		}
		if (istok == stok || f1 == false || f2 == false)
		{
			cout << "error\n";
		}
		else
			break;
	}
	size_t n = idks.size();
	matrix = creatematrix(n);
	editmatrixforminpyt(pv);
	float S = countpyt(pv, kv, istok, stok);
	deletematrix(n);
	return S;
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

