#include "Car.h"

Car::Car() 
{
	Mark();
	Model();
	Number();
}

Car::Car(ifstream& file) 
{
	int lines = 3;
	string* parameters = new string[lines];

	for (int i = 0; i < lines; i++) 
	{
		string line;
		getline(file, line);
		parameters[i] = line;
	}

	mark = parameters[0];
	model = parameters[1];
	number = parameters[2];
}

void Car::Mark() 
{
	cout << "Марка: ";
	getline(cin, mark);
}

void Car::Model() 
{
	cout << "Модель: ";
	getline(cin, model);
}

void Car::Number() 
{
	cout << "Номер: ";
	getline(cin, number);
}

void Car::edit() 
{
	Mark();
	Model();
	Number();
	cout << "\n";
}

void Car::print() 
{
	cout << "Класс: Машина";
	cout << "\nМарка: " << mark;
	cout << "\nМодель: " << model;
	cout << "\nНомер: " << number;
	cout << "\n";
}

void Car::write(ofstream& file) const
{
	file << "Машина" << "\n";
	file << mark << "\n";
	file << model << "\n";
	file << number << "\n";
}