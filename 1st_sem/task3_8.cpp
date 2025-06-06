#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  k = 0;
  cout << 0 << " ";
  for (int i = 1; i <= n; i++) {
    k = i + (i - 1) + k;
    cout << k << " ";
  }
  return 0;
}
