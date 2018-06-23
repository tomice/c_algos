/*
 * Tree Sort
 *
 * Concept: A sorting algorithm that builds a BST from the elements to be 
 *          sorted and traverses them in a way that has each element displayed 
 *          in a sorted order
 * Time complexity: Best: O(n log n)
 *                  Average: O(n log n)
 *                  Worst: O(n log n)
 * Auxiliary Space: O(n)
 * Stable: Yes
 * Method: Insertion
 * Usage: Useful when using a self-balancing binary tree 
 *        i.e. one that keeps its height small during arbitrary insertions 
 *        and deletions
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

void sorted(Node *root)
{
    if (root != NULL) {
        sorted(root->left);
	printf("%d ", root->key);
	sorted(root->right);
    }
}

void insert(Node **node, int key)
{
    if (*node == NULL) { 
        *node = malloc(sizeof(Node));
        if (node == NULL) {
	    perror("Malloc failed.\n");
	    exit(EXIT_FAILURE);
	}
	(*node)->left = NULL;
        (*node)->key = key;
        (*node)->right = NULL;
    }
    else { 
        if (key < (*node)->key) {
            insert(&((*node)->left), key); 
        }
        else {
            insert(&((*node)->right), key); 
        }
    } 
}

int main(int argc, char *argv[])
{
    int i;
    int myArr[] = {5, 2, 4, 6, 1, 3};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    Node *node = NULL;

    printf("Data as entered: ");
    for (i = 0; i < arrSize; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    /* Insert data */
    for (i = 0; i < arrSize; i++) {
        insert(&node, myArr[i]);
    }

    printf("Sorted traversal: ");
    sorted(node);
    
    printf("\n");

    return 0;
 
}
