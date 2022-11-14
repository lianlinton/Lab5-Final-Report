/**
 * Stores info of one discussion
 */
#pragma once
#include "dateTime.cpp"
#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Discussion{

    public:
        Discussion(){

        };
        void setPost(string p){
            post = p;
        };

        void setStudent(Student* s){
            student = *s;
        };

        void setDate(string d){
            /*stringstream ss(d);
            string dateString;
            string timeString;
            getline(ss, dateString, ' ');
            date.setDate(dateString);
            getline(ss, timeString, ' ');*/
            date.setDateTime(d);
        };
        bool operator==(Discussion& other);
        bool operator!=(Discussion& other);
        bool operator>(Discussion& other);
        bool operator<(Discussion& other);
        bool operator>=(Discussion& other);
        bool operator<=(Discussion& other);
        DateTime getDateTime(){
            return date;
        };

        string getName(){
            return student.getFirstName() +  " " + student.getMiddleName() +  " " + student.getLastName();
        };

        string getText(){
            return post;
        };
        void print() {
            cout << student.getFirstName() <<  " " << student.getMiddleName() <<  " " << student.getLastName() <<  " " << endl;
            cout << "Date: " << date.toString() << endl;
            cout << post << endl;
            cout << setfill('-') << setw(50) << "\n" << endl;
        };
    private:
        Student student;
        //DateType date;
        DateTime date;
        string post;
};

bool Discussion::operator==(Discussion& otherf) {
    return getName() == otherf.getName();
}

bool Discussion::operator!=(Discussion& otherf) {
    return !(*this == otherf);
}

bool Discussion::operator>(Discussion& otherf) {
    return getName() > otherf.getName();
}

bool Discussion::operator<(Discussion& otherf) {
    return !(*this > otherf || *this == otherf);
}

bool Discussion::operator>=(Discussion& otherf) {
    return !(*this < otherf);
}

bool Discussion::operator<=(Discussion& otherf) {
    return !(*this > otherf);
}