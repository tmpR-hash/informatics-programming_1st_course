#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void print_list(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

double calculate_average(Node* node) {
    if (node == nullptr) return 0;

    int sum = 0;
    int count = 0;
    Node* current = node;
         
    while (current != nullptr) {
        sum += current->data;
        count++;
        current = current->next;
    }

    return (count == 0) ? INFINITY : (double)sum / count;
}

void task_execution(Node** head_ref) {
    if (*head_ref == nullptr) return;

    Node* current = *head_ref;

    while (current != nullptr) {
        Node* next_node = current->next; 
        double avg = calculate_average(current->next);

        if (current->data > avg && current->next != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                *head_ref = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete current;
        }
        current = next_node;
    }
}


int main() {
    Node* head = nullptr;
    int n, elements;

    cout << "Enter amount of list elements: ";
    cin >> n;

    cout << "Enter list elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> elements;
        push(&head, elements);
    }

    cout << "Originsl list: ";
    print_list(head);
    task_execution(&head);
    cout << "New list: ";
    print_list(head);
    return 0;
}