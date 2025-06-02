#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& line) {
    if (line.empty()) return;
    int max_val = *max_element(line.begin(), line.end());
    vector<int> count(max_val + 1, 0);
    for (int num : line) {
        count[num]++;
    }
    int index = 0;
    for (int num = 0; num <= max_val; ++num) {
        while (count[num] > 0) {
            line[index++] = num;
            count[num]--;
        }
    }
}

int main() {
    ifstream input("C:/Users/user/Desktop/data.txt");
    ofstream output("C:/Users/user/Desktop/out.txt");
    vector<vector<int>> vec;
    int n;
    cin >> n;
    vec.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> vec[i][j];
        }
    }

    for (auto& line : vec) {
        countingSort(line);
    }

    for (const auto& line : vec) {
        for (int num : line) {
            output << num << " ";
        }
        output << endl;
    }

    input.close();
    output.close();
    return 0;
}
