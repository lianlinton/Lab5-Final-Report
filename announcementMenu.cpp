#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "menu.cpp"
#include "announcementMenu.h"
//#include "unorderedLinkedList.h"
//#include "discussion.h"

using namespace std;

AnnounceMenu::AnnounceMenu()
    : Menu("Announcement Menu") {
    addOption("1) Select an announcement from the list of announcements"); 
    addOption("3) Add announcement");   
    addOption("4) Edit announcement"); 
    addOption("5) Delete announcement");
    addOption("x) Exit");


    pAnnounce = nullptr;
    list = new LinkedStackType<Announcement>();
    //list->initializeStack();
    init();
};

AnnounceMenu::~AnnounceMenu() {
    delete list;
    inFile.close();
}

void AnnounceMenu::init() {
    inFile.open(ANNOUNCE_DATA);
    // ios::in | ios::out | ios::app

    string title;
    string date; // convert previous date string to class DateType
    string text;

    //string line = "";
    //int count = 0;
    while (!inFile.eof()){
        getline(inFile, title);
        getline(inFile, date);
        getline(inFile, text);
        Announcement announce;
        announce.setTitle(title);
        announce.setDateType(date);
        announce.setText(text);
        //nnouncement *p = &announce;
        list->push(announce);
    }
    //getline(inFile, line);
    /*while (getline(inFile, line)) {
        stringstream ss(line);
        if (count == 0){
            getline(ss, title, '\r');
            count++;
        } else if (count == 1){
            getline(ss, date, '\r');
            count++;
        } else if (count == 2){
            getline(ss, post, '\r');
            Announcement discuss;
            discuss.setUser(user);
            discuss.setDate(date);
            discuss.setPost(post);
            Announcement *p;
            p = &discuss;
            list->push(p);
            count = 0;
        }
    }*/
    inFile.clear();
}

void AnnounceMenu::doList() {
    cout << " *********** Announcement ***********" << endl;
    LinkedStackType<Announcement> copy = *list;
    while (!copy.isEmptyStack()){
        Announcement a = copy.top();
        a.print();
        copy.pop();
    }
}

void AnnounceMenu::doView() {
    if (pAnnounce == nullptr) {        
        doList();
    }
    pAnnounce->print();
}

void AnnounceMenu::doEdit(){
    if (pAnnounce == nullptr) {
        doList();
    }
    Announcement* p = pAnnounce;

    string temp;
    cout << "Enter new title (" + p->getTitle() + "): ";
    cin.ignore();
    getline(cin, temp);

    if (!temp.empty()) {
        p->setTitle(temp);
    }
    
    p->print();
}

void AnnounceMenu::doAdd(){
    string title;
    string date;
    string text;
    Announcement announce;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> date;
    cout << "Enter message: ";
    cin >> text;
    announce.setTitle(title);
    announce.setDateType(date);
    announce.setText(text);
    //Announcement *p = &announce;
    list->push(announce);
}

void AnnounceMenu::doDelete() {
    //Add operator overloading !!!!!!!
    if (pAnnounce == nullptr) {
        doList();
    }
    LinkedStackType<Announcement> copy = *list;
    LinkedStackType<Announcement> newRev;
    while (!copy.isEmptyStack()){
        /*
        if (copy.top() != *pAnnounce){
            Announcement a = copy.top();
            newRev.push(a);
            copy.pop();
        }
        */
    }
    /*//Reverse it 
    LinkedStackType<Announcement> newDel;
    while (!newRev.isEmptyStack()){
        Announcement a = copy.top();
        newDel.push(a);
        newRev.pop();
    }
    list = &newRev;
    */
}
