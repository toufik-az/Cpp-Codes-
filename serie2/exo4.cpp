#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev; // for doubly linked list

};

void insertEnd(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->val = x;
    newNode->next = nullptr;
    
    if (!head) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void fillList(Node*& head) {
    int n, x;
    cout << "Enter list size: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter value " << i+1 << ": ";
        cin >> x;
        insertEnd(head, x);
    }
}

void sortList(Node* head) {
    if (head == nullptr || head->next == nullptr) 
        return;
    
    Node* i;
    bool swapped;
    
    do {
        swapped = false;
        i = head;
        
        while (i->next != nullptr) {
            if (i->val > i->next->val) {
                int temp = i->val;
                i->val = i->next->val;
                i->next->val = temp;
                swapped = true;
            }
            i = i->next;
        }
    } while (swapped);
}

void deleteList(Node*& head) {
    Node* courent = head;
    while(courent) {
        Node* temp = courent;
        courent = courent->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    
    fillList(head);
    
    cout << "\nBefore sorting: ";
    display(head);
    
    sortList(head);
    
    cout << "After sorting: ";
    display(head);
    
    deleteList(head);
    return 0;
}