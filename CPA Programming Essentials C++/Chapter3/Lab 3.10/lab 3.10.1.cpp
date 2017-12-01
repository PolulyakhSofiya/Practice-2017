#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void GetArray(int count, int array[]) {
	
	for (int i = 0; i < count; i++)
		cout << array[i]<< " ";
		
	cout << endl;
}
	
int main(void) {

	int maxball;
	int ballsno;
	
	cout << "Max ball number? \n";
	cin >> maxball;
	cout << "How many balls? \n";
	cin >> ballsno;
	
	int* balls = new int[maxball];
	int* drawn_balls = new int[ballsno];
	bool was_used = false;

	for (int i = 0; i < maxball; i++)
		balls[i] = i + 1;
		
	srand(time(NULL));
	drawn_balls[0] = (rand()) % maxball + 1;
	
	for (int i = 1; i < ballsno; i++) {
		
		do {
			was_used = false;
			drawn_balls[i] = (rand()) % maxball + 1;
			
			for (int j = 0; j < i; j++)
				if (drawn_balls[i] == drawn_balls[j]) 
					was_used = true;
		} while( was_used );
	}
	cout << "The maximal ball number is " << maxball << "\nNumbers of drawn balls\n";
	GetArray(ballsno, drawn_balls);
	
	delete [] balls;
	delete [] drawn_balls;
	
	return 0;
}
