#pragma once
#include <string>
using namespace std;

class DateType {
public:
	DateType(int m = 0, int d = 0, int y = 0);
	~DateType() {};

	//Mutator functions
	void setMonth(int m) { month = m; };
	void setDay(int d) { day = d; };
	void setYear(int y) { year = y; };

	//string format mm/dd/yyyy
	void setDate(string);

	//Accessor functions
	int getMonth() const { return month; };
	int getDay() const { return day; };
	int getYear() const { return year; };
	DateType& getDate();

	string toString(); //mm-dd-yyyy
	bool isEmpty() {
		return month == 0 && day == 0 && year == 0;
	};

	//Overloaded operators
	bool operator>(const DateType&) const;
	bool operator<(const DateType&) const;
	bool operator>=(const DateType&) const;
	bool operator<=(const DateType&) const;
	bool operator==(const DateType&) const;
	bool operator!=(const DateType&) const;

protected:
	int month;
	int day;
	int year;
};
