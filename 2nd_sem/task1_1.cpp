#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x, m, b;
    cin >> n;
    vector<int> c;
    for (int j = 0; j < n; j++) {
        cin >> b;
        c.push_back(b);
    }
    cin >> x;
    m = c.at(0);
    for (auto a : c) {
        if (a > m) m = a;
    }
    
    for (int i = 0; i < n; i++) {
        if (c.at(i) % x == 0) c.at(i) = m;
    }

    for (auto a : c) {
        cout << a << " ";
    }
}
