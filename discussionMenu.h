#pragma once
#include <fstream>
#include <vector>
#include "discussion.h"
#include "menu.h"
#include "unorderedLinkedList.h"

using namespace std;

const string DISCUSS_DATA = "discussions.dat";

enum DISCUSSION_MENU_OPTION {
	DISCUSS_LIST='1',
	DISCUSS_VIEW='2',
	DISCUSS_ADD='3',
	DISCUSS_EDIT='4',
	DISCUSS_DELETE='4',
	DISCUSS_EXIT='x' 
};

class DiscussMenu : public Menu {
public:
	DiscussMenu();
	~DiscussMenu();

	void doList();
	void doView();
	void doDelete();
	void doEdit();
	void doAdd();

	Discussion& getSelectedPost() {
		return *pDiscuss;
	};

	bool isSelectedPost() const {
		return pDiscuss != nullptr;
	};
	void init();
	void setStudent(Student* s, string name);
	
private:
	void selectedPost(Discussion& c) {
		pDiscuss = &c;
	};

	fstream inFile;
	Discussion* pDiscuss;
	LinkedListType<Discussion> *list;
};