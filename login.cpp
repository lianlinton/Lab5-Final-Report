/**
 * Stores info of one login
 */
#pragma once
#include <string>
#include <iomanip>
#include <fstream>
#include "login.h"

using namespace std;

//Default constructor
Login::Login(){
	username = "";
	password = "";
}

//Overloaded to allow sorting
//Operators compare their username
bool Login::operator>=(const Login& otherL) const {
	return (username >= otherL.username);
}
bool Login::operator==(const Login& otherL) const {
	return (username == otherL.username);
}