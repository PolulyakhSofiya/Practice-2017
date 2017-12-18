#include <string>
#include <iostream>

using namespace std;

void ToUpperCase(string & row, int start, int end)
{
	for (int i = start; i < end; i++)
		if (row[i] > 90)
			row[i] = row[i] - 32;
}

void SeparateChars(string &row, int start, int end)
{

	string temp_row = row.substr(start, end - start);
	string working_row = "";
	working_row += temp_row[0];
	
	for (int i = 1; i < temp_row.length(); i++)
	{
			working_row  += " ";
			working_row  += temp_row[i];
	}
	row.replace(start, end - start, working_row);
}

void UseMethods(string &row, int &start, int &end, int &operation) {
	
	if (start != -1 && end != -1) {
		
		row.erase(start, 1);
		row.erase(end - 1, 1);
		
		if (operation == 1)
			ToUpperCase(row, start , end);
		else if (operation == 2)
			SeparateChars(row, start, end);
			
		start = -1;
		end = -1;
		operation = -1;
	}
	
}

void DeleteUnusedSymbols(string &row) {
	
	for (int i = 0; i < row.length(); i++)
		if (row[i] == '_' || row[i] == '*')
			row.erase(i, 1);
}

void DefineIndexes(string &row, int &start, int &end, int &operation) {
	
	start = -1;
	end = -1;
	operation = -1;
	
	for (int i = 0; i < row.length(); i++) {
		
		if (row[i] == '*' || row[i] == '_') {
			
			if (row[i] == '*') {
				
				if (start != -1 && operation == 1)
					end = i;
				else
					start = i;
				operation = 1;
				
			} else if (row[i] == '_') {
				
				if (start != -1 && operation == 2)
					end = i;
				else
					start = i;
				operation = 2;
			}
		}
		UseMethods(row, start, end, operation);
	}
	DeleteUnusedSymbols(row);
}

int main() {
	
	string row;
	int start_index;
	int end_index;
	int operation; //-1 - nothing, 1 - toUpper, 2 - separate
	
	getline(cin, row);
	DefineIndexes(row, start_index, end_index, operation);
			
	cout << row <<endl;
}