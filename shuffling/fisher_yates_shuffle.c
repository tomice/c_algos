/*
 * Fisher Yates Shuffle
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int t = *a;
    
    *a = *b;
    *b = t;
}

void fy_shuffle(int A[], int size)
{
    int i;
    int j;

    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
	swap(&A[i], &A[j]);
    }
}

int main(int argc, char *argv[])
{
    int i;
    int myArr[] = {1, 2, 3, 4, 5, 6};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    
    srand(time(NULL));
    
    printf("Before sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    fy_shuffle(myArr, arrSize);
    
    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}
