#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;
class IPAddress {
private:
	string ip;

public:
	IPAddress(IPAddress &source) :ip(source.ip) {}
	IPAddress(string ip = "0.0.0.0") {
		this->ip = ip;
	}
	string ShowIp() {
		return ip;
	}
};
class Network
{
private:
	
	int size;
	int q;
	IPAddress* net = new IPAddress[255];
public:
	Network() {
		size = 0;
		
	}
	void AddIp(IPAddress q) {
		net[size] = q;
		++size;
	}
	void print() {
		IPAddress p = net[0];
		for (size_t i = 0; i < size; i++)
		{
			cout << net[i].ShowIp() << endl;
		}
	}
};


int main()
{

	string i;
	cin >> i;
	IPAddress ip1(i);
	cin >> i;
	IPAddress ip2(i);
	cin >> i;
	IPAddress ip3(i);
	cin >> i;
	IPAddress ip4(i);
	cin >> i;
	IPAddress ip5(i);
	Network net1, net2;
	cout << " This address is  network 1" << endl;

	net1.AddIp(ip1);
	net1.AddIp(ip2);
	net1.AddIp(ip3);
	cout << "This address is network 2" << endl;
	net2.AddIp(ip3);
	net2.AddIp(ip4);
	net2.AddIp(ip5);
	net1.print();
	net2.print();
	
	return 0;
}