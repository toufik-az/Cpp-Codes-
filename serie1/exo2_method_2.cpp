#include<iostream>
using namespace std;

void fill(int n, int* A) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the value number " << i + 1 << " :\n";
        cin >> A[i];
    }
}

void findMinMax(int n, int* A, int &minValue, int &maxValue, int &minIndex, int &maxIndex) {
    minValue = A[0];
    maxValue = A[0];
    minIndex = 0;
    maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < minValue) {
            minValue = A[i];
            minIndex = i;
        }
        if (A[i] > maxValue) {
            maxValue = A[i];
            maxIndex = i;
        }
    }
}

void sortArray(int n, int* A) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void print(int n, int* A) {
    for (int i = 0; i < n; i++) {
        cout << "The value of number " << i + 1 << " is: " << A[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int* A = new int[n];
    int minValue, maxValue, minIndex, maxIndex;
    
    // Fill array
    fill(n, A);
    
    // Find min and max values
    findMinMax(n, A, minValue, maxValue, minIndex, maxIndex);
    
    // Sort array
    sortArray(n, A);
    
    // Print sorted array and results
    print(n, A);
    cout << "\nMinimum value: " << minValue << " at index " << minIndex << endl;
    cout << "Maximum value: " << maxValue << " at index " << maxIndex << endl;
    
    delete[] A;
    return 0;
}
