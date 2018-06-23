/*
 * Doubly Linked List
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

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

/* Given a ref to the head of a list, add new node and data at the beginning */
void addToBeginning(Node** head_ref, int data)
{
    /* 1. allocate node */
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc failed in addToBeginning.\n");
	exit(EXIT_FAILURE);
    } 
 
    /* 2. put in the data  */
    new_node->data  = data;
 
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    /* 5. move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Given a node as prev_node, insert a new node after the given node */
void addAfter(Node* prev_node, int data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    /* 2. allocate new node */
    Node* new_node =(Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc failed in addAfter.\n");
	exit(EXIT_FAILURE);
    } 
 
    /* 3. put in the data  */
    new_node->data  = data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;
 
    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;
 
    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
      new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, addToEnds a new node at the end  */
void addToEnd(Node** head_ref, int data)
{
    /* 1. allocate node */
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc failed in addToEnd.\n");
	exit(EXIT_FAILURE);
    } 
 
    Node *last = *head_ref;  /* used in step 5*/
 
    /* 2. put in the data  */
    new_node->data  = data;
 
    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
 
    /* 7. Make last node as previous of new node */
    new_node->prev = last;
 
    return;
}

void printList(Node *node)
{
    Node *last;
    printf("Traversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    /* Start with the empty list */
    Node *head = NULL;
 
    // Insert 6.  So linked list becomes 6->NULL
    addToEnd(&head, 6);
 
    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    addToBeginning(&head, 7);
 
    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    addToBeginning(&head, 1);
 
    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    addToEnd(&head, 4);
 
    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    addAfter(head->next, 8);
 
    printList(head);
 
    return 0;
}
