#include <iostream> 
using namespace std; 

int main(void) { 
	
	int number;
	long sum = 0;
	
	cout << "enter the max value\n";
	cin >> number;
	
	for (int i = 1; i <= number; i++)
		sum += i;
		
	cout << sum;
	return 0; 
} 