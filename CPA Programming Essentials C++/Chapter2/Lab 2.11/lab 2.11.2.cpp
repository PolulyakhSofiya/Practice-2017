#include <iostream>
using namespace std;

int main() {
	
	struct Time {
		int hours;
		int minutes;
	};
	
	Time start_time;
	Time end_time;
	Time result;
	
	do {
		
		cout << "Please enter the start time\n";
		cin >> start_time.hours;
		cin >> start_time.minutes;
		
		cout << "Please enter the end time\n";
		cin >> end_time.hours;
		cin >> end_time.minutes;
		
	} while (start_time.hours > 23 || start_time.minutes > 59 || end_time.hours > 23 
		|| end_time.minutes > 59 || start_time.hours > 23 || 
		start_time.hours > end_time.hours ||  start_time.hours == end_time.hours && 
		start_time.minutes >= end_time.minutes);
		
	if(end_time.minutes < start_time.minutes) {
		
		end_time.minutes += 60;
		end_time.hours -= 1;
	}
	
	result.minutes = end_time.minutes - start_time.minutes;
	result.hours = end_time.hours - start_time.hours;
		
	cout << result.hours << ":" << result.minutes;
	
	return 0;
}