#include <iostream>
using namespace std;

void DeleteChar(string &row, char char_to_delete) {
	
	int index = row.find(char_to_delete);
	int length = row.length();
	row = row.substr(0, index) + row.substr(index + 1, length - index - 1);
}

int* InitilizeEmpryIntArray(int length) {
	
	int *array = new int[length];
	
	for (int i = 0; i < length; i++)
		array[i] = 0;
		
	return array;
}

void CountChar(string row, string letters, int *counts, int size) {

	row = " " + row;
	for (int i = 0; i < size; i++)
		while (row.find(letters[i]) && row.find(letters[i]) != string::npos) {
			
			counts[i]++;
			DeleteChar(row, letters[i]);
		}
}

bool IsArraysEqual(int *first, int *second, int size) {
	
	bool result = true;
	
	for (int i = 0; i < size; i++)
		if (first[i] != second[i]) {
			
			result = false;
			break;
		}
		
	return result;
}

void IsWordsAnagrams(string first, string second) {
	
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int *first_word_counts = InitilizeEmpryIntArray(26);
	int *second_word_counts = InitilizeEmpryIntArray(26);
	
	CountChar(first, letters, first_word_counts, 26);
	CountChar(second, letters, second_word_counts, 26);
	
	if (IsArraysEqual(first_word_counts, second_word_counts, 26))
		cout << "pangrams";
	else 
		cout << "not pangrams";
	
	delete[] first_word_counts;
	delete[] second_word_counts;
}

int main() {

	string first_word;
	string second_word;
	
	getline(cin, first_word);
	int index = first_word.find(" ");
	
	second_word = first_word.substr(index + 1, first_word.length());
	first_word = first_word.substr(0, index );
	
	IsWordsAnagrams(first_word, second_word);
	
	return 0;
}