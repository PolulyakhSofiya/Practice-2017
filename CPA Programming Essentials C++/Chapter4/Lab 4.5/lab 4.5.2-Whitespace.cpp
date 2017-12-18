#include <string>
#include <iostream>

using namespace std;

void DeleteByIndex(string &row, int index) {
	
	int length = row.length();
	row = row.substr(0, index) + row.substr(index + 1, length - index - 1);
}

void DeleteDuplicatedWhitespaces(string &row) {
	
	string current_char, next_char;

	for (int i = 0; i < row.length() - 1; i++) {
		
		current_char = row[i];
		next_char = row[i + 1];
		
		if (current_char.compare(0,1," ") == 0 && next_char.compare(0,1," ") == 0) {
			DeleteByIndex(row, i);
			i--;
		}
	}
}

int main()
{
	string sentence;
	getline(cin, sentence);
	
	DeleteDuplicatedWhitespaces(sentence);

	cout << sentence << "\n";
}