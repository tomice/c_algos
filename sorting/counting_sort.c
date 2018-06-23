/*
 * Counting sort
 *
 * Concept: Counts the number of objects that have distinct key values, uses 
 *          math to determine the positions of each key value and outputs 
 *          the sequence
 * Time complexity: Best: O(n + k)
 *                  Average: O(n + k)
 *                  Worst: O(n + k)
 * Auxiliary Space: O(n + k)
 * Stable: Yes
 * Method: Non-comparison sort
 * Usage: Suitable for direct use situations where variations of keys are not
 *        significantly greater than the number of items. Used as a subroutine
 *        in a more interesting algorithm that handles larger keys - Radix sort
 */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void countingSort(int A[], int n)
{
    int i;
    int j;
    int outIdx;
    const int max = 65536;
    int *count = (int*)calloc(max, sizeof(*count));
    if (count == NULL) {
        perror("Calloc failed.\n");
	exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        count[A[i]]++;
    }
    
    for (i = 0; i < max; i++) {
        for (j = 0; j < count[i]; j++) {
	    A[outIdx++] = i;
	}
    } 
    free(count);
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

    countingSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}

