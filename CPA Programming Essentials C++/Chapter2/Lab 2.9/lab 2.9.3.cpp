#include <iostream>
using namespace std;

int main(void) {
	
	int vector[] = {1, 7, 3, 8, 3, 7, 1};
	bool ispalindrome = true;
	
	int n = sizeof(vector) / sizeof(vector[0]);
	
	for (int i = 0; i < n /2; i++) {
		if (vector[i] != vector[n - i - 1])
			ispalindrome = false;
	}
	
	if(ispalindrome)
		cout << "It's a palindrome\n";
	else
		cout << "It isn't a palindrome\n";

	return 0;
}