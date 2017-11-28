#include <iostream>
using namespace std;

int main(void) {
	
	int sys;
	float m, ft, in;

	cout << "Please choose the system. 0 means metric system and 1 means imperial system\n";
	cin >> sys;
	
	if (sys == 1) {
		cin >> ft;
		cin >> in;
		
		m = (ft + in/12.) * 0.3048;
		cout << m << "m";
	}
	else if (sys == 0) {
		cin >> m;
		
		in = (m/0.0254);
		ft = (int)(in/12);
		in = in - ft*12;
		
		cout << ft <<  "'" << in << "''";
	}
	return 0;
	
}