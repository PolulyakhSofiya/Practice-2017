#include <iostream>
using namespace std;
int main(void) {
	
	float pi = 3.14159265359;
	float x, y, leftSide, rightSide;
	
	cout << "Please enter value for x: ";
	cin >> x;
	
	leftSide = x * x / (pi * pi * (x * x + 0.5));
	rightSide = 1 + x * x / (pi * pi * (x * x - 0.5) * (x * x - 0.5));
	y = leftSide * rightSide;
	
	cout << "y equals " << y;
	return 0;
	
}