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

int daysBetween(Date d1, Date d2) {

	if (d2.day < d1.day && d2.month == d1.month || 
		d2.month < d1.month && d2.year == d1.year ||
		d2.year < d1.year) {
			
		return -1;
	} else {
		if (d2.month == d1.month && d2.year == d1.year) {
			
			return d2.day - d1.day;
		} else {
			if (d2.year == d1.year) {
				
				return dayOfYear(d2) - dayOfYear(d1);
			} else {
				int result = dayOfYear(d2), daysInYear;
				
				if (isLeap(d1.year))
					daysInYear = 366;
				else 
					daysInYear = 365;
					
				result += daysInYear - dayOfYear(d1);
								
				for (int i = d1.year + 1; i < d2.year; i++)
					for (int j = 1; j <= 12; j++)
						result += monthLength(i, j);
					
				return result;
			}
		}
	}
}


int main(void) {
	
	Date since, till;
	
	cout << "Enter first date (y m d): \n";
	cin >> since.year >> since.month >> since.day;
	
	cout << "Enter second date (y m d): \n";
	cin >> till.year >> till.month >> till.day;
	
	cout << daysBetween(since,till) << endl;
	
	return 0;
}