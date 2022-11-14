/**
 * Stores info of one student
 */
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "person.h"
#include "student.h"

using namespace std;

//Default constructor
//Implicitly calls PersonType's default constructor
Student::Student() {
	setId(-1);
}
//Parameterized constructor
//Uses a PersonType object to easily initialize the inherited members by
//calling the base class copy constructor
Student::Student(int id, string mName, string p2,
		const Person& personData):Person(personData){
	this->id = id;
}

//Overloaded to allow sorting
bool Student::operator==(const Student& otherS) const{
	return getId() == otherS.getId();
}
bool Student::operator!=(const Student& otherS) const{
	return !(*this == otherS);
}

bool Student::operator>(const Student& otherS) const{
	return getId() > otherS.getId();
}
bool Student::operator<(const Student& otherS) const{
	return !(*this > otherS || *this == otherS);
}
bool Student::operator>=(const Student& otherS) const{
	return !(*this < otherS);
}
bool Student::operator<=(const Student& otherS) const{
	return !(*this > otherS);
}


