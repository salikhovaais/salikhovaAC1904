#include "KC.h"

using namespace std;
int KC::idK = 0;//���������� ������������� �������
KC::KC()
{
	ident= idK;
	idK++;
}