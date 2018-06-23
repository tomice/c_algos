/*
 * Bubble sort
 *
 * Concept: An in-place sorting method that compares each value against its 
 *          neighboring number and swaps if necessary until the list is sorted
 * Time complexity: Best: n
 *                  Average: O(n^2)
 *                  Worst: O(n^2)
 * Auxiliary Space: O(1)
 * Stable: Yes
 * Method: Exchanging
 * Usage: Basically never use it
 */

#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int t = *a;
    
    *a = *b;
    *b = t;
}

/* The bool helps prevent it from being a constant n^2 runtime, 
 * breaking the loop if it's already sorted. It's a slight optimization
 */
void bubbleSort(int A[], int n)
{
    bool swapped;
    int i; 
    int j;
    
    for (i = 0; i < n - 1; i++) {
        swapped = false;
	for (j = 0; j < n - i - 1; j++) {
	    if (A[j] > A[j + 1]) {
		swap(&A[j], &A[j + 1]);
		swapped = true;
	    }
	}
	if (swapped == false) {
	    break;
	}
    }
}

int main(int argc, char *argv[])
{
    int i;
    int myArr[] = {5, 2, 4, 6, 1, 3};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);

    printf("Before sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    bubbleSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}

