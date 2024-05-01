#include <iostream>  
using namespace std;
int temp;


void sunny(int&, int);
void cloudy(int, int&);
int main() {
  int num1 = 6;
  int num2 = 10;
  temp = 20;
  cout << num1 << " " << num2 << " " << temp << endl;
  sunny(num1, num2);
  cout << num1 << " " << num2 << " " << temp << endl;
  cloudy(num1, num2);
  cout << num1 << " " << num2 << " " << temp << endl;
  return 0;
}
void sunny(int& a, int b) {
  int w;
  temp = (a + b) / 2;
  w = a / temp;
  b = a + w;
  a = temp - b;
}
void cloudy(int u, int& v) {
  temp = 2 * u + v;
  v = u; 
    u = v - temp;
}
