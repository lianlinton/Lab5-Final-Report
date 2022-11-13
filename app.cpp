#include <iostream>
#include "announcementMenu.cpp"
#include "discussionMenu.cpp"
using namespace std;
int main() {
    /*Announcement announce;

    announce.setTitle("Hi");
    announce.setDateType("10/10/10");
    announce.setText("Posted.");

    announce.print();*/

    /*AnnounceMenu announce;

    announce.doList();*/

    DiscussMenu discussion;
    discussion.doList();
    return 0;
}