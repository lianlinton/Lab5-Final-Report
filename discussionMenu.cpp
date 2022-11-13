#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "menu.cpp"
#include "discussionMenu.h"
#include "unorderedLinkedList.h"
#include "discussion.h"
#include "linkedListIterator.h"
#include "utils.h"
#include "student.h"
//#include "discussion.h"

using namespace std;

DiscussMenu::DiscussMenu()
    : Menu("Discussion Menu") {
    addOption("1) List discussion"); 
    addOption("2) View discussion post");
    addOption("3) Add post");
    addOption("4) Edit");
    addOption("5) Delete");
    addOption("x) Exit");

    pDiscuss = new Discussion();
    list = new UnorderedLinkedList<Discussion>();
    list->initializeList();
    init();
};

DiscussMenu::~DiscussMenu() {
    delete list;
    inFile.close();
}

void DiscussMenu::init() {
    inFile.open(DISCUSS_DATA);
    // ios::in | ios::out | ios::app

    string user;
    string date; // convert previous date string to class DateType
    string post;

    string line = "";
    int count = 0;
    //getline(inFile, line);
    while (!inFile.eof()){
        getline(inFile, user);
        getline(inFile, date);
        getline(inFile, post);
        Discussion d;
        Student s;
        setStudent(&s, user);
        d.setStudent(&s);
        d.setDate(date);
        d.setPost(post);
        list->insertLast(d);
        pDiscuss = &d;
    }
    inFile.clear();
    //pDiscuss = &(list->back());
}

void DiscussMenu::setStudent(Student* s, string name){
    int pos, i = 0;
    string names[3];
    do {
        pos = name.find(" ");
        if (pos > 0){
            names[i++] = name.substr(0, pos);
            name = name.substr(pos + 1);
        } else {
            names[2] = name;
        }
    } while (pos > 0);
    s->setFirstName(names[0]);
    s->setMiddleName(names[1]);
    s->setLastName(names[2]);
}

void DiscussMenu::doEdit(){
   if (pDiscuss == nullptr) {
        doList();
    } 
    Discussion* p = pDiscuss;

    string temp;
    cout << "Enter new user (" + p->getName() + "): ";
    cin.ignore();
    getline(cin, temp);

    if (!temp.empty()) {
        Student s;
        setStudent(&s, temp);
        p->setStudent(&s);
    }
    
    p->print();
}

void DiscussMenu::doList() {
    cout << " ****** Discussion ******" << endl;
    Discussion d;
    LinkedListIterator<Discussion> it;
    for (it = list->begin(); it != list->end(); ++it){
        ((Discussion*) &(*it))->print();
        /*d = *it;
        cout << d.getName() << endl;
        cout << d.getDateTime().toString() << endl;
        cout << d.getText() << endl;*/
        cout << setfill('-') << setw(50) << "\n";
    }
    pDiscuss = (Discussion*) &(*list->end());
    cout << endl;
}

void DiscussMenu::doView() {
    if (pDiscuss == nullptr) {        
        doList();
    }
    cout << "***** View Slected Discussion ****" << endl;
    Discussion d = getSelectedPost();
    d.print();
    //pCourse->printCourseInfo();
}

void DiscussMenu::doAdd(){
    cout << "***** View Slected Discussion ****" << endl;   
    string user;
    string date; // convert previous date string to class DateType
    string post;

    Discussion d;
    cout << "Enter student name: ";
    cin >> user;
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> date;
    cout << "Enter message: ";
    cin >> post;
    Student s;
    setStudent(&s, user);
    d.setStudent(&s);
    d.setDate(date);
    d.setPost(post);
    list->insertLast(d);
    pDiscuss = &d;
}

void DiscussMenu::doDelete() {
    if (pDiscuss == nullptr) {
        doList();
    }
    else {
        //list->deleteNode(*pDiscuss);
    }
}

