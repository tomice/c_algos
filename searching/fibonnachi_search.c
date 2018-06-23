/*
 * Fibonnachi search
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>

int min(int a, int b)
{
    return (a <= b) ? a : b;
}

int fibonnachiSearch(int A[], int size, int x)
{
    int i;
    int offset = -1;
    int fib1 = 1;
    int fib2 = 0;
    int fib_mth = fib2 + fib1;

    while (fib_mth < size) {
        fib2 = fib1;
        fib1 = fib_mth;
        fib_mth = fib2 + fib1;
    }
    while (fib_mth > 1) {
        i = min(offset + fib2, size - 1);
        if (A[i] < x) {
            fib_mth = fib1;
            fib1 = fib2;
            fib2 = fib_mth - fib1;
            offset = i;
        }
        else if (A[i] > x) {
            fib_mth = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib_mth - fib1;
        }
        else {
            return i;
        }
    }
    if (fib1 && A[offset + 1] == x) {
        return offset + 1;
    }
    
    return -1;
}

int main(int argc, char *argv[])
{
    int i;
    int x = 6;
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    int result = fibonnachiSearch(myArr, arrSize, x);
    
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
