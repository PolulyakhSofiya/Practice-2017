#include <iostream>

using namespace std;

int** InputArray() {

	int **arr, number_of_courses;
	cin >> number_of_courses;
	
	arr = new int* [number_of_courses + 1];
	arr[0] = new int[1];
	
	for (int i = 1; i <= number_of_courses; i++) {

		int columns, sum;
		cin >> columns;
		
		arr[i] = new int[columns + 2];
		arr[i][0] = columns;
		
		for (int j = 2; j <= columns + 1; j++) {
			
			cin >> arr[i][j];
			sum += arr[i][j];
		}
		arr[i][1] = sum;
		sum = 0;
	}
	
	arr[0][0] = number_of_courses;
	return arr;
}

void PrintArray(int** arr) {
	
	float total_sum = 0.0, avg;
	
	for (int i = 1; i <= arr[0][0]; i++) {
		
		avg = (float)arr[i][1] / arr[i][0];
		total_sum += avg;
		
		cout << "Course " << i << ": ";
		cout << "final: " << avg << " grades: ";
		
		for (int j = 2; j <= arr[i][0] + 1; j++)		
			cout << arr[i][j] << " ";
		
		cout << endl;
	}
	cout << "Over all final: " << total_sum / arr[0][0];
}

int main(void) {

	int **arr;
	arr = InputArray();
	
	PrintArray(arr);
	
	for (int i = 0; i < arr[0][0]; i++)
		delete [] arr[i];		
	delete [] arr;
	
	return 0;
}