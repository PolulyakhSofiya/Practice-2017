#include <iostream>
using namespace std;

int main(void) {
	
	bool answer;
	int value;
	
	cout << "Please enter a value: ";
	cin >> value;
	
	answer = (value >= 0 && value < 10)|(value * 2 < 20 && value - 2 > -2)|
		(value / 1 > 1 && value / 2 < 10)|(value == 111);
	
	cout << (answer ? "That's true!" : "That's false!") << endl;
	return 0;
}