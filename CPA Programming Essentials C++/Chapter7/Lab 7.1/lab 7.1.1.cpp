#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int main(void) {
	int a = 8, b = 0, c = 0;
	while (cin >> b) {
		try {

			if (b == 0)
				throw string("divide   by 0");
			c = a / b;
			cout << c << endl;
		}
		catch (string e) {
			cout << e << endl;
		}
	}


	return 0;
}