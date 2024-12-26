#include <iostream>
using namespace std;

struct Node {
    int coef;  
    int exp;   
    Node* next;
};

// Add a new term to end of polynomial
void addTerm(Node*& head, int coef, int exp) {
    Node* newNode = new Node;
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Create polynomial 
void createPoly(Node*& head) {
    int n;
    cout << "How many terms? :  ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int coef, exp;
        cout << "Enter coefficient and exponent for term " << i+1 << ": ";
        cin >> coef >> exp;
        addTerm(head, coef, exp);
    }
}

// Display polynomial
void displayPoly(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->coef << "x^" << current->exp;
        if (current->next != nullptr) {
            cout << " + ";
        }
        current = current->next;
    }
    cout << endl;
}

// Add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* p1 = poly1;
    Node* p2 = poly2;
    
    // Add terms from both polynomials
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exp > p2->exp) {
            addTerm(result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if (p2->exp > p1->exp) {
            addTerm(result, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else {  // Same exponents - add coefficients
            if (p1->coef + p2->coef != 0) {
                addTerm(result, p1->coef + p2->coef, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // Add remaining terms from poly1
    while (p1 != nullptr) {
        addTerm(result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    
    // Add remaining terms from poly2
    while (p2 != nullptr) {
        addTerm(result, p2->coef, p2->exp);
        p2 = p2->next;
    }
    
    return result;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    
    cout << "First polynomial:\n\n";
    createPoly(poly1);
    
    cout << "Second polynomial:\n\n";
    createPoly(poly2);
    
    cout << "\nFirst polynomial: ";
    displayPoly(poly1);
    
    cout << "Second polynomial: ";
    displayPoly(poly2);
    
    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    displayPoly(sum);
    
    return 0;
}