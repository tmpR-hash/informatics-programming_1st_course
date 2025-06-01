#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
  return a.second > b.second;
}

int main() {
  int k, n = 0;
  cin >> k;
  string input;
  ifstream inputFile("C:/Users/user/Desktop/test.txt");
  getline(inputFile, input);
  
  map<string, int> WnC;

  string word;
  while (inputFile >>  word) {
    ++WnC[word];
  }

  vector<pair<string, int>> sortedWords(WnC.begin(), WnC.end());
  sort(sortedWords.begin(), sortedWords.end(), compare);

  for (int i = 0; i < min(k, (int)sortedWords.size()); ++i) {
    cout << sortedWords[i].first << ": " << sortedWords[i].second << endl;
  }

  return 0;

}
