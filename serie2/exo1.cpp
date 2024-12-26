#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev; // for doubly linked list
};
// with sacrifice
void concernation(Node*& D1,Node*& D2){
    if(D1==0){
        D1 = D2;
    }
    else{   
        Node* courrent = D1;
        while(courrent->next != 0){
            courrent = courrent->next;
        }
    courrent->next = D2;
    D2->prev = courrent; // for doubly linked list
    }
    D2=0;
}
// without sacrifice
void concernation (Node* D1,Node* D2,Node*& D3){
    Node* courrent = D1;
    while(courrent->next != 0){
        courrent = courrent->next;
    }
    courrent->next = D2;
    D2->prev = courrent; // for doubly linked list
    D3 = D1;
    D1 = 0;
    D2 = 0;
}


void InserBig(Node*& D,int x){
    Node*NewD = new Node;
    NewD->val = x;
    NewD->next = 0;
    NewD->prev = 0; // for doubly linked list
    if (D == 0){
        D = NewD;
    }else{
        NewD->next = D;
        D->prev = NewD; // for doubly linked list
        D = NewD;
    }
}

void InserEnd(Node*& D,int x){
    Node* NewD = new Node;
    NewD->val = x;
    NewD->next = 0;
    NewD->prev = 0; // for doubly linked list
    if (D == 0){
        D = NewD;
    }else{
        Node* courrent = D;
        while(courrent->next != NULL){
            courrent = courrent->next;
        }

        courrent->next = NewD; 
        NewD->prev = courrent; // for doubly linked list
    }
       
}

void prinLis(Node* D) {
    Node* current = D;
    while (current != 0) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void FillNode(Node* &head1,int N){
    int num = 0;
    for (int i = 0; i < N; i++){
        cout<<"enter the values of the node :\n";
        cin>>num;
        InserEnd(head1, num);
    }
}

void deleteList(Node*& head) {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    int N, M;
    cout<<"Enter the nember of nodes :";
    cin>>N;

    cout << "\nPlease Enter: \n1: For partition without sacrificing original list\n2: For partition with sacrificing original list\n";
    cin >> M;

    Node* head1 = 0;
    Node* head2 = 0;
    Node* head3 = 0;

    FillNode(head1,N);
    FillNode(head2,N);

    cout << "List 1: ";
    prinLis(head1);
    cout << "List 2: ";
    prinLis(head2);


    if (M == 1){

        concernation(head1, head2);
        cout << "Concatenated List: ";
        prinLis(head1);
        deleteList(head1); // to free the memory

    }else if (M == 2){

        concernation(head1, head2, head3);
        cout << "Concatenated List: "; 
        prinLis(head3); 
        deleteList(head1);  // to free the memory   
        deleteList(head2);  // to free the memory
        deleteList(head3);  // to free the memory 

    }


    return 0;
}


