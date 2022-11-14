/**
 * Stores info of one course
 */
#include <string>
#include "course.h"
#include "faculty.h"
#include "dateTime.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int Course::fieldIndex = 7; // default Course::id

//Default constructor
Course::Course() {
	term ="";
	year = 0;
	name = "";
	section = "";
	id = "-1";
	meetDays = "";
	location = "";
	meetInfo = "";
	units = 0;
}


Course::~Course() {
	// todo
}

//Return the course information as a string in CSV format
string Course::getCourseInfoCSV() {
	return term + "," + to_string(year) + "," + startDate.toString() + ","
		+ endDate.toString() + "," + name + "," + section + ","
		+ id + "," + meetDays + "," + location + ","
		+ meetInfo + "," + instructor.getLastName() + "," + to_string(units);
}
//Print to console the course information in nice formatting
void Course::printCourseInfo()  {
	cout << left << setw(8) << term << setw(5) << year << setw(12) << startDate.getDate().toString() << setw(12)
		<< endDate.getDate().toString() << setw(32) << name << setw(10) << section
		<< setw(10) << id << setw(8) << meetDays << setw(10) << location
		<< setw(10) << meetInfo << setw(15) << instructor.getLastName() << endl
		<< setw(5) << units << endl;
}

bool Course::operator==(const Course& otherC) const{
	return false; // todo
}

bool Course::operator!=(const Course& otherC) const{
	return !(*this == otherC);
}

bool Course::operator>=(const Course& otherC) const{
	return !(*this < otherC);
}
bool Course::operator<=(const Course& otherC) const{
	return !(*this > otherC);
}
bool Course::operator<(const Course& otherC) const{
	bool retValue = false;
	if (fieldIndex == 1) {
		retValue = this->term < otherC.term;
	} else if (fieldIndex == 2) {
		retValue = this->year < otherC.year;
	} else if (fieldIndex == 3) {
		retValue = this->startDate < otherC.startDate;
	} else if (fieldIndex == 4) {
		retValue = this->endDate < otherC.endDate;
	} else if (fieldIndex == 5) {
		retValue = this->name < otherC.name;
	} else if (fieldIndex == 6) {
		retValue = this->term < otherC.term;
	} else if (fieldIndex == 7) {
		retValue = this->term < otherC.term;
	} else if (fieldIndex == 8) {
		retValue = this->term < otherC.term;
	}
	return retValue; // todo
}
bool Course::operator>(const Course& otherC) const{
	//If not less than or equal to, must be greater than
	return !(*this < otherC || *this == otherC);
}

