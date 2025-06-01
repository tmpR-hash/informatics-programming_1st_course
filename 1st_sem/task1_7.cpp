#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int x, y;
	long double f, z, c;
	cin >> x >> y;
	c = x * x + y * y;
	z = cos(x) * cos(x) + cos(x * x);
	f = exp(sqrt(log(c / z)));
	cout << f;
	return 0;
}