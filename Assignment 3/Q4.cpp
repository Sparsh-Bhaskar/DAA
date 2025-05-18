#include <iostream>
using namespace std;

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int maxSquareSubMatrix(int mat[][4], int n, int m) {
    int dp[n][m];
    int maxSize = 0;

    // Initialize the first row and column
    for (int i = 0; i < n; i++) {
        dp[i][0] = mat[i][0];
        if (dp[i][0] > maxSize) maxSize = dp[i][0];
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = mat[0][j];
        if (dp[0][j] > maxSize) maxSize = dp[0][j];
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                if (dp[i][j] > maxSize) maxSize = dp[i][j];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxSize;
}

int main() {
    // int mat[6][6] = {
    //     {0, 1, 1, 0, 1, 0},
    //     {1, 1, 0, 1, 0, 0},
    //     {0, 1, 1, 1, 0, 0},
    //     {1, 1, 1, 1, 0, 0},
    //     {1, 1, 1, 1, 1, 0},
    //     {0, 0, 0, 0, 0, 0}
    // };

    int mat[3][4] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    int n = 3, m = 4;
    cout << "Maximum size of square sub-matrix with all 1s: " << maxSquareSubMatrix(mat, n, m) << endl;

    return 0;
}