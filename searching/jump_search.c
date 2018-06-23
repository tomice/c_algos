/*
 * Jump search
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>
#include <math.h>

int min(int a, int b)
{
    return (a <= b) ? a : b;
}

int jumpSearch(int A[], int size, int x)
{
    int prev;
    int step = sqrt(size);
    
    while (A[min(step, size) - 1] < x) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }
    while (A[prev] < x) {
        prev++;
        if (prev == min(step, size)) {
            return -1;
        }
    }
    if (A[prev] == x) {
        return prev;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int i;
    int x = 6;
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    int result = jumpSearch(myArr, arrSize, x);

    printf("Searching for %d\n", x);
    printf("Current array: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    if (result == -1) {
        printf("Element not in array\n");
    }
    else {
        printf("Element at index %d\n", result);
    }
    return 0;
}

