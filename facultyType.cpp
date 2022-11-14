/**
 * Stores info of one faculty
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "faculty.h"

using namespace std;

//Default constructor
//Implicitly calls PersonType's default constructor
Faculty::Faculty()
	: Person() {
	setId(-1); // lab 6 facultyId use Person::id
	departmentName = "NoDepart";
}
//Parameterized constructor
//Uses a PersonType object to easily initialize the inherited members by
//calling the base class copy constructor
Faculty::Faculty(int id, string d, const Person& personData)
	: Person(personData) {
	setId(id);
	departmentName = d;
}

bool Faculty::operator==(const Faculty& otherF) const{
	return getId() == otherF.getId();
}
bool Faculty::operator!=(const Faculty& otherF) const{
	return !(*this == otherF);
}

bool Faculty::operator>(const Faculty& otherF) const{
	return getId() > otherF.getId();
}
bool Faculty::operator<(const Faculty& otherF) const{
	return !(*this > otherF || *this == otherF);
}
bool Faculty::operator>=(const Faculty& otherF) const{
	return !(*this < otherF);
}
bool Faculty::operator<=(const Faculty& otherF) const{
	return !(*this > otherF);
}
