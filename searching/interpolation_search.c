/*
 * Interpolation search
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>
 
int interpolationSearch(int A[], int size, int x)
{
    int position;
    int low = 0;
    int high = (size - 1);
    
    while (low <= high && x >= A[low] && x <= A[high])
    {
        position = low + (((double)(high - low) /
                   (A[high] - A[low])) * (x - A[low]));
        printf("%d\n", position);
        if (A[position] == x) {
            return position;
        }
        if (A[position] < x) {
            low = position + 1;
        }
        else {
            high = position - 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int i;
    int x = 6;
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    int result = interpolationSearch(myArr, arrSize, x);

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

