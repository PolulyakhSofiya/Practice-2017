#include <iostream>
using namespace std;

int main() {
	
	int *pointer;
	
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / 4;
	int smallest = 100000000;
	
	pointer = vector;
	
	for (int i = 0; i < n; i++)
	{
		if (smallest > *pointer)
			smallest = *pointer;
		pointer++;
	}
	
	cout << smallest;
	
	return 0;
}