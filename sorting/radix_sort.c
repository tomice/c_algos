/*
 * Radix Sort
 * 
 * Concept: A non-comparative integer sort that stores data with integer keys
 *          by grouping keys by the individual digits that share the same
 *          significant position and value
 * Time Complexity: Best: N/A
 *                  Average: O(n * (k/d))
 *                  Worst: O(n * (k/d))
 * Auxiliary Space: O(n + 2^d)
 * Stable: Yes
 * Method: Non-comparison sort
 * Uses: When there's a large set of data with keys that are constrained 
 *       in some way
 */ 

#include <stdio.h>

void radixSort(int A[], int n)
{
    int i; 
    int j; 
    int e;
    int m = A[0];
    int output[n];
    int count[10] = {0};
    
    /* Fix max val in array */
    for (i = 1; i < n; i++) {
        if (A[i] > m) {
	    m = A[i];
	}
    }

    /* Perform count sort for every digit */
    for (e = 1; m / e > 0; e *= 10) {

        /* Store occurrences */
        for (j = 0; j < n; j++) {
            count[(A[j] / e) % 10]++;
        }
        
	/* Move position so count contains the position of the digit */
        for (j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        
	/* Rebuild */
        for (j = n - 1; j >= 0; j--) {
            output[count[(A[j] / e) % 10 ] - 1] = A[j];
	    count[(A[j] / e) % 10]--;
        }

	/* Copy output array to old array */
        for (j = 0; j < n; j++) {
            A[j] = output[j];
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

   radixSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}

