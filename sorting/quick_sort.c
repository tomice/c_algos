/*
 * Quick Sort:
 * 
 * Concept: A divide and conquer sort similar to selection sort that divides
 *          an array into two smaller arrays called low and high, picks a
 *          pivot value, reorders the elements so that everything before the
 *          pivot value is smaller, and everything after is greater, then
 *          recursively repeats
 * Time Complexity: Best: O(n log n) to O(n) depending
 *                  Average: O(n log n)
 *                  Worst: O(n^2)
 * Auxiliary Space: O(log n) to O(n) depending
 * Stable: Usually no
 * Method: Partitioning
 * Uses: Cache friendly, tail recursive, and good for when merge sort
 *       takes up too much storage
 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

int partition(int A[], int high, int low)
{
    int j;
    int i = (low - 1);
    int pivot = A[high];

    for (j = low; j <= high - 1; j++) {
        if (A[j] <= pivot) {
	    i++;
	    swap(&A[i], &A[j]);
	}
    }
    swap(&A[i + 1], &A[high]);
    
    return (i + 1);
}

void quickSort(int A[], int high, int low)
{
    int part_index;
    
    if (low < high) {
        part_index = partition(A, high, low);
	quickSort(A, part_index - 1, low);
	quickSort(A, high, part_index + 1);
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

    quickSort(myArr, arrSize - 1, 0);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}

