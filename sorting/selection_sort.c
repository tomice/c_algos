/*
 * Selection Sort
 * 
 * Concept: An in-place sorting method that divides a list into two parts,
 *          which consists of a sorted part and an unsorted part. In every 
 *          iteration, the minimum element from the unsorted subarray is 
 *          picked and moved to the sorted subarray
 * Time Complexity: Best: O(n^2)
 *                  Average: O(n^2)
 *                  Worst: O(n^2)
 * Auxiliary Space: O(1)
 * Stable: No
 * Method: Selection
 * Uses: Sometimes useful when memory write is costly
 *       Stable with O(n) extra space, such as using lists
 */ 
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

void selectionSort(int A[], int n)
{
    int i;
    int j;
    int tmp;
    int min_index;
    
    for (i = 0; i < n - 1; i++) {
        min_index = i;
	for (j = i + 1; j < n; j++) {
	    if (A[j] < A[min_index]) {
	        min_index = j;
	    }
	}
	swap(&A[min_index], &A[i]);
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

    selectionSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}

