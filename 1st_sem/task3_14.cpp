#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, h;
    double f;
    f = 0;
    cin >> a >> b >> h;
    for (float i = a; i <= b; i += h) {
        cout << i << " ";
        if (i >= -1 && i <= 1) cout << "Logarifm of a non-positive number" << '\n';
        else if (i < 1) cout << "Square of a negative number" << '\n';
        else if (i == 2) cout << "Division by zero" << '\n';
        else {
            f = log(i * i - 1) / (1 - sqrt(i - 1));
            cout << f << '\n';
        }
        
    }
    return 0;
}
