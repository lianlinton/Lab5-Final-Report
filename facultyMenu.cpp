/**
 * Initializes, views, adds, edits, and deletes from list of announcements
 */
#include "menu.h"
#include "facultyMenu.h"
#include "utils.cpp"

FacultyMenu::FacultyMenu()
    : Menu("Course Menu") {
    addOption("1) Faculty list");   // Lab 5 - sortBy any field in class Person
    addOption("2) View faculty contact");
    addOption("3) Add a faculty");
    addOption("4) Edit a faculty");
    addOption("5) Delete a faculty");
    addOption("x) Exit");

    list = new vector<Faculty*>();
    init();
};

FacultyMenu::~FacultyMenu() {
    for (int i = 0; i < (int) list->size(); i++) {
        delete list->at(i);
    }
    delete list;
    inFile.close();
}

void FacultyMenu::init() {
    inFile.open(FACULTY_DATA);
    
    // TODO - load FACULTY_DATA

    inFile.clear();
}

void FacultyMenu::doList() {
    // TODO
}

void FacultyMenu::doView() {
    // TODO
}

void FacultyMenu::doAdd() {
    // TODO
}

void FacultyMenu::doEdit() {
    // TODO
}

void FacultyMenu::doDelete() {
    // TODO
}