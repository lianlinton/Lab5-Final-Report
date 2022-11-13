#pragma once
#include <fstream>
#include <vector>
#include "announcement.h"
#include "menu.h"
#include "linkedStack.h"

using namespace std;

const string ANNOUNCE_DATA = "announcements.dat";

enum ANNOUNCE_MENU_OPTION {
	ANNOUNCE_LIST='1',
	ANNOUNCE_VIEW='2',
	ANNOUNCE_ADD='3',
	ANNOUNCE_EDIT='4',
	ANNOUNCE_DELETE='5',
	ANNOUNCE_EXIT='x' 
};

class AnnounceMenu : public Menu {
public:
	AnnounceMenu();
	~AnnounceMenu();

	void doList();
	void doView();
    void doAdd();
    void doEdit();
	void doDelete();

	Announcement& getSelectedPost() {
		return *pAnnounce;
	};

	bool isSelectedPost() const {
		return pAnnounce != nullptr;
	};
	void init();
	
private:
	void selectedPost(Announcement& c) {
		pAnnounce = &c;
	};

	fstream inFile;
	Announcement* pAnnounce;
	LinkedStackType<Announcement> *list;
};