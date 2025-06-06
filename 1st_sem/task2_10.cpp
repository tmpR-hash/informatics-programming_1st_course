#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x, f;
    cin >> x;
    if ((x > 0 && x < 1) || (x > 1 && x < 5) || (x > 5 && x <= 6)) {
        f = ((sqrt(6 - x) / sqrt(x * x - 2 * x + 1)) + (log(x) / (exp(x - 5) - 1)));
        cout << f;
    }
    else {
        if (x >= 6) cout << "The square of a negative number";
        if (x == 1) cout << "Divizion by zero";
        if (x <= 0) cout << "Logarifm of a non-positive number";
        if (x == 5) cout << "Divizion by zero";
    }
    return 0;
}