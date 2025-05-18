#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(int arr[], int l, int m, int h) 
{
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return (leftSum + rightSum);
}

int MaxSum(int arr[], int l, int h) 
{
    if (l > h)
        return INT_MIN;

    if (l == h)
        return arr[l];

    int m = l + (h - l) / 2;

    int leftSum = MaxSum(arr, l, m);
    int rightSum = MaxSum(arr, m + 1, h);
    int crossSum = maxCrossingSum(arr, l, m, h);

    if (leftSum >= rightSum && leftSum >= crossSum)
        return leftSum;
    else if (rightSum >= leftSum && rightSum >= crossSum)
        return rightSum;
    else
        return crossSum;
}

int maxSubarraySum(int arr[], int n) {
    return MaxSum(arr, 0, n - 1);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << "max subarray sum is : " << maxSubarraySum(arr, 8);
    return 0;
}