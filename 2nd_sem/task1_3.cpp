#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main() {
    int n, b;
    double m, d, m1;
    cout << "n: ";  cin >> n;
    vector<int> c;
    vector<double> c1;
    for (int j = 0; j < n; j++) {
        cin >> b;
        c.push_back(b);
    }
    m = 0;
    m = accumulate(c.begin(), c.end(), (double)0) / n;
    cout << "M: " << m << endl << "Elements for sum: ";
    for (int i = 0; i < n; i++) {
        c1.push_back((c.at(i) - m) * (c.at(i) - m));
        cout << c1.at(i) << " ";
    }
    m1 = accumulate(c1.begin(), c1.end(), (double)0);
    cout << endl;
    d = 1. / (n - 1) * m1;
    cout << "D: " << d;
}
