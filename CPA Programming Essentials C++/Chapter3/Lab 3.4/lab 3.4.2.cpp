#include <iostream>
using namespace std;

int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

int main(void) {
	
	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr,mo) << " ";
		cout << endl;
	}
	
	return 0;
}