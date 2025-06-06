#include <iostream>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  i = 2;
  while (n > 1) {
    if (n % i == 0) {
      cout << i << " ";
      n = n / i;
    }
    else i++;
  }
  return 0;
}
