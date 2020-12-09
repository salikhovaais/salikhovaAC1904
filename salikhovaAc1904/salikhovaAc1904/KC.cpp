#include "KC.h"
#include "Header.h"
#include <vector>
using namespace std;
int KC::idK = 0;//уникальная идентификация станций
KC::KC()
{
	ident= idK;
	idK++;
}
std::istream& operator>>(std::istream& in, KC& y)
{
	std::cout << "type name kc \n";
	cin.ignore();
	getline(cin, y.name);
	std::cout << " type number of zeh \n";
	y.zeh = Getcorrectnumber(0, 1000);
	std::cout << "type number of working zeh\n";
	y.workzeh = (Getcorrectnumber(1, y.zeh));
	std::cout << "type efficiency  of  workzeh (1-10)\n";
	y.eff = (Getcorrectnumber(1, 10));
	return in;
}
