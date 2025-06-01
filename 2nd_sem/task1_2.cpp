#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, b, x, x1, x2, nel, f;
    cout << "n: ";  cin >> n;
    vector<int> c;
    for (int j = 0; j < n; j++) {
        cin >> b;
        c.push_back(b);
    }
    vector<int> c1 = c;

    cout << "Task 1: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << c.at(i) << " ";
    }
    cout << endl;

    cout << "x: "; cin >> x;
    cout << "a: "; cin >> x1;
    cout << "b: "; cin >> x2;
    cout << "Task 2: ";
    for (int i = 0; i < n; i++) {
        if (c1.at(i) >= x1 && c1.at(i) <= x2) c1.at(i) = x;
    }
    for (auto a : c1) {
        cout << a << " ";
    }
    cout << endl;

    cout << "Task 3: ";
    sort(begin(c), end(c));
    for (auto a : c) {
        cout << a << " ";
    }
    cout << endl;

    cout << "New element: "; cin >> nel;
    cout << "Task 4: ";
    auto iterator = lower_bound(c.begin(), c.end(), nel);
    c.insert(iterator, nel);
    for (auto a : c) {
        cout << a << " ";
    }
    cout << endl;

    cout << "Task 5: ";
    f = 0;
    for (int i = 1; i < n; i++) {

        if (c.at(i - f) == c.at(i - f - 1)) {
            c.erase(c.begin() + i - f);
            f = 1;
        }
        else f = 0;
    }
    for (auto a : c) {
        cout << a << " ";
    }
    cout << endl;
}
