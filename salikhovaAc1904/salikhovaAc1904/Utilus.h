#pragma once
#include <iostream>

using namespace std;
template <typename T>


T Getcorrectnumber(T min, T max)//проверка на введение нужной цифры 
{
	T x;
	while ((cin >> x).fail() || x<min || x> max)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type number (" << min << "-" << max << "):";
	}
	return x;

}