#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr[] = {15, 11, 3, 22, 5, 4};
    int target = 8;
    int n = sizeof(arr) / sizeof(int);
    bool found = false;

    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTarget: %d\n", target);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                printf("Two Sum Found at indices: (%d, %d)\n", i, j);
                found = true;
                goto done;
            }
        }
    }

done:
    if(!found) {
        printf("No two numbers add up to the target.\n");
    }

    return 0;
}