#include <iostream>
using namespace std;

// Process node
struct Process {
    int id;
    int prior;
    Process* next;
};

void addProcess(Process* &head) {
    Process* newProcess = new Process;
    
    cout << "Enter process ID: ";
    cin >> newProcess->id;
    cout << "Enter process priority: ";
    cin >> newProcess->prior;
    newProcess->next = NULL;
    
    if (head == NULL) {  // empty list
        head = newProcess;
        return;
    }
    
    Process* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newProcess;
}

void showList(Process* head, int listNumber) {
    cout << "List " << listNumber << ": ";
    Process* temp = head;
    while (temp != NULL) {
        cout << temp->id << "," << temp->prior << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Reverse list order
Process* reverseList(Process* head) {
    Process *prev = NULL;
    Process *current = head;
    Process *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Delete by priority
void deleteProcess(Process* &head, int priority) {
    if (head == NULL) return;
    
    if (head->prior == priority) {
        Process* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Process* temp = head;
    while (temp->next != NULL) {
        if (temp->next->prior == priority) {
            Process* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
}

int main() {
    int M, N;
    
    cout << "Enter number lists do you want : ";
    cin >> M;
    cout << "Enter number processes in each list : ";
    cin >> N;
    
    // Create lists
    Process** lists = new Process*[M];
    for (int i = 0; i < M; i++) {
        lists[i] = NULL;
    }
    

    for (int i = 0; i < M; i++) {
        cout << "\nEntering data for list " << i << endl;
        for (int j = 0; j < N; j++) {
            cout << "Process " << j << ":\n";
            addProcess(lists[i]);
        }
    }
    
    cout << "\nOriginal lists:\n";
    for (int i = 0; i < M; i++) {
        showList(lists[i], i);
    }
    
    // Reverse the order of each list
    for (int i = 0; i < M; i++) {
        lists[i] = reverseList(lists[i]);
    }
    
    cout << "\nReversed lists:\n";
    for (int i = 0; i < M; i++) {
        showList(lists[i], i);
    }
    
    int priority;
    cout << "\nEnter priority to delete: ";
    cin >> priority;
    
    // Delete matching priority
    for (int i = 0; i < M; i++) {
        deleteProcess(lists[i], priority);
    }
    
    cout << "\nLists after deleting priority " << priority << ":\n";
    for (int i = 0; i < M; i++) {
        showList(lists[i], i);
    }
    
    return 0;
}