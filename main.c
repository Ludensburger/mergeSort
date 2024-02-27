#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function declaration/prototype
void merge(const int *leftArr, int leftSize, const int *rightArr, int rightSize, int *arr);

// Main function/definition
void mergeSort(int *arr, int length) {

    // Base Case: If array length is 1 or less, it's already sorted
    if (length <= 1) {
        return;
    }

    // -for readability purposes
    // -Calculate mid-point and sizes of left and right subarrays
    int mid = length / 2;
    int leftSize = mid;
    int rightSize = length - mid;

    // -or pwede ra diritso leftArr[mid] & rightArr[length - mid]
    // -Create left and right subarrays
    int leftArr[leftSize];
    int rightArr[rightSize];

    // Split the array into left and right subarrays
    int i = 0; // left array
    int j = 0; // right array
    for (; i < length; i++) {
        //      -copy original array to left array
        //      -Copy elements to left array if before mid, else to right array
        if (i < mid) {
            leftArr[i] = arr[i];

            //      copy original array to right array
        } else {
            rightArr[j++] = arr[i];
            //            j++;
        }
    }

    //  -Recursion part
    //  -Recursively sort left and right subarrays
    mergeSort(leftArr, mid);                            // divide left
    mergeSort(rightArr, length - mid);                  // divide right
    merge(leftArr, leftSize, rightArr, rightSize, arr); // Merge sorted subarrays
}

// Printing function
void print(int *arr, int length) {

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {

        printf("%d", arr[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }

    printf("\n");
}

// Helper function/definition
void merge(const int *leftArr, int leftSize, const int *rightArr, int rightSize, int *arr) {

    int i = 0, l = 0, r = 0;

    //  -Check conditions for merging
    //  -while there's elements in the left and right arrays, we will continue adding elements to the original array array
    //  -Merge left and right subarrays into arr
    while (l < leftSize && r < rightSize) {

        //      -check which element is smaller
        //      -Compare elements from left and right subarrays and merge them into arr
        if (leftArr[l] < rightArr[r]) {
            arr[i++] = leftArr[l++];
            // i++;
            // l++;
        } else {
            arr[i++] = rightArr[r++];
            // i++;
            // r++;
        }
    }
    //  Copy remaining elements from left subarray, if any
    while (l < leftSize) {
        arr[i++] = leftArr[l++];
        // i++;
        // l++;
    }
    //  Copy remaining elements from right subarray, if any
    while (r < rightSize) {
        arr[i++] = rightArr[r++];
        // i++;
        // r++;
    }
}

int main() {

    // tester array
    int arr[] = {12, 11, 13, 5, 6, 7, 10};

    // -2nd tester array with random values
    // -array size is predefined kay kapoy nag set
    //      edit: ako nalang ge set ang dummy values
    int random[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // Seed the random number generator
    srand(time(NULL));

    int randLength = sizeof(random) / sizeof(random[0]);

    // add random values to the array
    for (int i = 0; i < randLength; i++) {
        random[i] = rand() % 100; // Generates random numbers between 0 and 99
    }

    // get the length of the first array
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("1st Array List \n");
    mergeSort(arr, length);
    print(arr, length);

    printf("Random List \n");
    mergeSort(random, randLength);
    print(random, randLength);

    return 0;
}