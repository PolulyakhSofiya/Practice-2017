#include <iostream>
using namespace std;

int main() {
	
	struct Time {
		int hours;
		int minutes;
	};
	
	Time time;
	int minutes;
	
	cout << " Please enter the hours value\n";
	do {
		cin >> time.hours;	
	} while (time.hours < 0 || time.hours > 23);

	cout << " Please enter the minute value\n";
	do {
		cin >> time.minutes;	
	} while (time.minutes < 0 || time.minutes > 59);
	
	cout << " Please enter the manute value you want to add\n";
	cin >> minutes;
	
	time.minutes += minutes;
	
	while (time.minutes > 59 || time.hours > 23)
	{
		if (time.minutes > 59)
		{
			time.minutes -= 60;
			time.hours += 1;
		}
		
		if (time.hours > 23)
		{
			time.hours -= 24;	
		}
	}
	
	if (time.minutes > 10)
		cout << time.hours << ":" << time.minutes;
	else 
		cout << time.hours << ":0" << time.minutes;
	
	return 0;
}