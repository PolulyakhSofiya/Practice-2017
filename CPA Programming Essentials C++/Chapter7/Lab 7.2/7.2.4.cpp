#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Ex {
	string mes;
public:
	Ex(string m = "exception type error") :mes(m) {}
	string get() {
		return mes;
	}
};
float square_area(float a) {
	if (a < 0)
		throw Ex("the square side less 0");
	return a*a;
}
float rectangle_area(float a, float b) {
	if (a < 0||b<0)
		throw Ex("the rectangle side less 0");
	return a*b;
}
int main(void) {
	float a, b, r;
	cin >> a;
	cin >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		cout << rsquare << endl << rrectangle << endl;
	}
	catch (Ex e) {
		cout << e.get() << endl;
	}
	return 0;
}