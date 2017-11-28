#include <iostream>
using namespace std;

int main() {
	long current_value = 2, previous_value = 1, more_previous_value = 1; 
	int counter = -1;
	
	while (counter < 1)
	{
		cout << "Please enter the value > 0";
		cin >> counter;
		cout << "\n";
	}
	if (counter == 1 || counter == 2)
		cout << 1;
	else
	{
		for (int i = 0; i < counter - 3; i++)
		{
			more_previous_value = previous_value;
			previous_value = current_value;
			current_value = more_previous_value + previous_value;
		}
		cout << current_value;
	}
	return 0;
}