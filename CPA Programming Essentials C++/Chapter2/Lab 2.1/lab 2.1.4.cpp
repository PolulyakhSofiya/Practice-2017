#include <iostream>
using namespace std;

int main() {
	
	int year, month, day;
	cin >> year;
	cin >> month;
	cin >> day;
	
	month -= 2;
	
	if (month <= 0)
	{
		month += 12;
		year -= 1;
	}
	
	month = month * 83 / 32;
	
	month = month + day + year + year / 4 - year / 100 + year / 400;
	
	cout << month % 7;
	
	return 0;
}