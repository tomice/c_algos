/*
 * Comb sort
 *
 * Concept: An in-place sorting method that works by eliminating small values 
 *          near the end of a list. The shrink factor is generally defined 
 *          as k = 1.3
 * Time complexity: Best: O(n log n)
 *                  Average: O(n^2)
 *                  Worst: O(n^2)
 * Auxiliary Space: O(1)
 * Stable: No
 * Method: Exchanging
 * Usage: Faster than bubble sort, but has very little usage otherwise
 */

#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

int findNextGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1) {
        return 1;
    }
    else {
        return gap;
    }
}

/* The bool helps prevent it from being a constant n^2 runtime, 
 * breaking the loop if it's already sorted. Slight optimization
 */
void combSort(int A[], int n)
{
    bool swapped = true;
    int i;
    int gap;
    
    while (gap != 1 || swapped == true) {
        gap = findNextGap(gap);
	swapped = false;
	for (i = 0; i < n - gap; i++) {
	    if (A[i] > A[i + gap]) {
	        swap(&A[i], &A[i + gap]);
	        swapped = true;
	    }
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

    combSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}

