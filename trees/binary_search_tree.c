/*
 * Self-Balancing Binary Search Tree
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
#include <assert.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        perror("malloc failed\n");
	exit(EXIT_FAILURE);
    } 
    
    tmp->key = data;
    tmp->left = NULL;
    tmp->right = NULL;
    
    return tmp;
}

void inOrderTraversal(Node *root)
{
    if (root != NULL) {
        inOrderTraversal(root->left);
	printf("%d \n", root->key);
        inOrderTraversal(root->right);
    }
}

Node *insert(Node *node, int key)
{
    if (node == NULL) { 
        return newNode(key);
    }
    
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

int main(int argc, char *argv[])
{
    Node *root = NULL;
    /* Tree structure
            50
	   /  \
         30    70
        /  \  /  \
       20  40 60  80
    */
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inOrderTraversal(root);

    return 0;
}
