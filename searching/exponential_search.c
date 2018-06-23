/*
 * Exponential search
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>

int min(int a, int b)
{
    return (a <= b) ? a : b;
}

int binarySearch(int A[], int l, int r, int x)
{
    int mid;
    
    if (r >= l)
    {
        mid = l + (r - l)/2;
        if (A[mid] == x) {
            return mid;
	}
        if (A[mid] > x) {
            return binarySearch(A, l, mid - 1, x);
	}
        return binarySearch(A, mid + 1, r, x);
    }
    
    return -1;
}

int exponentialSearch(int A[], int n, int x)
{
    int i = 1;
    
    if (A[0] == x) {
        return 0;
    }
    while (i < n && A[i] <= x) {
        i *= 2;
    }
 
    return binarySearch(A, i / 2, min(i, n), x);
}
 

int main(int argc, char *argv[])
{
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    int x = 6;
    int i;
    int result = exponentialSearch(myArr, arrSize, x);
    
    printf("Searching for %d\n", x);
    printf("Current array: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    if (result == -1) {
        printf("Element not in array\n");
    }
    else {
        printf("Element at index %d\n", result);
    }
    return 0;
}
