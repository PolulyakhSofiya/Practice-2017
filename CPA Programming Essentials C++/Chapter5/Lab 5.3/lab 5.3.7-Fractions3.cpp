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
	int get_num();
	int get_dem();
	
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
	
	bool isGreaterThan(Fraction that);
	bool isLessThan(Fraction that);
	bool isEqual(Fraction that);
	int compare(Fraction that);

private:
	int numerator;
	int denominator;
	void reduce();
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

int Fraction::get_num() { return this -> numerator; }
int Fraction::get_dem() { return this -> denominator; }

int ExecuteAlgorithm(int left, int right) {
	
	int reminder = -1;	
	while (reminder != 0) {
		
		if (left < right) {
			right = left * right;
			left = right / left;
			right = right / left;
		}		
		int temp_reminder = left % right;
		left = right;
		
		if (temp_reminder != 0)
			right = temp_reminder;
		reminder = temp_reminder;
	}	
	return right;
}

void MakeItPositive(int &value) {
	
	if (value < 0)
		value *= -1;
}

int FindSmallestDivisor(int num, int dem) {
	
	int left, right;
	
	if (num == dem)
		return num;
	else {
		MakeItPositive(num);
		MakeItPositive(dem);
		return ExecuteAlgorithm(num, dem);	
	}
}

void Fraction::reduce() {
	
	if (this->numerator != 0) {
		int divisor = FindSmallestDivisor(this->numerator, this->denominator);
		this -> numerator = numerator / divisor;
		this -> denominator = denominator / divisor;
	}
}

Fraction Fraction::plus(Fraction that) {
	
	int num_result = this->numerator * that.get_dem() + that.get_num() * this->denominator;
	int den_result = this->denominator * that.get_dem();
	
	Fraction result(num_result, den_result);
	result.reduce();
	
	return result;
}

Fraction Fraction::minus(Fraction that) {
	
	int new_that_num = that.get_num() * -1;
	Fraction new_that(new_that_num, that.get_dem());

	Fraction result = this->plus(new_that);
	return result;
}

Fraction Fraction::times(Fraction that) {

	int num_result = this->numerator * that.get_num();
	int den_result = this->denominator * that.get_dem();
	
	Fraction result(num_result, den_result);
	result.reduce();
	
	return result;
}

Fraction Fraction::by(Fraction that) {
	
	Fraction new_that(that.get_dem(), that.get_num());
	
	Fraction result = this->times(new_that);
	return result;
}

int Fraction::compare(Fraction that) {
	
	int result;
	Fraction fraction_result = this->minus(that);
	
	if (fraction_result.get_num() == 0)
		result = 0;
	else if (fraction_result.get_num() < 0)
			result = -1;
		else 
			result = 1;
	
	return result;
}

bool compareResultToBool(Fraction left, Fraction right, int expected) {
	
	int compare_result = left.compare(right);
	bool result = (compare_result == expected) ? true : false;
	
	return result;
}

bool Fraction::isEqual(Fraction that) {
	
	return compareResultToBool(*this, that, 0);
}

bool Fraction::isGreaterThan(Fraction that) {
	
	return compareResultToBool(*this, that, 1);
}

bool Fraction::isLessThan(Fraction that) {
	
	return compareResultToBool(*this, that, -1);
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

Fraction ReadFraction() {
	
	int num, den;
	string input = "";
	
	getline(cin, input);
	int *numbers = LikeASplit(input);
	
	if (numbers[1] == 0) {
		cout << "Please enter correct input data. Denominator can't be equal 0";
		delete[] numbers;
		std::exit(-1);
	}
	
	Fraction fraction(numbers[0], numbers[1]);
	delete[] numbers;
	
	return fraction;
}

void PerformOperations(Fraction left, Fraction right) {
	
	cout << left.toString() << " + " << right.toString() << " = " << left.plus(right).toString() << endl;
	cout << left.toString() << " - " << right.toString() << " = " << left.minus(right).toString() << endl;
	cout << left.toString() << " * " << right.toString() << " = " << left.times(right).toString() << endl;
	cout << left.toString() << " / " << right.toString() << " = " << left.by(right).toString() << endl;
}

void compareFractions(Fraction left, Fraction right) {
	
	string resultSign;
	if (left.isEqual(right))
		resultSign = " = ";
	else 
		if (left.isGreaterThan(right))
			resultSign = " > ";
		else
			resultSign = " < ";
		
	cout << left.toString() << resultSign << right.toString();
}

int main(void) {
	
	Fraction fraction_left = ReadFraction();
	Fraction fraction_right = ReadFraction();
	
	compareFractions(fraction_left, fraction_right);
	
	return 0;
}