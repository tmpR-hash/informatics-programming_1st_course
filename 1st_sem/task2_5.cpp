#include <iostream>
using namespace std;
int main() {
    int a, x, y, c1, c2;
    cin >> a >> x >> y;
    if (a > 99 || a < 10 || x / 10 != 0 || y / 10 != 0) cout << "Incorrect input";
    else {
        c1 = a / 10;
        c2 = a % 10;
        if (c1 < x && c2 > y) a -= x;
        else if (c1 < x && c2 < y) a += x;
        else if (c1 > x && c2 > y) a -= y;
        else if (c1 > x && c2 < y) a += y;
        else a += x * y;
        cout << a;
    }
    return 0;
}