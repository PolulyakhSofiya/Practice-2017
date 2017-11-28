#include <iostream>

using namespace std;

int main () {

	int year;
	bool isLeap;
	cin >> year;
	
	
	if (year % 4 != 0)
		isLeap = false;
	else
		if (year % 100 != 0)
			isLeap = true;
		else 
			if (year % 400 != 0)
				isLeap = false;
			else 
				isLeap = true;

	if (isLeap)
		cout << "The year " << year << " is a leap";
	else
		cout << "The year " << year << " is a common";
	return 0;
  
}