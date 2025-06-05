#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

int main() {
    int queue[MAX_SIZE];
    int front = 0, back = 0;
    
    int input[] = { 2, 8, 2, 1, 6, 8, 8, 1, 2, 2, 8, 2, 1 };
    int inputSize = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < inputSize; i++) {
        if (back < MAX_SIZE) {
            queue[back++] = input[i];
        }
    }

    int max_num = queue[front];
    for (int i = front + 1; i < back; i++) {
        if (queue[i] > max_num) {
            max_num = queue[i];
        }
    }

    int last_even = -1;
    for (int i = back - 1; i >= front; i--) {
        if (queue[i] % 2 == 0) {
            last_even = queue[i];
            break;
        }
    }

    if (last_even == -1) {
        cout << "There is no even numbers" << endl;
        return 0;
    }

    int new_queue[MAX_SIZE];
    int new_back = 0;

    for (int i = front; i < back; i++) {
        new_queue[new_back++] = queue[i];
        if (queue[i] == max_num) {
            new_queue[new_back++] = last_even;
        }
    }   

    for (int i = 0; i < new_back; i++) {
        cout << new_queue[i] << " ";
    }
    cout << endl;

    return 0;
}