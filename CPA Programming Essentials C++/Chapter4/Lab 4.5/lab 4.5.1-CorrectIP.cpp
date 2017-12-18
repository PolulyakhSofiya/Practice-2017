#include <iostream> 
#include <string>
#include <sstream>

using namespace std;

void DeleteChar(string &row, char char_to_delete) {
	
	int index = row.find(char_to_delete);
	int length = row.length();
	row = row.substr(0, index) + row.substr(index + 1, length - index - 1);
}

int DotsInRow(string row) {
	
	int number_of_dots = 0;
	while (row.find(".") && row.find(".") != string::npos) {
		number_of_dots++;
		DeleteChar(row, '.');
	}
	
	return number_of_dots;
}

bool ContainsOnlyDotsAndNumbers(string row){
	
	string required_characters = "0123456789.";
	
	for (int i = 0; i < required_characters.length(); i++)
		while (row.find(required_characters[i]) 
				&& row.find(required_characters[i]) != string::npos)
			DeleteChar(row, required_characters[i]);

	if (row.length() > 1)
		return false;
	else 
		return true;
}

bool IsPartsOk(string row) {
	
	string temp_string;
	row += ".";
	bool answer = true;
	for (int i = 0; i < 4; i++) {
		
		int index = row.find(".");
		int result;
		
		temp_string = row.substr(0, index);
		istringstream(temp_string) >> result;
		
		row = row.substr(index + 1, row.length() - index);
		
		if (result > 255)
			answer = false;
	}
	return answer;
}

string CheckAddr(string address) {
	
	if (address.length() > 16)
		return "Too many characters in a part";
	else {
		string temp_string = address;
		if (DotsInRow(temp_string) > 3)
			return "Too many parts";
		else if (DotsInRow(temp_string) < 3)
				return "Incorrect parts count";
		else {
			temp_string = address;
			
			if (!ContainsOnlyDotsAndNumbers(temp_string))
				return "Only digits and dots allowed";
			else if (!IsPartsOk(temp_string))
					return "Too big value of a part";
				else 
					return "Correct IP";
		}
	}
}

int main(void) {
	
	string user_address;
	cout << "Please enter the address\n";
	
	getline(cin, user_address);
	user_address = " " + user_address;
	
	cout << CheckAddr(user_address);
}
