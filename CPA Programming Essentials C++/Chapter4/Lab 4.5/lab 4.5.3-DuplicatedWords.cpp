#include <string>
#include <iostream>

using namespace std;

string GetWord(string &row) {
	
	string temp_word = "";
	
	while (row.compare(0, 1, " ") && row.length())
	{
		temp_word += row[0];
		row.erase(0, 1);
	}
	
	row.erase(0,1);
	
	return temp_word;
}

bool ContainWord(string row, string word) {
	
	return (row.find(word) && row.find(row) != string::npos);
}

void GetIndex(string row, string word, int &index) {
	
	row = " " + row;
	
	if (ContainWord(row, " " + word)) 
		index = row.find(" " + word);
		
	else if (ContainWord(row, word + " "))
		index = row.find(word + " ");
	
	else 
		index = -1;
}

void DeleteWord(string &row, string &temp_string, int index ,int length) {
	
	string copy = row.substr(0, row.length() - temp_string.length());
	
	temp_string.erase(index - 1, length + 1);
	row = copy + temp_string;
}

void CheckDuplicates(string &row) {
	
	string temp_string = row;
	int index = 0;
	
	while (temp_string.length()) {
		
		string current_word =  GetWord(temp_string);

		do {
			GetIndex(temp_string, current_word, index);

		if (index > 0)
			DeleteWord(row, temp_string, index, current_word.length());
		
		} while (index > 0);
	}
}

int main() {
	
	string sentence;
	getline(cin, sentence);
	cout << "input: " << sentence << endl;

	CheckDuplicates(sentence);

	cout << "output: " << sentence;
}