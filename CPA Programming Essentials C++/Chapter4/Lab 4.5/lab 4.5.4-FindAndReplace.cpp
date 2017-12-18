#include <string>
#include <iostream>

void ReplaceWords(std::string &row, std::string from, std::string to) {
	
	row = " " + row;
	
	if (row.find(from) && row.find(from) != std::string::npos) {
		
		int index = row.find(from);
		row.replace(index, from.length(), to);
	}
		
	row.erase(0, 1);
}	

int main() {
	
	std::string from;
	std::getline(std::cin, from);
	
	std::string to;
	std::getline(std::cin, to);
	
	std::string sentence;
	std::getline(std::cin, sentence);
	
	ReplaceWords(sentence, from, to);
	std::cout << sentence << "\n";
}
