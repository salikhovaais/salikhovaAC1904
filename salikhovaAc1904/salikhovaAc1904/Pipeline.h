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
	unsigned int inputks = 0; // ������������� �������, �� ������� ��� �����
	unsigned int outputks = 0; // ������������� �������, � ������� ��� �����
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
	void setinputks(unsigned int value); // ���������� ����� ������������� �������, �� ������� ��� �����
	void setoutputks(unsigned int value);// ���������� ����� ������������� �������, � ������� ��� �����
	unsigned int getinputks(); // ��������� ����� ������������� �������, �� ������� ��� �����
	unsigned int getoutputks(); // ��������� ����� ������������� �������, � ������� ��� �����

	void RedaktPipeline();
	friend std::ostream& operator<<(std::ostream& out, const Pipeline& x);
	friend std::istream& operator >>(std::istream& in, Pipeline& x);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipeline& x);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipeline& x);
	int getID()const;
	
	

};