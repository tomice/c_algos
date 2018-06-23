/*
 * Linear search
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>

int linearSearch(int A[], int size, int x)
{
    int i;

    for (i = 0; i < size; i++) {
        if (A[i] == x) {
	    return i;
	}
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int i;
    int x = 6;
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    int result = linearSearch(myArr, arrSize, x);
    
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
