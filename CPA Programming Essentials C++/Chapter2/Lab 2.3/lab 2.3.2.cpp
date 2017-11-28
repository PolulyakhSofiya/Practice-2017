#include <iostream>

using namespace std;

int main() {
	double pi4 = 0.;
	long n, k = 1.0;
	
	//cout << "Number of iterations? ";
	cin >> n;
	
	for ( long counter = 0.;counter < n; counter++)
	{
		pi4 += k * 1./(2.*counter + 1.0);
		k = -1 * k;
	}
	
	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	
	return 0;
}