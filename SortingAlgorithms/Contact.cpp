#include "pch.h"
#include "Contact.h"

Contact::Contact(int id, string name, double salary)
{
	this->id = id;
	this->name = name;
	this->salary = salary;
}

int Contact::getId()
{
	return this->id;
}

string Contact::getName()
{
	return this->name;
}

double Contact::getSalary()
{
	return this->salary;
}
