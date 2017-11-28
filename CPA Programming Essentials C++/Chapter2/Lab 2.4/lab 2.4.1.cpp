#include <iostream>
using namespace std;

int main() {
	
	int value, counter = 0;
	
	do {
		cout << "Please enter the value that is > 0";
		cin >> value;
		cout << "\n";
	}
	while (value < 1);
	
	while (value)
	{
		if (value & 1)
			counter++;
		value >>= 1;
	}
	
	cout << counter;
	
	return 0;
}