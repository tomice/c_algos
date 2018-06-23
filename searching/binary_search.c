/*
 * Binary search
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>

int binarySearch(int A[], int l, int r, int x)
{
    int mid;

    if (r >= 1) {
        mid = 1 + (r - 1) / 2;
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

int main(int argc, char *argv[])
{
    int i;
    int x = 6;
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    int result = binarySearch(myArr, 0, arrSize - 1, x);
    
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
