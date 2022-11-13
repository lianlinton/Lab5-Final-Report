#pragma once
#include "person.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student: public Person{
public:
	Student(){};
	Student(int id, string mName, string p2, const Person&);
	~Student(){};

	//Overloaded operators
	bool operator==(const Student&) const;
	bool operator!=(const Student&) const;
	bool operator>(const Student&) const;
	bool operator<(const Student&) const;
	bool operator>=(const Student&) const;
	bool operator<=(const Student&) const;

private:
   

};
