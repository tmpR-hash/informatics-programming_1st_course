#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int x, c1, c2, c3, y1, y2, y3, y;
	cin >> x;
	c1 = x / 100;
	c2 = (x % 100) / 10;
	c3 = x % 10;
	y1 = (c2 + c3) % 10;
	y2 = abs(c1 - c3);
	y3 = c2 % c1;
	y = y1 * 100 + y2 * 10 + y3;
	cout << y;
	return 0;
}




