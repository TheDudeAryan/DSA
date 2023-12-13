#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;    
    Node(int val) : data(val), next(nullptr) {}
};


int linearSearch(Node* head, int target) {
    int index = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return index;
        }
        current = current->next;
        ++index;
    }
    return -1;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    std::cout << "Linked List: ";
    displayList(head);
    int targetElement = 3;
    int result = linearSearch(head, targetElement);
    if (result != -1) {
        cout << "Element " << targetElement << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << targetElement << " not found in the linked list." << endl;
    }
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    return 0;
}