#include <iostream>
using namespace std;

int main() {
	long value = 1;
	int counter = -1;
	
	while (counter < 0)
	{
		cout << "Please enter the value > 0";
		cin >> counter;
		cout << "\n";
	}
	if (counter == 0)
		cout << 1;
	else
	{
		for (int i = 1; i <= counter; i++)
		{
			value *= i;
		}
		cout << counter << "! = " << value;
	}
	return 0;
}