#include <string>
#include <iostream>

std::string ToLowerCase(std::string row) {
	
	for (int i = 0; i < row.length(); i++)
		if (row[i] <= 90 && row[i] != ' ')
			row[i] += 32;
			
	return row;
}

void DeleteWord(std::string &row, std::string word) {
	
	std::string temp_row = ToLowerCase(row);
	temp_row = " " + temp_row;
	
	while (temp_row.find(word) && temp_row.find(word) != std::string::npos) {
		
		int index = temp_row.find(word);
		
		row.replace(index - 1, word.length() - 1, "");
		temp_row.replace(index, word.length() - 1, "");
	}
}

std::string* LikeASplit(std::string row, int &count) {
	
	std::string *words = new std::string[1];
	row = row + ","; 
	
	while(row.find(",") && row.find(",") != std::string::npos) {
		
		std::string *temp_words = new std::string[count + 1];
		int index = row.find(",");
		
		for (int i = 0; i < count; i++)
			temp_words[i] = words[i];
			
		temp_words[count] = row.substr(0, index);
			
		delete [] words;
		words = temp_words;
		
		row.erase(0, index + 1);
		count++;
	}
	
	return words;
}

void EliminateWords(std::string &row, std::string stop_words) {
	
	int count = 0;
	
	std::string *words = LikeASplit(stop_words, count);
	
	row = " " + row;
	
	for (int i = 0; i < count; i++)
		DeleteWord(row, " " + words[i] + " ");
		
	row.erase(0, 1);
}

int main() {
	
	std::string stop_words;
	std::getline(std::cin, stop_words);
	
	std::string sentence;
	std::getline(std::cin, sentence);
	
	EliminateWords(sentence, stop_words);
	std::cout << sentence << "\n";
}