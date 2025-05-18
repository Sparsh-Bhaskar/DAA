#include <iostream>
#include <cstring>
using namespace std;

// Function to print the optimal parenthesization
void printOptimalParenthesis(int i, int j, int n, int* bracket, char& name) {
    // If only one matrix left in current segment
    if (i == j) {
        cout << name++;
        return;
    }

    cout << "(";

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    printOptimalParenthesis(i, *((bracket + i * n) + j), n, bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printOptimalParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);

    cout << ")";
}

// Function to find the most efficient way to multiply matrices
void matrixChainOrder(int p[], int n) {
    int m[n][n]; // m[i][j] = Minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j] = A[i..j]
    int bracket[n][n]; // To store the optimal parenthesis position

    // cost is zero when multiplying one matrix.
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = 2147483647; // Use a large number instead of INT_MAX

            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;

                    // Each entry bracket[i,j] = k shows where to split the product arr[i]...arr[j] for the minimum cost.
                    bracket[i][j] = k;
                }
            }
        }
    }

    // The first matrix is printed as 'A', next as 'B', and so on
    char name = 'A';

    cout << "Efficient way : ";
    printOptimalParenthesis(1, n - 1, n, (int*)bracket, name);
    cout << "\nMultiplications performed = " << m[1][n - 1] << endl;
}

int main() {
    int arr[] = {2, 1, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, size);

    return 0;
}