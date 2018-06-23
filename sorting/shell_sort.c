/*
 * Shell Sort
 * 
 * Concept: An in-place comparison sort which is a variation of insert sort.
 *          During insertion sort, elements only move one position ahead.
 *          During shell sort, "far items" can now be exchanged
 * Time Complexity: Best: O(n log n)
 *                  Average: Depends on gap sequence
 *                  Worst: O(n^2)
 * Auxiliary Space: O(1)
 * Stable: No
 * Method: Insertion
 * Uses: Small code size, good for embedded or older hardware
 */ 

#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    
    *a = *b;
    *b = t;
}

void shellSort(int A[], int n)
{
    int i;
    int j;
    int k;

    for (i = n / 2; i > 0; i /= 2) {
        for (j = i; j < n; j++) {
            for (k = j - i; k >= 0; k -= i) {
                if (A[k + i] >= A[k]) {
                    break;
                }
                else {
		    swap(&A[k], &A[k + i]);
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int myArr[] = {5, 2, 4, 6, 1, 3};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    int i;

    printf("Before sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    shellSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}

