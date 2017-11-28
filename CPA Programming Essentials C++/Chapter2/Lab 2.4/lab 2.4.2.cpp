#include <iostream>
using namespace std;

int main(void) {
	
	unsigned short int val, leftPart, rightPart;	
	bool ispalindrome = true;
	
	cout << "value ";
	cin >> val;
	
	int j;
	for (int i = 8; i < 16; i++)
	{
		j = 16 - i - 1;
		
		leftPart = val >> i;
		rightPart = val >> j;
		
		if ((leftPart & 1) != (rightPart & 1))
			ispalindrome = false;	
	}
	
	if (ispalindrome)
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl;
	
return 0;
}
