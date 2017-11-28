#include <iostream>
using namespace std;

int main() {
	
	int value;
	cout << "Please enterthe value\n";
	cin >> value;
	
	int banknotes[] = {50, 20, 10, 5, 1};
	
	for(int i = 0; i < sizeof(banknotes) / 4; i++)
	{
		while (value >= banknotes[i])
		{
			value -= banknotes[i];
			cout << banknotes[i] << " ";
		}
	}
		
	return 0;
}