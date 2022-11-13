#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

#include <string>

using namespace std; 

class PersonType {

	// ....
public:
	PersonType()
	{
		firstName = "";
		lastName = "";
		address = "";
		phone = "";
		city = "";
		state = "";
		zip = "";
	}

	// Parameterized Constructor
	PersonType(string fname, string lname, string add, string phn, string c, string st, string z)
	{
		firstName = fname;
		lastName = lname;
		address = add;
		phone = phn;
		city = c;
		state = st;
		zip = z;
	}

	string getFirstName() //gets the inputted FirstName
	{
		return firstName;
	}
	void setFirstName(string fname) //returns as a string
	{
		firstName = fname;
	}

	string getLastName()//gets the inputted LastName
	{
		return lastName;
	}
	void setLastName(string lname) //returns as a string
	{
		lastName = lname;
	}

	string getAddress() //gets the inputted Address
	{
		return address;
	}
	void setAddress(string add) //returns as a string
	{
		address = add;
	}

	string getPhone() //gets the inputted Phone
	{
		return phone;
	}
	void setPhone(string phn)  //return as a string
	{
		phone = phn;
	}

	string getCity()  //gets the inputted City
	{
		return city;
	}
	void setCity(string c) //return as a string
	{
		city = c;
	}

	string getState() //gets the inputted State
	{
		return state;
	}
	void setState(string s) //returns as a string
	{
		state = s;
	}

	string getZip() //gets the inputted Zip
	{
		return zip;
	}
	void setZip(string z) //returns as a string
	{
		zip = z;
	}

	string toString(){
		return "Name: " + firstName + " "+lastName+ "\nAddress: "+ address + ", " + city + " " +state+" " + zip;
	}

	bool operator==(const PersonType&) const;
	bool operator!=(const PersonType&) const;
	// <=; <; >=; >
private:
	string firstName;
	string lastName;
	string address;
	string phone;
	string city;
	string state;
	string zip;
	// Other fields of the personType
};

#endif
