#include <iostream>
using namespace std;

int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
	int year;
	int month;
	int day;
};

bool isLeap(int year) {
	
	if (year % 4 != 0)
		return false;
	else
		if (year % 100 != 0)
			return true;
		else 
			if (year % 400 != 0)
				return false;
			else 
				return true;
}

int monthLength(int year, int month) {

	if (year <= 0 || month <= 0 || month > 12)
		return 0;
	else {
		if (month == 2 && isLeap(year))
			return daysInMonth[month - 1] + 1;
		else 
			return daysInMonth[month - 1];
	}
}

int dayOfYear(Date date) {
	
	int result = date.day;
	
	for (int i = 1; i < date.month; i++)
		result += monthLength(date.year, i);

	return result;
}


int main(void) {
	
	Date d;
	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;

	return 0;
}