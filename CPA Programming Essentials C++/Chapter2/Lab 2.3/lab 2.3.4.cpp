#include <iostream>

using namespace std;

int main() {
	
	double pow = 1.0;
	int n;
	cin >> n;
	
	for (int counter = 0; counter < n; counter++)
		pow /= 2.0;
	
	cout.precision(20);
	cout << pow;
	return 0;
}