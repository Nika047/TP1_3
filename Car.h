#pragma once
#include "Base.h"
#include <iostream>
#include <string>

using namespace std;

class Car : public Base
{
public:
	Car();
	Car(ifstream& file);

	void Mark();
	void Model();
	void Number();
	void print();
	void edit();
	void write(ofstream& file) const;

private:
	string mark;
	string model;
	string number;
};