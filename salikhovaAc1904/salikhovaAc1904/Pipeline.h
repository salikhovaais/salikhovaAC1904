#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
class Pipeline
{
private:
	static int idP;
	int ident;
	unsigned int inputks = 0; // Компрессорная станция, от которой идёт труба
	unsigned int outputks = 0; // Компрессорная станция, к которой идёт труба
public:
	int idin;
	int idout;
	int get_idin() const;
	int get_idout() const;
	double length = 0;
	double diametr = 0;
	bool remont = false;
	Pipeline();
	static int GetidP();
	void setinputks(unsigned int value); // Присваиваю номер компрессорной станции, от которой идёт труба
	void setoutputks(unsigned int value);// Присваиваю номер компрессорной станции, к которой идёт труба
	unsigned int getinputks(); // Возвращаю номер компрессорной станции, от которой идёт труба
	unsigned int getoutputks(); // Возвращаю номер компрессорной станции, к которой идёт труба

	void RedaktPipeline();
	friend std::ostream& operator<<(std::ostream& out, const Pipeline& x);
	friend std::istream& operator >>(std::istream& in, Pipeline& x);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipeline& x);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipeline& x);
	int getID()const;
	
	

};