#include <iostream>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to find the minimum number of platforms required
int findMinPlatforms(int arr[], int dep[], int n) {
    // Sort the arrival and departure times
    bubbleSort(arr, n);
    bubbleSort(dep, n);

    // Initialize variables to track platforms needed and result
    int platforms_needed = 0, max_platforms = 0;
    int i = 0, j = 0;

    // Traverse through all events (arrival and departure)
    while (i < n && j < n) {
        // If next event is an arrival, increment platforms needed
        if (arr[i] <= dep[j]) {
            platforms_needed++;
            i++;
        }
        // Else, decrement platforms needed
        else {
            platforms_needed--;
            j++;
        }
        // Update the result if needed
        if (platforms_needed > max_platforms) {
            max_platforms = platforms_needed;
        }
    }

    return max_platforms;
}

int main() {
    // Input arrival and departure times in minutes since midnight
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find and print the minimum number of platforms required
    int result = findMinPlatforms(arr, dep, n);
    cout << "Minimum number of platforms required: " << result << endl;

    return 0;
}