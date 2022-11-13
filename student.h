#pragma once
#include "person.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student: public Person{
public:
	Student();
	Student(int id, string mName, string p2, const Person&);
	~Student(){};

	void setId(int id){
		this->id = id;
	};

	//Overloaded operators
	bool operator==(const Student&) const;
	bool operator!=(const Student&) const;
	bool operator>(const Student&) const;
	bool operator<(const Student&) const;
	bool operator>=(const Student&) const;
	bool operator<=(const Student&) const;

	void toString(){
		cout << "Id: " << id << endl;
		cout << "Name: " + firstName + " "+lastName+ "\nAddress: "+ address + ", " + city + " " +state+" " + zip << endl;
		cout << setfill('-') << setw(50) << "\n";
	}

private:
   int id;

};
