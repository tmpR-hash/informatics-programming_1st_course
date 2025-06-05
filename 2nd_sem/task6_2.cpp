#include <iostream>
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

Node* find_first_max(Node* head) {
    if (head == nullptr) return nullptr;

    Node* max_node = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data > max_node->data) {
            max_node = current;
        }
        current = current->next;
    }

    return max_node;
}

void task_execution(Node** head_ref) {
    if (*head_ref == nullptr) return;

    Node* max_node = find_first_max(*head_ref);
    if (max_node == *head_ref) return;

    if (max_node->prev != nullptr)
        max_node->prev->next = nullptr;

    Node* tail = max_node;
    while (tail->next != nullptr)
        tail = tail->next;

    tail->next = *head_ref;
    (*head_ref)->prev = tail;

    *head_ref = max_node;
    max_node->prev = nullptr;
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