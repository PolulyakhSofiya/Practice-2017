#include <iostream>

using namespace std;

int main() {
	
	unsigned long pow = 1;
	int n;
	cin >> n;
	
	for (int counter = 0; counter < n; counter++)
		pow *= 2;
	
	cout << pow;
	return 0;
}