#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

string lower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

set<string> to_set(string s) {
    set<string> set_word;
    if (s[s.length() - 1] != ' ') {
        s += " ";
    }
    while (s != "") {
        set_word.insert(lower(s.substr(0, s.find(' '))));
        s.erase(0, s.find(' ') + 1);
    }
    return set_word;
}
int main() {
    ifstream input("C:/Users/user/Desktop/test1.txt");
    set<string> T, voskl, vopr, pov, ans;
    string s;

    while (input) {
        getline(input, s);
    }
    while (s != "") {
        int pos = s.find_first_of("'!?.'");
        T = to_set(s.substr(0, pos));
        if (s[pos] == '!') {
            voskl.insert(T.begin(), T.end());
        }
        if (s[pos] == '?') {
            vopr.insert(T.begin(), T.end());
        }
        if (s[pos] == '.') {
            pov.insert(T.begin(), T.end());
        }
        s.erase(0, pos + 2);
    }

    set_intersection(pov.begin(), pov.end(), voskl.begin(), voskl.end(), inserter(ans, ans.begin()));

    for (auto i : ans) {
        cout << i << " ";
    }

}
