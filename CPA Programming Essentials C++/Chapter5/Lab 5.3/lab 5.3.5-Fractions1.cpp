#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Fraction
{
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
	
	this -> numerator = numerator;
	if (denominator != 0)
		this -> denominator = denominator;
	else {
		this -> numerator = 0;
		this -> denominator = 1;
	}
}

void CheckSign(int &value, int &sign) {
	
	if (value < 0) {
		
		value *= -1;
		sign++;
	}
}

string GetSign(int &value, int sign) {
	
	string result = "";
	
	if (sign % 2 != 0)
		value *= -1;
	
	switch (value) {
		case -1: {
			result += "-";
			break;
		}
		case 1: {
			break;
		}
		default: {
			if (value > 0)
				result += to_string(value - 1) + " ";
			else
				result += to_string(value + 1) + " ";
		}
	}	
	return result;
}

string Fraction::toString() {
	
	if (numerator == 0 )
		return "0";
	else {
	
		int normal = 1, normal_sign = 2, nom_copy = numerator, den_copy = denominator;
		string result = "";
		
		CheckSign(nom_copy, normal_sign);
		CheckSign(den_copy, normal_sign);
		
		while (nom_copy >= den_copy) {
			
			normal++;
			nom_copy -= den_copy;
		}	
		if (nom_copy > 0)
			return GetSign(normal, normal_sign) + to_string(nom_copy) + "/" + to_string(den_copy);
		else
			return GetSign(normal, normal_sign);
	}
}


double Fraction::toDouble() {
	
	double num = numerator * 1.0;
	double den = denominator * 1.0;
	
	return num / den;
}

int LikePow(int number, int pow_to) {
	
	if (pow_to == 0)
		return 1;
		
	int start_number = number;
	
	for (int i = 0; i < pow_to - 1; i++)
		number *= start_number;
		
	return number;
}

void DeleteWhiteSpaces(string &row) {
	
	string temp_row = "";
	for (int i = 0; i < row.length(); i++)
		if (row[i] != ' ')
			temp_row += row[i];
			
	row = temp_row;
}

int ConvertStringToInt(string row) {
	
	int number = 0;
	int sign = 2;
	DeleteWhiteSpaces(row);
	
	for (int i = 0; i < row.length(); i++) {
		
		if (row[row.length() - 1 - i] == '-')
			sign++;
		else
			number += LikePow(10, i) * (row[row.length() - 1 - i] - 48);
	}	
	if (sign % 2 != 0)
		number *= -1;
	
	return number;
}

int* LikeASplit (string input_row) {
	
	int index = input_row.find("/");
	int *numbers = new int[1];
	
	if (index != 0 && index != string::npos)
	{		
			numbers[0] = ConvertStringToInt(input_row.substr(0, index));
			numbers[1] = ConvertStringToInt(input_row.substr(index + 1, input_row.length()));
	}	else 
		cout << "Please enter correct input data\n";
	
	if (numbers[0] < 0 && numbers[1] < 0) {
		
		numbers[0] *= -1;
		numbers[1] *= -1;
	}	
	return numbers;
}

void PrintResult(Fraction fraction) {
	
	string result = "";
	result += fraction.toString();
	
	if (fraction.toDouble() - int(fraction.toDouble()) == 0)
		cout << result << "is " << setprecision(1) << fixed << fraction.toDouble() << " in decimal\n";
	else 
		cout << result << " is " <<  fraction.toDouble() << " in decimal\n";	
}

int main(void) {
	int num, den;
	string input = "";
	
	getline(cin, input);
	int *numbers = LikeASplit(input);
	
	if (numbers[1] == 0) {
		cout << "Please enter correct input data. Denominator can't be equal 0";
		delete [] numbers;
		std::exit(-1);
	}
	
	Fraction fraction(numbers[0], numbers[1]);
	PrintResult(fraction);
	
	delete [] numbers;
	return 0;
}