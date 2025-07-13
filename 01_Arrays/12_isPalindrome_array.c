#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        if (arr[start] != arr[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    if (isPalindrome(arr, n)){
        printf("The array is a palindrome.\n");
    } else {
        printf("The array is NOT a palindrome.\n");
    }

    return 0;
}