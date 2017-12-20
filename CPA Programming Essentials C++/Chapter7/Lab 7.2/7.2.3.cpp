#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
const int DivideByZero = 111;
using namespace std;
float internaldiv(float arg1, float arg2)
{
	if (0 == arg2)
		throw DivideByZero;
	return arg1 / arg2;
}
float div(float arg1, float arg2) {
	if (arg2 == 0.0)
		throw DivideByZero;
	return internaldiv(arg1, arg2);
}
int main(void) {
	float a, b;
	while (cin >> a) {
		try {
			cin >> b;
			cout << fixed << div(a,b) << endl;
		}
		catch (int e) {
			cout << "Are you kidding me?" << endl;

			cout << e << endl;
		}
	}
	return 0;
}