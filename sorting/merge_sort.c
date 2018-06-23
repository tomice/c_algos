/*
 * Merge Sort:
 * 
 * Concept: Uses a divide and conquer approach to recursively sort through
 *          data by dividing the unsorted list into n sublists, each containing
 *          a single sorted element, and repeatly merging the sublists until
 *          a single sublist remains
 * Time Complexity: Best: O(n log n)
 *                  Average: O(n log n)
 *                  Worst: O(n log n)
 * Auxiliary Space: O(n)
 * Stable: Yes
 * Method: Merging
 * Uses: Sorting linked lists in n log n time
 *       Inversion counting problem
 *       External sorting
 */

#include <stdio.h>

void merge(int A[], int p, int q, int r)
{
    int i;
    int j;
    int k;
    int n1 = q - p + 1;
    int n2 = r - q;
    
    /* Create two temp arrays for breaking up original array */
    int L[n1], R[n2];

    /* Copy array contents into temp arrays */
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }

    i = 0;
    j = 0;
    k = p;
    
    /* Merge elements back into array */
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
	    A[k] = L[i];
	    i++;
	}
	else {
	    A[k] = R[j];
	    j++;
	}
	k++;
    }
    
    /* Copy remaining elements */
    while (i < n1) {
        A[k] = L[i];
	i++;
	k++;
    }
    while (j < n2) {
        A[k] = R[j];
	j++;
	k++;
    }
}

void mergeSort(int A[], int p, int r)
{
    int q;

    if (p < r) {
        q = p + (r - p) / 2;
        
	/* Sort each half */
	mergeSort(A, p, q);
	mergeSort(A, q + 1, r);
	
	/* Merge */
	merge(A, p, q, r);
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
    
    mergeSort(myArr, 0, arrSize - 1);
    
    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}
