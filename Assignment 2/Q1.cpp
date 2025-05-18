#include <iostream>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to sort activities by finish time using a simple bubble sort
void sortActivities(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (finish[j] > finish[j + 1]) {
                swap(finish[j], finish[j + 1]);
                swap(start[j], start[j + 1]);
            }
        }
    }
}

// Function to perform activity selection
void activitySelection(int start[], int finish[], int n) {
    // Array to store the indices of the selected activities
    int selectedActivities[n];
    int count = 0;

    // Sort activities by finish time
    sortActivities(start, finish, n);

    // The first activity always gets selected
    selectedActivities[count++] = 0;
    int lastFinishTime = finish[0];

    // Iterate through the sorted activities
    for (int i = 1; i < n; ++i) {
        // If the start time of the current activity is greater or equal to
        // the finish time of the last selected activity, select it
        if (start[i] >= lastFinishTime) {
            selectedActivities[count++] = i;
            lastFinishTime = finish[i];
        }
    }

    // Print the selected activities
    cout << "The selected activities are:\n";
    for (int i = 0; i < count; ++i) {
        int index = selectedActivities[i];
        cout << "Start: " << start[index] << ", Finish: " << finish[index] << "\n";
    }
}

int main() {
    // Input start and finish times
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    // Get the maximum set of activities
    activitySelection(start, finish, n);

    return 0;
}