#include "menu.cpp"
#include "studentMenu.h"
#include "student.h"
#include "utils.h"
#include "studentType.cpp"
#include "linkedQueue.h"
#include <typeinfo>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

StudentMenu::StudentMenu()
    : Menu("Student Menu") {
    addOption("1) Student list");   // Lab 5 - sortBy any field in class Student and Person
    addOption("2) View student details");
    addOption("3) Add a student");
    addOption("4) Edit a student");
    addOption("5) Delete a student");
    addOption("x) Exit");
    
    list = new LinkedQueueType<Student*>();
    init();
};

StudentMenu::~StudentMenu() {
    delete list;
    inFile.close();
}

void StudentMenu::init() {    
    inFile.open(STUDENT_DATA);
    string id;
	string firstName; 
	string lastName; 
	string address; 
	string city; 
	string state; 
	string zip; 
	string phone;
	string email;
	//2,Yong,Gao,CS,43600 Mission Blvd.,Fremont,CA,94538,ygao@ohlone.edu,510-659-6000
	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, address, ',');
		getline(ss, city, ',');
		getline(ss, state, ',');
		getline(ss, zip, ',');
		getline(ss, email, ',');
		getline(ss, phone, ',');
		//cout << phone << endl;
		Student* _student = new Student();
		int num = stoi(id);
		_student->setId(num);
		_student->setFirstName(firstName);
		_student->setLastName(lastName);
		_student->setAddress(address);
		_student->setCity(city);
		_student->setState(state);
		_student->setZip(zip);
		_student->setEmail(email);
		_student->setPhone(phone);
		list->addQueue(_student);
	}
    inFile.clear();
}

void StudentMenu::doList() {
    cout << " *********** Student ***********" << endl;
    LinkedQueueType<Student*> copy = *list;
    while (!copy.isEmptyQueue()){
        copy.front()->toString();
        copy.deleteQueue();
    }
}

void StudentMenu::doView() {
    list->front()->toString();
}

void StudentMenu::doAdd() {
    string id;
	string firstName; 
	string lastName; 
	string address; 
	string city; 
	string state; 
	string zip; 
	string phone;
	string email;

    cout << "Enter ID: ";
    cin.ignore();
    getline(cin, id);
	cout << "Enter first name: ";
	//cin.ignore();
	getline(cin, firstName);
	cout << "Enter last name: ";
	//cin.ignore();
	getline(cin, lastName);
	cout << "Enter address: ";
	//cin.ignore();
	getline(cin, address);
	cout << "Enter city: ";
	getline(cin, city);
	cout << "Enter state: ";
	getline(cin, state);
	cout << "Enter zip: ";
	getline(cin, zip);
	cout << "Enter phone: ";
	getline(cin, phone);
	cout << "Enter email: ";
	getline(cin, email);

	Student* _student = new Student();
    int num = stoi(id);
    _student->setId(num);
    _student->setFirstName(firstName);
    _student->setLastName(lastName);
    _student->setAddress(address);
    _student->setCity(city);
    _student->setState(state);
    _student->setZip(zip);
    _student->setEmail(email);
    _student->setPhone(phone);
    list->addQueue(_student);
    pItem = _student;
}

void StudentMenu::doEdit() {
    if (pItem == nullptr) {
        doList();
    }
    Student* p = pItem;

    string temp;
    cout << "Enter new address (" + p->getAddress() + "): ";
    cin.ignore();
    getline(cin, temp);

    if (!temp.empty()) {
        p->setAddress(temp);
    }
    
    p->toString();
}

void StudentMenu::doDelete() {
    if(!list->isEmptyQueue()){
        list->deleteQueue();
    }
    doList();
}
/*
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
    selectedPost(announce);
}

void AnnounceMenu::doDelete() {
    //Add operator overloading !!!!!!!
    if (pAnnounce == nullptr) {
        doList();
    }
    list->pop();
    LinkedStackType<Announcement> newRev;
    while (!copy.isEmptyStack()){
        if (copy.top() != *pAnnounce){
            Announcement a = copy.top();
            newRev.push(a);
            copy.pop();
        }
    }
    //Reverse it 
    LinkedStackType<Announcement> newDel;
    while (!newRev.isEmptyStack()){
        Announcement a = copy.top();
        newDel.push(a);
        newRev.pop();
    }
    list = &newRev;
    
}
*/