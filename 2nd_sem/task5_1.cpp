#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

int count_divisors(int n) {
    if (n < 1) return 0;
    int count = (n == 1) ? 1 : 2;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count += (i * i == n) ? 1 : 2;
        }
    }
    return count;
}

int main() {
    int stack[MAX_SIZE];
    int head = -1;

    int input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int inputSize = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < inputSize; i++) {
        if (head < MAX_SIZE - 1) {
            stack[++head] = input[i];
        }
        else {
            cout << "Stack overflow!" << endl;
            break;
        }
    }

    int max_divisors = 0;
    for (int i = 0; i <= head; i++) {
        int divisors = count_divisors(stack[i]);
        if (divisors > max_divisors) {
            max_divisors = divisors;
        }
    }

    int result[MAX_SIZE];
    int result_size = 0;

    for (int i = 0; i <= head; ++i) {
        if (count_divisors(stack[i]) != max_divisors) {
            result[result_size++] = stack[i];
        }
    }

    for (int i = 0; i < result_size; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}