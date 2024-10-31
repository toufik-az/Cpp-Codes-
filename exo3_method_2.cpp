#include<iostream>
using namespace std;

void fill(int n, int** A) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter value for A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
}

void print(int n, int** A, const string &name) {
    cout << "\nArray " << name << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void calculate_Sum(int n, int** A, int** B, int** result) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void calculate_Product(int n, int** A, int** B, int** result) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int count_Null_Values(int n, int** A) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

void swap_Min_A_With_Max_B(int n, int** A, int** B) {
    int min_A = A[0][0], max_B = B[0][0];
    int min_Row_A = 0, min_Col_A = 0, max_Row_B = 0, max_Col_B = 0;
    
    // Find min in A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] < min_A) {
                min_A = A[i][j];
                min_Row_A = i;
                min_Col_A = j;
            }
        }
    }
    
    // Find max in B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i][j] > max_B) {
                max_B = B[i][j];
                max_Row_B = i;
                max_Col_B = j;
            }
        }
    }
    
    // Swap min in A with max in B
    int temp = A[min_Row_A][min_Col_A];
    A[min_Row_A][min_Col_A] = B[max_Row_B][max_Col_B];
    B[max_Row_B][max_Col_B] = temp;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    
    // Dynamic allocation of arrays
    int** A = new int*[n];
    int** B = new int*[n];
    int** sum = new int*[n];
    int** product = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        sum[i] = new int[n];
        product[i] = new int[n];
    }
    
    // Fill arrays
    cout << "\nInitializing array A:\n";
    fill(n, A);
    cout << "\nInitializing array B:\n";
    fill(n, B);
    
    // Calculate sum and product
    calculate_Sum(n, A, B, sum);
    calculate_Product(n, A, B, product);
    
    // Count null values
    int null_Count_A = count_Null_Values(n, A);
    int null_Count_B = count_Null_Values(n, B);
    
    // Swap minimum of A with maximum of B
    swap_Min_A_With_Max_B(n, A, B);
    
    // Print arrays and results
    print(n, A, "A (After Swap)");
    print(n, B, "B (After Swap)");
    print(n, sum, "Sum");
    print(n, product, "Product");
    
    cout << "\nNumber of null values in A: " << null_Count_A << endl;
    cout << "Number of null values in B: " << null_Count_B << endl;
    
    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] sum[i];
        delete[] product[i];
    }
    delete[] A;
    delete[] B;
    delete[] sum;
    delete[] product;
    
    return 0;
}
