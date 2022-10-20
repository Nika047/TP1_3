#include "Worker.h"

Worker::Worker() 
{
	Name();
	Post();
	Salary();
	Address();
	Phone();
}

Worker::Worker(ifstream& file) 
{
	int lines = 5;
	string* parameters = new string[lines];

	for (int i = 0; i < lines; i++) 
	{
		string line;
		getline(file, line);
		parameters[i] = line;
	}

	name = parameters[0];
	post = parameters[1];
	salary = stoi(parameters[2]);
	address = parameters[3];
	phone = parameters[4];
}

void Worker::Name() 
{
	cout << "���: ";
	getline(cin, name);
}

void Worker::Post() 
{
	cout << "���������: ";
	getline(cin, post);
}

void Worker::Salary() 
{
	cout << "��������: ";
	cin >> salary;
	cin.ignore();
}

void Worker::Address() 
{
	cout << "�����: ";
	getline(cin, address);
}

void Worker::Phone() 
{
	cout << "�������: ";
	getline(cin, phone);
}

void Worker::edit() 
{
	Name();
	Post();
	Salary();
	Address();
	Phone();
}

void Worker::print() 
{
	cout << "�����: ��������";
	cout << "\n���: " << name;
	cout << "\n���������: " << post;
	cout << "\n���������� �����: " << salary;
	cout << "\n������: " << address;
	cout << "\n�������: " << phone;
	cout << "\n";
}

void Worker::write(ofstream& file) const 
{
	file << "��������" << "\n";
	file << name << "\n";
	file << post << "\n";
	file << salary << "\n";
	file << address << "\n";
	file << phone << "\n";
}