#pragma once

#include <string>

using std::string;

class Contact
{
	int id;
	string name;
	double salary;

public:
	Contact(int id, string name, double salary) {
		this->id = id;
		this->name = name;
		this->salary = salary;
	}

	int get_id() {
		return this->id;
	}

	string get_name() {
		return this->name;
	}

	void set_name(string name) {
		this->name = name;
	}

	double get_salary() {
		return this->salary;
	}

	void set_salary(double salary) {
		this->salary = salary;
	}
};

