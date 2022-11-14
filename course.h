/**
 * Stores details of one course
 */
#pragma once
#include "faculty.h"
#include "dateTime.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Course {
public:
	Course();
	~Course();

	//Mutator functions
	void setTerm(string t) { term = t; };
	void setYear(int y) { year = y; };
	void setStartDate(string s) { startDate.setDate(s); };
	void setEndDate(string e) { endDate.setDate(e); };
	void setName(string n) { name = n; };
	void setSection(string s) { section = s; };
	void setId(string i) { id = i; };
	void setMeetDays(string m) { meetDays = m; };
	void setLocation(string l) { location = l; };
	void setMeetInfo(string m) { meetInfo = m; };
	void setInstructor(string name) { instructor.setLastName(name); };
	void setUnits(int u) { units = u; };


	string getName() const {
		return name;
	};

	string getSection() const {
		return section;
	};

	string getTerm() const {
		return term;
	};

	int getYear() const {
		return year;
	};

	//Return the course information as a string in CSV format
	string getCourseInfoCSV();
	//Print to console the course information in nice formatting
	void printCourseInfo();

	
	//Overloaded operators
	bool operator>=(const Course&) const;
	bool operator<=(const Course&) const;
	bool operator<(const Course&) const;
	bool operator>(const Course&) const;
	bool operator==(const Course&) const;
	bool operator!=(const Course&) const;

	static int fieldIndex;

private:
     string term;
	 int year;
	 DateTime startDate;
	 DateTime endDate;
	 string name;
	 string section;
 	 string id;
 	 string meetDays;
	 string location;
	 string meetInfo;
	 Faculty instructor;
	 int units;


};

