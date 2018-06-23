/*
 * Bucket sort
 *
 * Concept: Scatter/gather algo that works by distributing elements of an 
 *          array into buckets
 * Time complexity: Best: Omega(n + k)
 *                  Average: O(n + k)
 *                  Worst: O(n^2)
 * Auxiliary Space: O(n * k)
 * Stable: Yes
 * Method: Distribution
 * Usage: Little usage on its own. However, interesting derived cousins exist
 *        in the form of ProxmapSort, Histogram sort, Postman's soft and 
 *        Shuffle sort
 */

#include <stdio.h>
 
void bucketSort(int A[], int n) {
    int i;
    int j;
    int k;
    int size = n + 1;
    int buckets[size];
    
    for (i = 0; i < size; ++i) {
        buckets[i] = 0;
    }
    
    for (i = 0; i < n; ++i) {
        ++buckets[A[i]];
    }
        
    for (i = 0, j = 0; j < size; ++j) {
        for (k = buckets[j]; k > 0; --k) {
            A[i++] = j;
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

    bucketSort(myArr, arrSize);

    printf("After sorting: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    return 0;
}
