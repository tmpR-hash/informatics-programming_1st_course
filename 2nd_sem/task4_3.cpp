#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        swap(arr[i], arr[max_index]);
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

    for (int k = 1 - n; k < n; k++) {
        vector<int> diagonal;

        for (int i = 0; i < n; i++) {
            int j = i + k;
            if (j >= 0 && j < n) {
                diagonal.push_back(vec[i][j]);
            }
        }

        selectionSort(diagonal);

        int index = 0;
        for (int i = 0; i < n; i++) {
            int j = i + k;
            if (j >= 0 && j < n) {
                vec[i][j] = diagonal[index++];
            }
        }
    }

    for (const auto& line : vec) {
        for (int num : line) {
            output << num << " ";
        }
        output << "\n";
    }

    input.close();
    output.close();
    return 0;
}
