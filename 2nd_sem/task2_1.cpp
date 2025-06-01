#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

void digits(int n, set<int>& dl) {
  n = (int)fabs(n);
  while(n > 0) {
  dl.insert(n % 10);
  n /= 10;
  }
}

int main() {
  int n, a;
  cin >> n;
  vector<int> liSt;
  for (int i = 0; i < n; i++) {
    cin >> a;
    liSt.push_back(a);
  }

  set<int> alldigs;
  set<int> digs;
  for (int a : liSt) digits(a, alldigs);
  for (int a : liSt) if (fabs(a) >= 10 && fabs(a) <= 999) digits(a, digs);
  
  set<int> ans;
  for (int a : alldigs) if (digs.find(a) == digs.end()) ans.insert(a);
  for (int a : ans) cout << a << " ";
  return 0;
}
