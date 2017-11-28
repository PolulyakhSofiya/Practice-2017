#include <iostream>
using namespace std;

int main(void) {
	
	int side;
	
	cout << "Please enter the value > than 1 and < 50\n";
	cin >> side;
	
	if (side < 1 || side >= 50)
	{
		cout << "wrong value";
		return 0;
	}
	
	cout << '+';
	
	for(int i = 0; i < side; i++)
		cout << '-';
	cout << '+' << endl;
	
	for(int i = 0; i < side; i++) {
		cout << '|';
		for(int j = 0; j < side; j++)
			cout << ' ';
		cout << '|' << endl;
	}
	cout << '+';
	
	for(int i = 0; i < side; i++)
		cout << '-';
	cout << '+' << endl;
	return 0;
}