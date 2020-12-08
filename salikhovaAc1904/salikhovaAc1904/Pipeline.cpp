#include "Pipeline.h"
#include <iostream>
#include <string>

using namespace std;

int Pipeline::idP = 0;

Pipeline::Pipeline()
{
	ident = idP++;
}


std::string checkRepair(const Pipeline& p)//rename and class
{
	return (p.remont) ? "Unworking \n\n" : "Working \n\n";

}