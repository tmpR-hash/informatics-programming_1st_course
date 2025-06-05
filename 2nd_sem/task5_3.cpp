#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

bool is_vowel(char c) {
    for (char v : vowels) if (c == v) return true;
    return false;
}

int main() {
    char original[MAX_SIZE];  
    char stack[MAX_SIZE]; 
    int head = -1;
    int count = 0;

    char input[] = { 'q', 'w', 'e', 'r', 't', 'u', 'i', 'o', 'p', 's', 'd', 'a' };
    int input_size = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < input_size; i++) {
        if (head < MAX_SIZE - 1) {
            original[count] = input[i];
            stack[++head] = input[i];
            count++;
        }
    }

    int last_vowel_pos = -1;
    for (int i = count - 1; i >= 0; i--) {
        if (is_vowel(original[i])) {
            last_vowel_pos = i;
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        cout << original[i] << " ";
        if (i == last_vowel_pos) {
            cout << "! ";
        }
    }
    return 0;
}