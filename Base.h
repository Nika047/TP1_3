#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Base
{
public: 
	virtual void write(ofstream& file) const = 0;
	virtual void print() = 0;
	virtual void edit() = 0;

	friend ofstream& operator<< (ofstream& file, const Base& object) 
	{
		object.write(file);
		return file;
	}

private:

};