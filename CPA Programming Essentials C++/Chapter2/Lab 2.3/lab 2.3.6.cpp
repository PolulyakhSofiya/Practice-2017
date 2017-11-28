#include <iostream>
using namespace std;
 
int main(void) {
 
	int side;
	int length;
 
	cout << "Please enter the value > than 0\n";
	cin >> side;
 
	if (side < 2 && side >9)
	{
		return 0;
		cout << "wrong value";
	}
	length = (side - 1) * 6 + 7;
 
	for (int i = 1; i <= length; i++)
	{
		if (i % (length / 3) == 0)
			cout << "*";
		else 
			cout << " ";
	}
	if (side == 1)
		return 0;;
	cout << "\n";
 
	int j = 1;
	for (int k = 1; k <= side - 2; k++)
	{
		for (int i = 1; i <= length + side - 3; i++)
		{
			if (((i - j)  / 3 >= 1 && (i - j) % (length / 3) == 0) || ((i + j)  / 3 >= 1 && (i + j) % (length / 3) == 0))
				cout << "*";
			else 
				cout << " ";
		}
		cout << "\n";
		j++;
	}
 
	for (int i = 0; i <= length; i++)
	{
		if ((i + side)  / 3 >= 1 && (i + side) % (length / 3) == 0 )
		{
			for (int k = 0; k < 2 * side -1; k++)
			{
				cout << "*";
				i++;
			}
			i--;
		}
		else 
			cout << " ";
	}
	return 0;
}