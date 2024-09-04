#include <stdio.h> 

void linear_search(int *arr, int n, int target) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            printf("Element Found at index %d.\n", i);
            found = 1;
            break;
        }
    }
    if(found != 1) {
        printf("Element not found in the array!!\n");
    }
}

void binary_search(int *arr, int n, int key) {
    int left = 0;
    int right = n-1;
    int found = 0;

    while (left <= right) {

        // calculating mid point
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            printf("Element found at index %d.\n", mid);
            found = 1;
        }

        // If key greater than arr[mid], ignore left half
        if (arr[mid] < key) {
            left = mid + 1;
        }

        // If key is smaller than or equal to arr[mid],
        // ignore right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then element was not present
    if(found != 1) {
        printf("Element not found in the array!!\n");
    }
}