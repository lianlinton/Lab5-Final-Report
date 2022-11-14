/**
 * Stores info of one login
 */
#pragma once
#include <string>

using namespace std;

class Login {
    public:
        Login();
        ~Login() {};

		//Mutator member functions
		void setUsername(string name) {
			username = name;
		};
		void setPassword(string pass) {
			password = pass;
		};
		
		//Accessor member functions
		string getUsername() const { return username; };
		string getPassword() const { return password; };
		

		//Overloaded operators
		bool operator>=(const Login&) const;
		bool operator==(const Login&) const;

    private:
       string username;
       string password;
};
