#pragma once

#include <string>

using std::string;

class Contact
{
	int id;
	string name;
	double salary;

public:
	Contact(int id, string name, double salary);

	int getId();
	string getName();
	double getSalary();
};

