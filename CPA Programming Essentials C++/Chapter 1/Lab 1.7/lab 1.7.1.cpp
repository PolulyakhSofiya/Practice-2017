#include <iostream>
#include <iomanip>

using namespace std;

int main () {

  cout << fixed;
  
  cout << setprecision(1) << 2.3 << '\n';
  cout << setprecision(2) << 2.3 << '\n';
  cout << setprecision(6) << 2.123456 << '\n';
  cout << setprecision(2) << 2.123456 << '\n';
  cout << setprecision(0) << 2.123456 << '\n';
  
  return 0;
}