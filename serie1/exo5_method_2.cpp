#include <iostream>
#include <climits>
using namespace std;

// Global arrays
int A[100][100];
int B[100][100];
int N;

// Fill matrix from user input
void fillMatrix(int arr[][100]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Enter value for position " << i << "|" << j << ": "<<endl;
            cin >> arr[i][j];
        }
    }
}

// Find minimum value and position
void findMin(int arr[][100], int N, int &minValue, int &minRow, int &minCol) {
    minValue = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] < minValue) {
                minValue = arr[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
}

int main() {
    cout << "Enter the size N: ";
    cin >> N;

    if (N <= 0 || N > 100) {
        cout << "Invalid size N\n";
        return 1;
    }

    cout << "\nFill Matrix A:\n";
    fillMatrix(A);

    cout << "\nFill Matrix B:\n";
    fillMatrix(B);

    // Find minimum positions
    int minA, minRowA, minColA;
    int minB, minRowB, minColB;

    findMin(A, N, minA, minRowA, minColA);
    findMin(B, N, minB, minRowB, minColB);

    // Display original minimums
    cout << "Before swap:\n";
    cout << "Min A is: " << minA << " at position " << minRowA << "|" << minColA << endl;
    cout << "Min B is: " << minB << " at position " << minRowB << "|" << minColB << endl;

    // Swap the minimum values
    swap(A[minRowA][minColA], B[minRowB][minColB]);

    // Display after swap
    cout << "After swap:\n";
    cout << "Min A is now: " << A[minRowA][minColA] << endl;
    cout << "Min B is now: " << B[minRowB][minColB] << endl;

    return 0;
}
