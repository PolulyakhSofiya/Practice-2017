#include <iostream> 
#include <string> 

using namespace std;

void DeleteChar(string &row, char char_to_delete) {
	
	int index = row.find(char_to_delete);
	int length = row.length();
	row = row.substr(0, index) + row.substr(index + 1, length - index - 1);
}

void CountChar(string row, string letters, int * counts, int size) {

	for (int i = 0; i < size; i++)
		while (row.find(letters[i]) && row.find(letters[i]) != string::npos) {
			
			counts[i]++;
			DeleteChar(row, letters[i]);
		}
}

void ChangeCase(string &letters, int length, bool isUpper) {
	
	if (!isUpper) 
		for (int i = 0; i < length; i++)
			letters[i] = letters[i] - 'a' + 'A';
	else 
		for (int i = 0; i < 26; i++)
			letters[i] = letters[i] - 'A' + 'a';
}

int main(void) {
	
	string letters = "abcdefghijklmnopqrstuvwxyz";
	int counts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	string TheString; 
	getline(cin, TheString);
	TheString = " " + TheString;

	CountChar(TheString, letters, counts, 26);
	
	ChangeCase(letters, 26, false);
	CountChar(TheString, letters, counts, 26);
	
	ChangeCase(letters, 26, true);
	
	for (int i = 0; i < 26; i++)
		cout << letters[i] << " - " << counts[i] << endl;
	
	return 0;
}