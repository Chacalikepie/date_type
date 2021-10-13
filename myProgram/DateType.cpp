// Define member functions of class DateType.
// This is file DateType.cpp.

#include "DateType.h" // gain access to specification of class
#include <iostream>
using namespace std;

//The first constructor method to initialize a DateType object
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
DateType::DateType()
{
	year = 2000;
	month = 1;
	day = 1;
}


//The second constructor method to initialize a DateType object
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
DateType::DateType(int newMonth, int newDay, int newYear)
{
	if (IsValidDate(newMonth, newDay, newYear) == false) {
		cout << "Date is Invalid" << endl;
		cout << "Setting date to 1/1/2000" << endl;
		year = 2000;
		month = 1;
		day = 1;
	}
	else {
		year = newYear;
		month = newMonth;
		day = newDay;
	}
}



//A method to set a new date for the DateType object.
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//   do not change the date stored in the object and then return false.
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
//   and then return true.
bool DateType::SetDate(int newMonth, int newDay, int newYear)
{
	if (IsValidDate(newMonth, newDay, newYear) == true) {
		year = newYear;
		month = newMonth;
		day = newDay;
		return true;
	}
	else {
		return false;
	}
}

int DateType::MonthIs()
// Accessor function for data member month.
{
	return month;
}

int DateType::YearIs()
// Accessor function for data member year.
{
	return year;
}


int DateType::DayIs()
// Accessor function for data member day.
{
	return day;
}


void DateType::ReadDate()
{
	cout << endl
		<< "Read in the information of a date: ";

	cout << endl << "The month is: ";
	cin >> month;
	cout << endl << "The day is: ";
	cin >> day;
	cout << endl << "The year is: ";
	cin >> year;

	while (IsValidDate(month, day, year) == false) {
		cout << "Input date is not a valid date" << endl;
		cout << "Please enter a new date" << endl;

		cout << endl << "The month is: ";
		cin >> month;
		cout << endl << "The day is: ";
		cin >> day;
		cout << endl << "The year is: ";
		cin >> year;
	}

}

void DateType::PrintDate()
{
	//Implement your code here
	cout << month << "/" << day << "/" << year << endl;

}


int DateType::ComparedTo(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//  LESS, if self comes before aDate.
//  EQUAL, if self is the same as aDate.
//  GREATER, if self comes after aDate.
{
	if (year < aDate.YearIs()) {
		return LESS;
	}
	else if (year == aDate.YearIs()) {
		if (month < aDate.MonthIs()) {
			return LESS;
		}
		else if (month == aDate.MonthIs()) {
			if (day < aDate.DayIs()) {
				return LESS;
			}
			else if (day == aDate.DayIs()) {
				return EQUAL;
			}
			else {
				return GREATER;
			}
		}
		else {
			return GREATER;
		}
	}
	else {
		return GREATER;
	}
}

int DateType::ComparedCentury(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//	LESS, if the object itSelf comes before the century of aDate.
//	EQUAL, if the object itSelf is in the same century as aDate.
//	GREATER, if the object itSelf comes after the century of aDate.
{
	int Cent;	//DateType Century
	int aCent;	//aDate Century

	Cent = (year / 100) + 1;
	aCent = (aDate.YearIs() / 100) + 1;

	if (Cent < aCent) {
		return LESS;
	}
	else if (Cent == aCent) {
		return EQUAL;
	}
	else {
		return GREATER;
	}
}

void DateType::AdvanceDays(int NumDays)
{
	for (int a = 1; a <= NumDays; a = a + 1) {

		// Adding days
		day = day + 1;

		// Changing month if NumDays exceeds month limit
		// If the month is a month with 31 days, and days is above 31 then change month and day to correct date
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31) {
				month = month + 1;
				day = day - 31;
			}
			else {
				NumDays = NumDays;
			}
		}
		// If the month is a month with 30 days, and days is above 30 then change month and day to correct date
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) {
				month = month + 1;
				day = day - 30;

			}
			else {
				NumDays = NumDays;
			}
		}
		// If the month is Feb, and days is above 28 then change month and day to correct date
		// Since leap years affect Feb, this part accounts for leap years
		else {
			if ((year % 4 == 0) && (day > 29)) {
				month = month + 1;
				day = day - 29;

			}
			else if ((year % 4 != 0) && (day > 28)) {
				month = month + 1;
				day = day - 28;

			}
			else {
				NumDays = NumDays;
			}
		}

		//Changing year if month exceeds 12
		if (month > 12) {
			year = year + 1;
			month = month - 12;
		}
		else {
			NumDays = NumDays;
		}
	}

}

void DateType::BackDays(int NumDays)
{
	for (int a = 1; a <= NumDays; a = a + 1) {

		// Subtract days
		day = day - 1;

		// Changing month if NumDays exceeds month limit
		// Adjusting month if day goes into a month with 31 days
		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11 || month == 1) {
			if (day < 1) {
				month = month - 1;
				day = day + 31;
			}
			else {
				NumDays = NumDays;
			}
		}
		// Adjusting month if day goes into a month with 30 days
		else if (month == 5 || month == 7 || month == 10 || month == 12) {
			if (day < 1) {
				month = month - 1;
				day = day + 30;

			}
			else {
				NumDays = NumDays;
			}
		}
		// Adjusting month if day goes into a month with 29 days
		// Since leap years affect Feb, this part accounts for leap years
		else {
			if ((year % 4 == 0) && (day < 1)) {
				month = month - 1;
				day = day + 29;

			}
			else if ((year % 4 != 0) && (day < 1)) {
				month = month - 1;
				day = day + 28;

			}
			else {
				NumDays = NumDays;
			}
		}

		//Changing year if month goes below 1
		if (month < 1) {
			year = year - 1;
			month = month + 12;
		}
		else {
			NumDays = NumDays;
		}
	}

}

bool DateType::IsValidDate(int newMonth, int newDay, int newYear)
{
	//If year is not negative and is not a leap year
	if ((newYear > 0) && (newYear % 4 != 0)) {
		if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) {
			if ((newDay > 0) && (newDay <= 31)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
			if ((newDay > 0) && (newDay <= 30)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (newMonth == 2) {
			if ((newDay > 0) && (newDay <= 28)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	//If year is not negative and is not a leap year
	else if ((newYear > 0) && (newYear % 100 == 0)) {
		if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) {
			if ((newDay > 0) && (newDay <= 31)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
			if ((newDay > 0) && (newDay <= 30)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (newMonth == 2) {
			if ((newDay > 0) && (newDay <= 28)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	//If year is not negative and is a leap year
	else if ((newYear > 0) && (newYear % 4 == 0)) {
		if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) {
			if ((newDay > 0) && (newDay <= 31)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
			if ((newDay > 0) && (newDay <= 30)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (newMonth == 2) {
			if ((newDay > 0) && (newDay <= 29)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	//If year is negative
	else
		return false;
}

void DateType::SetRandomDate() {
	// Set random year 1 < year < 9999
	year = rand() % 9999 + 1;

	// Choosing random month and day on non-leap years
	if ((year % 4 != 0) || (year % 100 == 0)) {
		month = rand() % 12 + 1;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			day = rand() % 31 + 1;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			day = rand() % 30 + 1;
		}
		else if (month == 2) {
			day = rand() % 28 + 1;
		}
	}
	// Choosing random month and day on leap years
	else if (year % 4 == 0) {
		month = rand() % 12 + 1;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			day = rand() % 31 + 1;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			day = rand() % 30 + 1;
		}
		else if (month == 2) {
			day = rand() % 29 + 1;
		}
	}
}

bool DateType::operator>(const DateType & aDate)
{
	if (year > aDate.year) {
		return true;
	}
	else if (year == aDate.year) {
		if (month > aDate.month) {
			return true;
		}
		else if (month == aDate.month) {
			if (day > aDate.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool DateType::operator<(const DateType & aDate)
{
	if (year < aDate.year) {
		return true;
	}
	else if (year == aDate.year) {
		if (month < aDate.month) {
			return true;
		}
		else if (month == aDate.month) {
			if (day < aDate.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool DateType::operator==(const DateType & aDate)
{
	if (year == aDate.year) {
		if (month == aDate.month) {
			if (day == aDate.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool DateType::operator!=(const DateType & aDate)
{
	if (year == aDate.year) {
		if (month == aDate.month) {
			if (day == aDate.day) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
}

bool DateType::operator>=(const DateType & aDate)
{
	if (year > aDate.year) {
		return true;
	}
	else if (year == aDate.year) {
		if (month > aDate.month) {
			return true;
		}
		else if (month == aDate.month) {
			if (day > aDate.day) {
				return true;
			}
			else if (day == aDate.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool DateType::operator<=(const DateType & aDate)
{
	if (year < aDate.year) {
		return true;
	}
	else if (year == aDate.year) {
		if (month < aDate.month) {
			return true;
		}
		else if (month == aDate.month) {
			if (day < aDate.day) {
				return true;
			}
			else if (day == aDate.day) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

DateType DateType::operator+(int numDays)
{
	//Make a variable d2 to be the same as DateType contents
	DateType d2(month, day, year);

	//Adjust d2 to advance i days
	d2.AdvanceDays(numDays);
	return d2;
}

DateType DateType::operator-(int numDays)
{
	//Make a variable d2 to be the same as DateType contents
	DateType d2(month, day, year);

	//Adjust d2 to go back i days
	d2.BackDays(numDays);
	return d2;
}

int DateType::operator-(const DateType & aDate)
{
	//temp will store the date2
	DateType temp(aDate.month, aDate.day, aDate.year);

	//This will be the difference in days
	int daycount = 0;

	/*
	If date1 is less than day2 using the compared to member function,
	we will use BackDays one day at a time until the two days are equal.
	*/
	if (ComparedTo(temp) == LESS) {
		while (ComparedTo(temp) == LESS) {
			temp.BackDays(1);
			daycount++;	//Each time the days go back
		}
		return -1 * daycount;
	}
	/*
	If date1 is greater than day2, advance days on date2 until the two dates are equal.
	daycount will keep track of each time advance days occurs.
	*/
	else if (ComparedTo(temp) == GREATER) {
		while (ComparedTo(temp) == GREATER) {
			temp.AdvanceDays(1);
			daycount++;
		}
		return daycount;
	}
	//If dates are the same
	else {
		return 0;
	}
}

ostream & operator<<(ostream & output, const DateType & aDate)
{
	//If else statement for detecting if it's outputting from a DateType object or file
	if (&output == &cout) {
		output << aDate.month << "/" << aDate.day << "/" << aDate.year << endl;
	}
	else {
		output << aDate.month << " " << aDate.day << " " << aDate.year << endl;
	}
	return output;
}

istream & operator>>(istream & input, DateType & aDate)
{
	if (&input == &cin) {
		aDate.ReadDate();
	}
	else {
		//Make temporary variables to store day month and year from the file
		int tempM; int tempD; int tempY;
		input >> tempM >> tempD >> tempY;

		//Use the set date function
		aDate.SetDate(tempM, tempD, tempY);
	}
	return input;
}