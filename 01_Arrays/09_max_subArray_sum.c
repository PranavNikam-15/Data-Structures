// Kadane's Algorithm

#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void kadanes(int arr[], int n) {
    int maxSum = arr[0];
    int currSum = 0;

    for(int i=0; i<n; i++){
        currSum = MAX(arr[i], currSum + arr[i]);
        maxSum = MAX(currSum, maxSum);
    }
    printf("Maximum Subarray Sum = %d\n", maxSum);
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
    kadanes(arr, n);
    return 0;
}