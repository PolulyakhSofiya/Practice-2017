#include <iostream>
using namespace std;

int main() {
	long value = 1;
	int number = -1;
	
	do
	{
		cout << "Please enter the odd value > 1";
		cin >> number;
		cout << "\n";
	}
	while (number < 1 || number % 2 == 0);
	
	cout << number * number - 2 * number + 2;
	return 0;
}