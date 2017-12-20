#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;
class Engine {
private:
	double version;
public:
	Engine(double ver = 1.0):version(ver) {}
	void print() {
		cout << "Engine: " << version << endl;
	}
};
class Wheel {
private:
	int version;
public:
	Wheel(int ver = 1) :version(ver) {}
	void print() {
		cout << "Wheel: " << version <<"inches"<< endl;
	}
};
class Chassis {
private:
	string version;
public:
	Chassis(string ver = "Normal") :version(ver) {}
	void print() {
		cout << "Chassis: " << version  << endl;
	}
};
class Light {
private:
	int version;
public:
	Light(int ver = 1) :version(ver) {}
	void print() {
		cout << "Light: " << "Type " << version  << endl;
	}
};
class Body {
private:
	string version;
public:
	Body(string ver = "Black") :version(ver) {}
	void print() {
		cout << "Body: " << version << endl;
	}
};
class Car {
private:
	
	Engine *e;
	Wheel *w;
	Chassis *c;
	Light *li; 
	Body *b;
public:
	Car()  {
		e = new Engine(1.0);
		w = new Wheel[4];
		c = new Chassis;
		li = new Light[10];//{ Light(1),Light(1),Light(2),Light(2),Light(3),Light(3), Light(4),Light(4),Light(5),Light(5) };
		b = new Body;
	}
	void print() {
		e->print();
		for (size_t i = 0; i < 4; i++)
		{
			w->print();
			w++;
		}
		c->print();
		for (size_t i = 0; i < 10; i++)
		{
			li->print();
			li++;
		}
		b->print();
	}
};
int main()
{
	Car c;
	c.print();
	return 0;
}