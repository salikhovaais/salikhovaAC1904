#include <iostream>
using namespace std;
struct Pipeline
{
	int dlina;
	int diametr;
	bool remont;
	int ident;
};
struct KC
{
	int ident;
	string name;
	int kolvo;
	int zeh;
	int rabzeh;
	string effect;
};
int createpipe(string name) {
	Pipeline x;
	cout << "введите длину  трубы\n";
	cin >> x.dlina ;
	cout << "введите диаметр трубы\n";
	cin >> x.diametr;
	return x;
}
int main()
{
	setlocale;
		Pipeline pipe1;
		pipe1.ident = "1a";
		cout << pipe1.ident;
		createpipe(pipe1);
		return 0;
}
