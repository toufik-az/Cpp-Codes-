 #include<iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node* prev; // for doubly linked list
};

void insertFront(Node* &head, int x ) {
    Node * newNode = new Node;
    newNode->info = x;
    newNode->next = head;
    newNode->prev = 0; // for doubly linked list
    if(head != 0) 
        head->prev = newNode; // for doubly linked list
    head = newNode;
}

void insertEnd(Node * &head, int x) {
    if(head == 0) 
        insertFront(head, x);
    else {
        Node *current = head;
        while(current->next != 0)
            current = current->next;
        current->next = new Node;
        current->next->info = x;
        current->next->next = 0;
        current->next->prev = current; // for doubly linked list
    }
}

void create(Node* &head, int n) {
    int x;
    for(int i = 0; i < n; i++) {
        cout << "Enter an integer: ";
        cin >> x;
        insertFront(head, x);
    }
}

void partitionWithoutSacrifice(Node *D, Node *&D1, Node *&D2, int n) {
    if(D != 0) {
        Node *current = D;
        for(int i = 0; i < n/2; i++) {
            insertEnd(D1, current->info);
            current = current->next;
        }
        while(current != 0) {
            insertEnd(D2, current->info);
            current = current->next;
        }
    }
}

void partitionWithSacrifice(Node *D, Node *&D1, int n) {
    if(D != 0) {
        Node *current = D;
        Node *pred;
        for(int i = 0; i < n/2; i++) {
            pred = current;
            current = current->next;
        }
        pred->next = 0;
        D1 = current;
        D1->prev = 0; // for doubly linked list
    }
}

void display(Node *current) {
    if(current == 0)
        cout << "Empty list";
    else
        while(current != 0) {
            cout << current->info << " -> ";
            current = current->next;
        }
    cout << "NULL" << endl;
}

void deleteList(Node *& head) {
    Node * temp;
    while(head != 0) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *D = 0;
    Node *D1 = 0;
    Node *D2 = 0;


    int n,m;
    do {
        cout << "Enter list size an even number for list size: ";
        cin >> n;
        if(n % 2 != 0)
            cout << "\nPlease enter an even number only!\n\n";
    } while(n % 2 != 0);
    create(D, n);

    cout << "\nList: \n";
    display(D);


    cout << "\nPlease Enter: \n1: For partition without sacrificing original list\n2: For partition with sacrificing original list\n";
    cin >> m;

    if(m == 1) {
        partitionWithoutSacrifice(D, D1, D2, n);
        cout << "\nFirst list obtained: \n";
        display(D1);
        cout << "\nSecond list obtained: \n";
        display(D2);
    } else if(m == 2) {
        partitionWithSacrifice(D, D1, n);
        cout << "\nFirst list obtained: \n";
        display(D);
        cout << "\nSecond list obtained: \n";
        display(D1);
    }

    deleteList(D1);
    deleteList(D2);
    deleteList(D);
}