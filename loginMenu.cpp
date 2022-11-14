/**
 * Initializes, views, adds, edits, and deletes from list of announcements
 */
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "loginMenu.h"
#include "login.cpp"
#include "menu.cpp"
#include "utils.cpp"

using namespace std;

LoginMenu::LoginMenu() 
    : Menu("Login Menu") {
    addOption("1) Login");
    addOption("2) Create New Account");
    addOption("3) Reset Password");
    addOption("x) Exit Login");

	// populate all users.csv
	initUserData();
};

LoginMenu::~LoginMenu() {
	inFile.close();
}

void LoginMenu::initUserData() {
	inFile.open(USERS_DATA);

	string  username;
	string  password;
	string  loginDateTime;
	string  logoutDateTime;

	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, loginDateTime, ',');
		getline(ss, logoutDateTime, ',');
		Login _login;
		_login.setUsername(username);
		_login.setPassword(password);

		users.push_back(_login);
	}

	inFile.clear();
}

bool LoginMenu::authenticate() {
	bool valid = false;
	for (int i = 0; i < (int) users.size(); i++) {
		if (login.getUsername() == users.at(i).getUsername() &&
			login.getPassword() == users.at(i).getPassword()) {			
			valid = true;
			break;
		}
	}
	return valid;
}

bool LoginMenu::doLogin() {
	int attempt = 0;
	do {
		string username, password;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		login.setUsername(username);
		login.setPassword(password);
		cout << endl;
		if (authenticate()) {
			// TODO: Lab 5 - save loginDateTime
			return true;
		}
	} while (++attempt < 3);
	return false;
}

void LoginMenu::doCreate() {
	// TODO: Lab 5 - create new user
}


void LoginMenu::doReset() {
	// TODO: Lab 5 - change password
}

void LoginMenu::doLogout() {
	// TODO: Lab 5 - save loginDateTime/logoutDateTime to USERS_DATA
};