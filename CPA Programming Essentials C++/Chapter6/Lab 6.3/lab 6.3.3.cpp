#include "stdafx.h"
#include "iostream"
#include "string";
using namespace std;
class IPAddress {
protected:
	string ip;
	int i[4];
	void Parse() {
		int p = ip.find(".");
		i[0] = atoi((ip.substr(0, p)).c_str());
		p = ip.find(".", p + 1);
		i[1] = atoi((ip.substr(0, p)).c_str());
		p = ip.find(".", p + 1);
		i[2] = atoi((ip.substr(0, p)).c_str());
		p = ip.length();
		i[3] = atoi((ip.substr(0, p)).c_str());
	}
public:
	IPAddress() {
		ip = "0.0.0.0";
		Parse();
	}
	IPAddress(string s) {
		ip = s;
		Parse();
	}
	IPAddress(IPAddress const &q) {
		ip = q.ip;
		Parse();
	}
	virtual string print() {
		return ip;
	}
};
class IPAddressC : public IPAddress {
protected:
	bool flag;
public:
	IPAddressC() :IPAddress(){
		flag = true;
	}
	IPAddressC(string s) :IPAddress(s){
		flag = true;
	}
	IPAddressC(IPAddressC const &q) :IPAddress(q){
		flag = q.flag;
	}
	bool Check() {
		for (size_t j = 0; j < 4; j++)
		{
			if (i[j] < 0 || i[j]>255)
			{
				flag = false;
				return false;

			}
		}
		flag = true;
		return true;
	}
	string print() {
		return  IPAddress::print() + " - " + (Check() ? "IP is correct" : "Ip isn`t correct") + "\n";
	}
};
int main()
{

	string ip1, ip2, ip3;
	cin >> ip1 >> ip2 >> ip3;
	IPAddress q(ip1);
	IPAddressC w(ip2), e(ip3);
	cout << q.print() << endl;;
	cout << w.print();
	cout << e.print();
	return 0;
}