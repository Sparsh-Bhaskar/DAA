#include <iostream>
#include <cstring> // For memset

using namespace std;

// A structure to represent an item with profit and weight
struct Item {
    int profit;
    int weight;
};

// Function to swap two items
void swap(Item& a, Item& b) {
    Item temp = a;
    a = b;
    b = temp;
}

// Function to sort items based on profit-to-weight ratio using bubble sort
void bubbleSort(Item arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            double r1 = (double)arr[j].profit / arr[j].weight;
            double r2 = (double)arr[j + 1].profit / arr[j + 1].weight;
            if (r1 < r2) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to calculate the maximum profit for the fractional knapsack
double fractionalKnapsack(Item arr[], int n, int W) {
    // Sort items by profit-to-weight ratio
    bubbleSort(arr, n);

    double totalProfit = 0.0;
    int currentWeight = 0;

    // Iterate through all items
    for (int i = 0; i < n; i++) {
        // If adding the entire item doesn't exceed capacity, add it
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            totalProfit += arr[i].profit;
        } else {
            // Add fractional part of the item
            int remainingWeight = W - currentWeight;
            totalProfit += arr[i].profit * ((double)remainingWeight / arr[i].weight);
            break; // Knapsack is full
        }
    }

    return totalProfit;
}

int main() {
    // Array of items with profit and weight
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 50; // Capacity of knapsack

    // Calculate and print the maximum profit
    double maxProfit = fractionalKnapsack(arr, n, W);
    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}