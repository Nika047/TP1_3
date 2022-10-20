#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "Keeper.h"
#include "Worker.h"
#include "Car.h"
#include "Furniture.h"

using namespace std;

Keeper fabric;

void editMenu();
void removeMenu();

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1)
	{
		cout << "Меню: \n";
		cout << "1. Открыть структуру фабрики \n";
		cout << "2. Добавить мебель \n";
		cout << "3. Добавить машину \n";
		cout << "4. Добавить работника \n";
		cout << "5. Редактировать \n";
		cout << "6. Удалить \n";
		cout << "7. Сохранить в файл \n";
		cout << "8. Загрузить из файла \n";
		cout << "ESC. Выход \n\n";
		cout << "Выберите нужное действие";
		
		char command = _getch();

		system("@cls||clear");

		switch (command)
		{
		case '1':
			fabric.print();
			break;

		case '2':
			fabric.add(new Furniture());
			break;

		case '3':
			fabric.add(new Car());
			break;

		case '4':
			fabric.add(new Worker());
			break;

		case '5':
			editMenu();
			break;

		case '6':
			removeMenu();
			break;

		case '7':
			fabric.save();
			break;

		case '8':
			fabric.load();
			break;

		case 27:
			exit(0);

		default:
			break;
		}
		system("@cls||clear");
	}
}

void editMenu()
{
	if (fabric.isEmpty())
		return;

	while (1) 
	{
		system("@cls||clear");

		for (int i = 0; i < fabric.getSize(); i++) 
		{
			cout << "Номер: " << (i + 1) << "\n";
			fabric.getList()[i]->print();
			cout << "\n";
		}

		int num;

		cout << "\nВведите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > fabric.getSize()) 
		{
			cout << "\nТакого объекта нет \n";
			cout << "\"nНажмите любую клавишу \n";
			_getch();
			continue;
		}

		system("@cls||clear");
		fabric.getList()[num - 1]->edit();
		return;
	}
}

void removeMenu() 
{
	if (fabric.isEmpty()) 
		return;

	while (1) 
	{
		system("@cls||clear");

		for (int i = 0; i < fabric.getSize(); i++) 
		{
			cout << "Номер: " << (i + 1) << "\n";
			fabric.getList()[i]->print();
			cout << "\n";
		}

		int num;

		cout << "\nВведите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > fabric.getSize()) 
		{
			cout << "\nТакого объекта нет \n";
			cout << "\nНажмите любую клавишу \n";
			_getch();
			continue;
		}

		system("@cls||clear");
		fabric.remove(num - 1);
		return;
	}
}