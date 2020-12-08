#include "KC.h"

using namespace std;
int KC::idK = 0;//уникальная идентификация станций
KC::KC()
{
	ident= idK;
	idK++;
}