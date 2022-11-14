#pragma once
#include "person.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Faculty: public Person{
public:
	Faculty(){};
	Faculty(int id, string d, const Person&);
	~Faculty() {};

	//Mutator functions
	void setDepartment(string d) { departmentName = d;};

	//Accesor functions	
	string getDepartment() const{return departmentName;};

	//Overloaded operators
	bool operator==(const Faculty&) const;
	bool operator!=(const Faculty&) const;
	bool operator>(const Faculty&) const;
	bool operator<(const Faculty&) const;
	bool operator>=(const Faculty&) const;
	bool operator<=(const Faculty&) const;

private:
	 // int facultyId; // lab 5 add int id to class Person
	 string departmentName; 
};

