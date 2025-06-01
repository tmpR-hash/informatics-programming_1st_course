#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int c1, c2, c3, f, y, x;
	cin >> x;
	c1 = x / 100;
	c2 = (x % 100) / 10;
	c3 = x % 10;
	f = (c1 * c2 * c3) % (c1 + c2 + c3);
	y = c1 * 100 + c3 * 10 + c2;
	cout << f << '\n';
	cout << y;
	return 0;
}
