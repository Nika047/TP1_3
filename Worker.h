#pragma once
#include "Base.h"
#include <iostream>
#include <string>

using namespace std;

class Worker : public Base
{
public:
	Worker();
	Worker(ifstream& file);

	void Name();
	void Post();
	void Salary();
	void Address();
	void Phone();
	void print();
	void edit();
	void write(ofstream& file) const;

private:
	int salary;
	string name;
	string post;
	string address;
	string phone;
};