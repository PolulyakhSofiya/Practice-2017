#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Collection {
	
	int elno;
	int *elements;
};

void AddToCollection(Collection &col, int element) {
		
	if (col.elno == 0) {
		
		col = { 1, new int[1] };
		col.elements[0] = element;
	} else {
		
		int temp_array[col.elno + 1];
		
		for (int i = 0; i < col.elno; i++)
			temp_array[i] = col.elements[i];
	
		temp_array[col.elno] = element;
		
		delete[] col.elements;
		col.elno++;
		col.elements = new int[col.elno];
		
		for (int i = 0; i < col.elno; i++)
			col.elements[i] = temp_array[i];
	}
}

void PrintCollection(Collection col) {
	
	cout << "[ ";
	
	for(int i = 0; i < col.elno; i++)
		cout << col.elements[i] << " ";
		
	cout << "]" << endl;
}

int main(void) {
	
	Collection collection = { 0, NULL };
	int elems;
	
	cout << "How many elements? ";
	cin >> elems;
	
	srand(time(NULL));
	
	for(int i = 0; i < elems; i++)
		AddToCollection(collection, rand() % 100 + 1);
		
	PrintCollection(collection);
	delete[] collection.elements;
	
	return 0;
}
