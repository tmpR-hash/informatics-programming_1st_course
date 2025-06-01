#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int x, y;
	double f, z, c;
	cin >> x >> y;
	c = exp(x - 1) + exp(y - 1);
	z = cos(x + 2 * y) * cos(x + 2 * y);
	f = 0.2 * x * y + sqrt(c / z);
	cout << f;
	return 0;
}

