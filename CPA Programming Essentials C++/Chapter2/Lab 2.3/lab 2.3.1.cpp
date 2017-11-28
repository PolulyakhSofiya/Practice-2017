#include <iostream>
using namespace std;

int main() {
	
	int c0, counter = 0;
	cin >> c0;
	
	if (c0 > 0)
	{
		while (c0 != 1)
		{
			counter++;
			
			if (c0 % 2 == 0)
				c0 = c0/2;
			else
				c0 = 3 * c0 + 1;
				
			cout << counter << "step, c0 = " << c0 << endl;
		}
		
		cout << "steps = " << counter;
		
	}
	else
		cout << "This value is negative. Try again)";
		
	return 0;
}