#include <iostream>
#include <cstring> // For memset

using namespace std;


struct Job {
    char id;     // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
};

// Function to swap two jobs
void swap(Job& a, Job& b) {
    Job temp = a;
    a = b;
    b = temp;
}

// Function to sort jobs according to profit using bubble sort
void bubbleSort(Job arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].profit < arr[j + 1].profit) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to find the maximum profit job sequence
void jobScheduling(Job arr[], int n) {
    // Sort all jobs according to decreasing order of profit
    bubbleSort(arr, n);

    // To keep track of free time slots
    bool slot[n];

    // To store result (sequence of jobs)
    char result[n];

    // Initialize all slots to be free
    memset(slot, false, sizeof(slot));

    // Variable to store the total profit
    int totalProfit = 0;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == false) {
                result[j] = arr[i].id; // Add this job to result
                slot[j] = true;        // Mark this slot as occupied
                totalProfit += arr[i].profit; // Add profit
                break;
            }
        }
    }

    // Print the result
    cout << "The job sequence for maximum profit is: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;

    // Print the total profit
    cout << "The maximum profit is: " << totalProfit << endl;
}

int main() {
    // Array of jobs
    Job arr[] = { {'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    jobScheduling(arr, n);

    return 0;
}