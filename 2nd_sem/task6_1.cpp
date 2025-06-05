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

void task_execution(Node** head_ref) {
    if (*head_ref == nullptr) return;

    Node* current = *head_ref;
    Node* first_even = nullptr;
    Node* last_even = nullptr;

    while (current != nullptr) {
        if (current->data % 2 == 0) {
            first_even = current;
            break;
        }
        current = current->next;
    }

    current = *head_ref;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            last_even = current;
        }
        current = current->next;
    }

    if (first_even != nullptr && last_even != nullptr && first_even == last_even) {
        if (first_even->prev != nullptr) {
            first_even->prev->next = first_even->next;
        }
        else {
            *head_ref = first_even->next;
        }
        if (first_even->next != nullptr) {
            first_even->next->prev = first_even->prev;
        }
        delete first_even;
    }
    else {
        if (first_even != nullptr) {
            if (first_even->prev != nullptr) {
                first_even->prev->next = first_even->next;
            }
            else {
                *head_ref = first_even->next;
            }
            if (first_even->next != nullptr) {
                first_even->next->prev = first_even->prev;
            }
            delete first_even;
        }

        if (last_even != nullptr) {
            if (last_even->prev != nullptr) {
                last_even->prev->next = last_even->next;
            }
            else {
                *head_ref = last_even->next;
            }
            if (last_even->next != nullptr) {
                last_even->next->prev = last_even->prev;
            }
            delete last_even;
        }
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