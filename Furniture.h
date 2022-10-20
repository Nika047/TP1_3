#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include "Base.h"

#define LEFT 75
#define RIGTH 77
#define ENTER 13

using namespace std;

class Furniture : public Base
{
public:
	Furniture();
	Furniture(ifstream& file);

	void Type();
	void Dimensions();
	void Color();
	void Material();
	void Price();
	void print();
	void edit();
	void write(ofstream& file) const;

private:
	int color;
	int price;
	string type;
	string dimensions;
	string material;
	string colors[7] = { "\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m" };
	string colorsTitle[7] = { "Красный", "Зеленый", "Желтый", "Синий", "Фиолетовый", "Голубой", "Белый" };
};