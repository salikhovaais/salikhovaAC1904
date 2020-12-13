#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

class KC

{
private:
	int ident;
	static int idK;
public:
	static int GetidK();
	std::string name;
	int zeh = 0;; // ���-�� �����
	int workzeh = 0;; // ���-�� ���������� ���
	double eff = 0;;//������������� 
	KC();
	friend std::ostream& operator<<(std::ostream& out, const KC& x);
	friend std::istream& operator >>(std::istream& in, KC& x);
	friend std::ofstream& operator << (std::ofstream& fout, const KC& x);
	friend std::ifstream& operator >> (std::ifstream& fin, KC& x);
	friend bool SearchById(KC& p, int param);
	int getID()const;
	void RedaktKC();
	
};

