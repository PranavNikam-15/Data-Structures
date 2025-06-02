// Brute Force Method

#include <stdio.h>

void MaxSubArraySum(int arr[], int n) {
    int maxSum = arr[0];
    int minSum = arr[0]; 

    // Outer loop defines the starting index of the subarray
    for (int i = 0; i < n; i++) {
        // Middle loop defines the ending index of the subarray
        for (int j = i; j < n; j++) {
            int currSum = 0;  // Initialize current subarray sum

            // Inner loop to calculate sum of subarray from index i to j
            for (int k = i; k <= j; k++) {
                currSum += arr[k];
            }

        // Update maxSum and minSum if needed
            if (currSum > maxSum) maxSum = currSum;
            if (currSum < minSum) minSum = currSum;

        }
    }

    printf("Maximum Subarray Sum = %d\n", maxSum);
    printf("Minimum Subarray Sum = %d\n", minSum);
}

int main() {
    int n;

    printf("Enter the size of Array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    MaxSubArraySum(arr, n);

    return 0;
}