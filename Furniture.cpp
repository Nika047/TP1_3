#include "Furniture.h"

Furniture::Furniture() 
{
	Type();
	Dimensions();
	Material();
	Color();
	Price();
}

Furniture::Furniture(ifstream& file) 
{
	int lines = 5;
	string* parameters = new string[lines];

	for (int i = 0; i < lines; i++) 
	{
		string line;
		getline(file, line);
		parameters[i] = line;
	}
	type = parameters[0];
	dimensions = parameters[1];
	color = stoi(parameters[2]);
	material = parameters[3];
	price = stoi(parameters[4]);
}

void Furniture::Type() 
{
	cout << "Тип мебели: ";
	getline(cin, type);
}

void Furniture::Dimensions() 
{
	int h, w, l;
	cout << "Введите длину: ";
	cin >> l;
	cout << "Введите ширину: ";
	cin >> w;
	cout << "Введите высоту: ";
	cin >> h;

	cin.ignore();
	dimensions = to_string(l) + string("*") + to_string(w) + string("*") + to_string(h);
}

void Furniture::Color() 
{
	int colorNum = 0;

	while (1) 
	{
		cout << "\33[2K \r";
		cout << "Выберите цвет: < " << colors[colorNum] << colorsTitle[colorNum] << "\033[0m >";
		
		int command = _getch();

		switch (command)
		{
		case LEFT:
			colorNum = colorNum > 0 ? colorNum - 1 : 6;
			break;

		case RIGTH:
			colorNum = colorNum != 6 ? colorNum + 1 : 0;
			break;

		case ENTER:
			cout << "\n";
			color = colorNum;
			to_string(color);
			return;
		}
	}
}

void Furniture::Material() 
{
	cout << "Материал: ";
	getline(cin, material);
}

void Furniture::Price() 
{
	cout << "Цена: ";
	cin >> price;
	to_string(price);
	cin.ignore();
}

void Furniture::edit() 
{
	Type();
	Dimensions();
	Material();
	Color();
	Price();
	cout << "\n";
}

void Furniture::print() 
{
	cout << "Класс: Мебель";
	cout << "\nТип: " << type;
	cout << "\nРазмеры: " << dimensions;
	cout << "\nЦвет: " << colors[color] << colorsTitle[color] << "\033[0m";
	cout << "\nМатериал: " << material;
	cout << "\nЦена: " << price << " руб.";
	cout << "\n";
}

void Furniture::write(ofstream& file) const 
{
	file << "Мебель" << "\n";
	file << string(type) << "\n";
	file << dimensions << "\n";
	file << color << "\n";
	file << string(material) << "\n";
	file << price << "\n";
}