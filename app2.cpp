#include <iostream>
#include "announcementMenu.cpp"
#include "discussionMenu.cpp"
#include "studentMenu.cpp"
#include "courseMenu.cpp"
#include "assignmentMenu.cpp"
#include "loginMenu.cpp"
using namespace std;
int main() {
    /*Announcement announce;

    announce.setTitle("Hi");
    announce.setDateType("10/10/10");
    announce.setText("Posted.");

    announce.print();

    AnnounceMenu announce;

    announce.doList();
    announce.doView();
    announce.doEdit();
    announce.doAdd();
    announce.doList();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;*/
    //announce.doDelete();
    //announce.doList();
    //cout << "Success!" << endl;
    /*DiscussMenu discussion;
    discussion.doList();
    //discussion.doView();
    //discussion.doEdit();
    //discussion.doAdd();
    discussion.doDelete();
    cout << "NEW APPARENTL " << endl;
    discussion.doList();
    StudentMenu men; 
    men.doList();*/

    CourseMenu men;
    men.doList();
    return 0;
}