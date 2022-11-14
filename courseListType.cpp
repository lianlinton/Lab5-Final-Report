/**
 * stores list of courses
 */
#include <iostream>
#include "unorderedArrayListType.h"
#include "courseListType.h"
#include "course.h"
//#include "searchSortAlgorithms.h"

using namespace std;

CourseListType::CourseListType() {
	initFieldIndex();
}

void CourseListType::initFieldIndex(){
	fieldMenu.setName("Sort By Field Name");
	fieldMenu.addOption("term");
	fieldMenu.addOption("year");
	fieldMenu.addOption("startDate");
	fieldMenu.addOption("endDate");
	fieldMenu.addOption("name");
	fieldMenu.addOption("section");
	fieldMenu.addOption("Course Id");
	fieldMenu.addOption("meetDays");
	fieldMenu.addOption("location");
	fieldMenu.addOption("meetInfo");
	fieldMenu.addOption("instructor");
	fieldMenu.addOption("units");
}

void CourseListType::sortBy(bool ascending) {
	// do select fieldIndex
	Course::fieldIndex = fieldMenu.getInput();
	// do sortBy
	sort(ascending);
}

Course* CourseListType::at(int location) const {
	Course* p = nullptr;
	if (location < 0 || location >= length) {
		cout << "The location of the item to be retrieved is "
			<< "out of range" << endl;
	}
	else {
		p = &list[location];
	}
	return p;
} //end retrieveAt

Course* CourseListType::find(string value) {
	
	// TODO find value - fillout value of Course c
	Course c;
	
	int location = search(c);

	return  &list[location]; // check nullptr or address or course
}