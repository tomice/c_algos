/*
 * Insertion Sort
 *
 * Concept: An in-place sorting method that iterates over the data,
 *          comparing two items at a time. It swaps if one item is larger 
 *          than the other and continues until the data is sorted
 * Time Complexity: Best: O(n)
 *                  Average: O(n^2)
 *                  Worst: O(n^2)
 * Auxiliary Space: O(1)
 * Stable: Yes
 * Method: Insertion
 * Uses: When number of elements is small or only a few elements are misplaced
 */

#include <stdio.h>

void insertionSort(int A[], int size) 
{
    int i;
    int j;
    int key;

    for (i = 1; i < size; i++) {
        key = A[i];
	j = i - 1;
	while (j >= 0 && A[j] > key) {
	    A[j + 1] = A[j];
	    j--;
	}
	A[j + 1] = key;
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
    
    insertionSort(myArr, arrSize);
     
    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}
