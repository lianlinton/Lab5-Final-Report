/**
 * stores list of courese
 */
#pragma once
#include <string>
#include "menu.h"
#include "course.h"
//#include "searchSortAlgorithms.h"
#include "unorderedArrayListType.h"

using namespace std;

class CourseListType : public UnorderedArrayListType<Course> {

public:
	CourseListType();

	void sortBy(bool ascending);  // TODO true ascending; false descending
	Course* at(int location) const;
	Course* find(string searchName);

private:
	void initFieldIndex();
	Menu fieldMenu;

};
