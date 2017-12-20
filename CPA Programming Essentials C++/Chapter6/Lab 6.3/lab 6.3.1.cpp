#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
class SyperClass
{
public:
	virtual string TakePicture(){ return " /\\ \n"; }
protected:
	string symbol;
};

class Variant1 :public SyperClass {
public:
	Variant1() {
		symbol = "++";
	}
	string TakePicture() {
		return SyperClass::TakePicture() + "/" + symbol + "\\\n";
	}
};
class Variant2 :public SyperClass {
public:
	Variant2() {
		symbol = "**";
	}
	string TakePicture() {
		return SyperClass::TakePicture() + "/" + symbol + "\\\n";
	}
};
class Variant3 :public SyperClass {
public:
	Variant3() {
		symbol = "/\\";
	}
	string TakePicture() {
		return SyperClass::TakePicture() + "/" + symbol + "\\\n";
	}
};
int main()
{
	SyperClass *Variant1, *Variant2, *Variant3;
	Var1 = new Variant1();
	Var2 = new Variant2;
	Var3 = new Variant3;
	std::cout << (Var1->TakePicture());
	cout << Var2->TakePicture();
	cout << Var3->TakePicture();
	return 0;
}