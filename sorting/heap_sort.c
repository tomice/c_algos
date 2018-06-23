/*
 * Heap sort
 *
 * Concept: An in-place sorting method that divides its input into 
 *          sorted/unsorted regions and shrinks each one by extracting the 
 *          largest element, then moving it to the sorted region. Basically a 
 *          selection sort, but it utilizes the heap to be a bit faster
 * Time Complexity: Best: O(n log n)
 *                  Average: O(n log n)
 *                  Worst: O(n log n)
 * Auxiliary Space: O(1)
 * Stable: No
 * Method: Selection
 * Uses: Sort a nearly sorted/K sorted array
 *       k largest/smallest elements in an array
 *       Competes with Quicksort, which has a better typical time but worse 
 *       worst-case time. Also competes with Mergesort, which requires more 
 *       auxiliary space
 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;
    *b = t;
}

void heapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest]) {
        largest = left;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&A[i], &A[largest]);
	heapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    int i;
    
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }

    for (i = n - 1; i >= 0; i--) {
        swap(&A[0], &A[i]);
	heapify(A, i, 0);
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
    
    heapSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}
