#include "Keeper.h"

Keeper::Keeper() {}

void Keeper::add(Base *element) 
{
	Base **newList = new Base*[structureSize + 1];

	for (int i = 0; i < structureSize; i++)
		newList[i] = structure[i];

	newList[structureSize++] = element;
	delete[] structure;
	structure = newList;
}

void Keeper::remove(int number) 
{
	Base **newList = new Base*[structureSize - 1];

	int index = 0;
	for (int i = 0; i < structureSize; i++)
	{
		if (i == number)
			continue;
		newList[index] = structure[index];
		index++;
	}
	delete[] structure;
	structure = newList;
	structureSize--;
}

void Keeper::save() 
{
	ofstream out;
	out.open(fileName);

	if (out.is_open())
	{
		out << structureSize << "\n";
		for (size_t i = 0; i < structureSize; i++) 
		{
			out << *structure[i];
			out << "\n";
		}
		cout << "���������!\n";
	}

	else
		cout << "�� ������� ������� ����!";

	out.close();
	cout << endl << "������� ����� ������� ����� �������� � ����\n";
	_getch();
}

void Keeper::load() 
{
	string line;
	ifstream in(fileName);

	try
	{
		if (!in.is_open())
			throw std::runtime_error("�� ������� ������� ����");
		
		getline(in, line);

		int structCount = stoi(line);
		if (structCount <= 0)
			throw std::runtime_error("���� ���� ��� ���������");

		int counter = 0;
		Base **newList = new Base*[structCount];

		while (getline(in, line))
		{
			if (string("������") == line) 
				newList[counter++] = new Furniture(in);
			
			if (string("��������") == line) 
				newList[counter++] = new Worker(in);
			
			if (string("������") == line) 
				newList[counter++] = new Car(in);
		}

		delete[]structure;
		structure = newList;
		structureSize = structCount;
		cout << "������� ��������(�) " << structureSize << " ������(��)\n";
	}

	catch (std::runtime_error err)
	{
		cout << err.what() << "\n";
	}

	catch (...)
	{
		cout << "����������� ������";
	}

	in.close();

	cout << "\n������� ����� ������� ����� �������� � ���� \n";
	_getch();
}

void Keeper::print()
{
	if (isEmpty()) 
		return;

	for (int i = 0; i < structureSize; i++) 
	{
		structure[i]->print();
		cout << "\n";
	}

	cout << "\n������� ����� ������� \n";
	_getch();
}

bool Keeper::isEmpty()
{
	if (structureSize > 0) 
		return 0;

	cout << "������� �����!\n\n";
	cout << "������� ����� ������� ����� �������� � ���� \n";
	_getch();

	return 1;
}

Base** Keeper::getList()
{
	return this->structure;
}

int Keeper::getSize()
{
	return this->structureSize;
}

Keeper::~Keeper() 
{
	delete[] structure;
}