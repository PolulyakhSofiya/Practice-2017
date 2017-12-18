#include <iostream>
#include <string>
using namespace std;

void ChangeCase(string &letters, int length)
{
	for (int i = 0; i < length; i++)
			letters[i] = letters[i] - 'a' + 'A';
}

void CheckConcreteCharacters(string pass, string symbols, int *counters, int length, int index)
{
	for (int i = 0; i < length; i ++)
		for (int j = 0; j < symbols.length(); j++)
			if (pass[i] == symbols[j])
				counters[index]++;
}

void CheckCharactrs(string password, int *counters, int length)
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string digits = "1234567890";
	string specific_symbols = "[]()@_$";
	
	CheckConcreteCharacters(password, alphabet, counters, length, 1);
	
	ChangeCase(alphabet, alphabet.length());
	CheckConcreteCharacters(password, alphabet, counters, length, 2);
	
	CheckConcreteCharacters(password, digits, counters, length, 3);
	
	CheckConcreteCharacters(password, specific_symbols, counters, length, 4);
}

void PrintResult(int * counters)
{
	string massages[5] = {
		
		"The password must be 8 characters long",
		"The password must have at least one lower case letter",
		"The password must have at least one upper case letter",
		"The password must have at least one digit",
		"The password must have at least one special character"		
	};
	
	for (int i = 0; i < 5; i++)
		if (counters[i] < 1)
			cout << massages[i] << endl;
	
}

void CheckPass(string password, int *counters)
{
	bool isValid = true;
	(password.length() >= 8) ? counters[0] = 1 : counters[0] = 0;
		
	CheckCharactrs(password, counters, password.length());
	
	for (int i = 0; i < 5; i++)
		if (counters[i] < 1)
			isValid = false;
	
	if (isValid)
		cout << "The password is valid";
	else 
		PrintResult(counters);
		
}

int main() {
	
	int validation_counters[5] = {0, 0, 0, 0, 0};

	string user_pass;
	getline(cin, user_pass);
	
	CheckPass(user_pass, validation_counters);

	return 0;
}