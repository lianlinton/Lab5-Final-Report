#pragma once
#include <string>
#include "menu.h"
#include "course.h"
#include "unorderedArrayListType.h"

using namespace std;

class CourseListType : public UnorderedArrayListType<Course> {

public:
	CourseListType();

	Course** sortBy(UnorderedArrayListType<Course*> list);
	Course* at(int location);
	Course* find(string searchName);
	void print();
	void sort(bool ascending, Course* list[]);

private:
	bool ascending; // use to toggle sortBy ascending and descending order
	void initFieldIndex();
	Menu fieldIndexMenu;

};
