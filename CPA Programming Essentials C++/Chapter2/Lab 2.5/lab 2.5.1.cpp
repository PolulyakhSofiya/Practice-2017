#include <iostream>
using namespace std;

int main(void) {
	
	int operation;
	double leftPart, rightPart;
	
	cout << "MENU:\n 0 - exit\n 1 - addition\n 2 - subtraction\n 3 - multiplication\n 4 - division\n Your choice?\n";
	do {
		cin >> operation;
		if (operation)
		{
			cin >> leftPart;
			cin >> rightPart;
			
			switch (operation) {
				case 0: break;
				case 1: cout << leftPart + rightPart; break;
				case 2: cout << leftPart - rightPart; break;
				case 3: cout << leftPart * rightPart; break;
				case 4: {
					if (rightPart) { 
						cout << leftPart / rightPart;
					} else 
						cout << "try again";
					break;
				}
				default: cout << "try again";
			}
		}
	} while (operation);

	return 0;
}
