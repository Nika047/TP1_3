#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <conio.h>

#include "Base.h"
#include "Car.h"
#include "Furniture.h"
#include "Worker.h"

using namespace std;

class Keeper
{
public:
	Keeper();

	void add(Base *element);
	void remove(int number);
	void save();
	void load();
	void print();
	bool isEmpty();

	Base** getList();

	int getSize();

	~Keeper();

private:
	Base** structure = {};
	int structureSize = 0;
	string fileName = "fabric.txt";
};