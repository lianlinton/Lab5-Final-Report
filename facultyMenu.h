/**
 * Initializes, views, adds, edits, and deletes from list of announcements
 */
#pragma once
#include <fstream>
#include <vector>
#include "menu.h"
#include "faculty.h"

using namespace std;

enum FACULTY_MENU_OPTION {
	FACULTY_LIST = '1',
	FACULTY_VIEW = '2',
	FACULTY_ADD = '3',
	FACULTY_EDIT = '4',
	FACULTY_DELETE = '5',
	FACULTY_EXIT = 'x'
};

const string FACULTY_DATA = "faculty_data.csv";

class FacultyMenu : public Menu {
public:
	FacultyMenu();
	~FacultyMenu();
	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	
	Faculty& getSelectedFaculty() {
		return *pFaculty;
	};
private:
	void selectedFaculty(Faculty& f) {
		pFaculty = &f;
	};

	fstream inFile;
	Faculty* pFaculty;
	void init();
	vector<Faculty*>* list;
};