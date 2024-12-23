  // static allocation.


#include <iostream>
using namespace std;
// Product structure
struct Product {
    int code;
    float weight;
    float price;
};

// Initialize product by reference
void initializeProduct(Product &p, int code, float weight, float price) {
    p.code = code;
    p.weight = weight;
    p.price = price;
}

// Update product by address
void modifyProduct(Product* p, int newCode, float newWeight, float newPrice) {
    p->code = newCode;
    p->weight = newWeight;
    p->price = newPrice;
}

// Display product info by value
void displayProduct(Product p) {
    cout << "Product Code: " << p.code
              << ", Weight: " << p.weight
              << ", Price: " << p.price << endl;
}

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    // Create array of products
    Product* products = new Product[n];
    
    // Get user input for each product
    for(int i = 0; i < n; i++) {
        int code;
        float weight, price;
        
        cout << "\nEnter details for product " << i+1 << ":\n";
        cout << "Code: ";
        cin >> code;
        cout << "Weight: ";
        cin >> weight;
        cout << "Price: ";
        cin >> price;
        
        initializeProduct(products[i], code, weight, price);
    }

    // Display original values
    cout << "\nOriginal products:" << endl;
    for(int i = 0; i < n; i++) {
        displayProduct(products[i]);
    }

    // Get modification values
    cout << "\nModify products:" << endl;
    for(int i = 0; i < n; i++) {
        int newCode;
        float newWeight, newPrice;
        
        cout << "\nEnter new details for product " << i+1 << ":\n";
        cout << "New code: ";
        cin >> newCode;
        cout << "New weight: ";
        cin >> newWeight;
        cout << "New price: ";
        cin >> newPrice;
        
        modifyProduct(&products[i], newCode, newWeight, newPrice);
    }

    // Display modified values
    cout << "\nModified products:" << endl;
    for(int i = 0; i < n; i++) {
        displayProduct(products[i]);
    }

    // Free memory
    delete[] products;
    
    return 0;
}