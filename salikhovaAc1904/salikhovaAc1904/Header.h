#pragma once
#include <iostream>

//template <typename T>
int Getcorrectnumber(int min, int max)//проверка на введение нужной цифры 
{
	int x;
	while ((std::cin >> x).fail() || x<min || x> max)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Type number (" << min << "-" << max << "):";
	}
	return x;
}