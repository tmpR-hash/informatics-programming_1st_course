#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void remove_duplicates(int queue[], int& front, int& back) {
    if (front == back) return; 

    int temp[MAX_SIZE]; 
    int tempback = 0;

    int last = queue[front]; 
    temp[tempback++] = last; 
    front = (front + 1) % MAX_SIZE; 

    while (front != back) {
        int current = queue[front]; 
        front = (front + 1) % MAX_SIZE; 

        if (current != last) {
            temp[tempback++] = current;
            last = current; 
        }
    }

    front = 0; 
    back = 0;
    for (int i = 0; i < tempback; i++) {
        queue[back++] = temp[i]; 
    }
}

int main() {
    int queue[MAX_SIZE]; 
    int front = 0;       
    int back = 0;

    int input[] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5 };
    int input_size = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < input_size; i++) {
        if ((back + 1) % MAX_SIZE != front) { 
            queue[back] = input[i];
            back = (back + 1) % MAX_SIZE;
        }
    }

    remove_duplicates(queue, front, back);

    while (front != back) {
        cout << queue[front] << " ";
        front = (front + 1) % MAX_SIZE;
    }
    cout << endl;

    return 0;
}