#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

void combSort(vector<int>& arr, bool increasing) {
    int n = arr.size();
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = max(1, (gap * 10) / 13);
        swapped = false;

        for (int i = 0; i < n - gap; ++i) {
            if (increasing ? (arr[i] > arr[i + gap]) : (arr[i] < arr[i + gap])) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
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
    for (int j = 0; j < n; ++j) {
        vector<int> column(n);
        for (int i = 0; i < n; ++i) {
            column[i] = vec[i][j];
        }
        combSort(column, (j + 1) % 3 != 0);
        for (int i = 0; i < n; ++i) {
            vec[i][j] = column[i];
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
