// Prefix Sum Method

#include <stdio.h>

void MaxSubArraySum(int arr[], int n) {
    int maxSum = arr[0];
    int minSum = arr[0];

    int prefix[n];
    prefix[0] = arr[0];

    // calculate prefix sum array
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Now iterate over all possible subarrays [i..j]
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currSum = (i == 0) ? prefix[j] : (prefix[j] - prefix[i-1]);

            // Update maxSum and minSum if needed
            if (currSum > maxSum){
                maxSum = currSum;
            }
            if (currSum < minSum) {
                minSum = currSum;
            }
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