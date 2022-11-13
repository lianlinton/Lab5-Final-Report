#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "dateTime.cpp"
using namespace std;

class Announcement{
    public:

        Announcement(){};
        void setTitle(string name) { title = name;};
        void setDateType(string dt) {postDate.setDate(dt); };
        void setText(string text){ this->text = text;};

        DateType getDate(){
            return postDate;
        };

        void print() {
            cout << title << endl;
            cout << "Date: " << postDate.toString() << endl;
            cout << text << endl;
            cout << setfill('-') << setw(50) << "\n";
        };

        string getTitle(){
            return title;
        };

        string getText(){
            return text;
        };

        //Overloaded operators
        bool operator>=(Announcement&);
        bool operator<=(Announcement&);
        bool operator<(Announcement&);
        bool operator>(Announcement&);
        bool operator==(Announcement&);
        bool operator!=(Announcement&);
    private:
        string title;
        DateType postDate;
        string text;
};

bool Announcement::operator==(Announcement& otherf) {
    return title == otherf.getTitle();
}

bool Announcement::operator!=(Announcement& otherf) {
    return !(*this == otherf);
}

bool Announcement::operator>(Announcement& otherf) {
    return getTitle() > otherf.getTitle();
}

bool Announcement::operator<(Announcement& otherf) {
    return !(*this > otherf || *this == otherf);
}

bool Announcement::operator>=(Announcement& otherf) {
    return !(*this < otherf);
}

bool Announcement::operator<=(Announcement& otherf) {
    return !(*this > otherf);
}



