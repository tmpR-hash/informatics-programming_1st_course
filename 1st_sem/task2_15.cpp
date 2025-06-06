#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int x;
	cin >> x;
	if (x % 10 == 4 || x % 10 == 5) cout << "Green ";
	if (x % 10 == 6 || x % 10 == 7) cout << "Red ";
	if (x % 10 == 8 || x % 10 == 9) cout << "Yellow ";
	if (x % 10 == 0 || x % 10 == 1) cout << "White ";
	if (x % 10 == 2 || x % 10 == 3) cout << "Blue ";

	if (x % 12 == 1) cout << "Cock";
	if (x % 12 == 2) cout << "Dog";
	if (x % 12 == 3) cout << "Pig";
	if (x % 12 == 4) cout << "Rat";
	if (x % 12 == 5) cout << "Bull";
	if (x % 12 == 6) cout << "Tiger";
	if (x % 12 == 7) cout << "Bunny";
	if (x % 12 == 8) cout << "Dragon";
	if (x % 12 == 9) cout << "Snake";
	if (x % 12 == 10) cout << "Horse";
	if (x % 12 == 11) cout << "Goat";
	if (x % 12 == 0) cout << "Monkey";
	return 0;
}