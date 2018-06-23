/*
 * Circular Singly Linked List
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
} Node;
 
Node *addToEmpty(Node *last, int data)
{
    // This function is only for empty list
    if (last != NULL)
      return last;
 
    // Creating a node dynamically.
    Node *temp = 
           (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        perror("malloc failed in addToEmpty.\n");
	exit(EXIT_FAILURE);
    } 
 
    // Assigning the data.
    temp -> data = data;
    last = temp;
 
    // Creating the link.
    last -> next = last;
 
    return last;
}
 
Node *addBegin(Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    Node *temp = 
            (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        perror("malloc failed in addBegin.\n");
	exit(EXIT_FAILURE);
    } 
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
 
    return last;
}
 
Node *addEnd(Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    Node *temp = 
        (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        perror("malloc failed in addEnd.\n");
	exit(EXIT_FAILURE);
    } 
 
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
 
    return last;
}
 
Node *addAfter(Node *last, int data, int item)
{
    if (last == NULL)
        return NULL;
 
    Node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = (Node *)malloc(sizeof(Node));
            if (temp == NULL) {
                perror("malloc failed in addAfter.\n");
	        exit(EXIT_FAILURE);
            } 
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
 
            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);
 
    printf("%dnot present\n", item);
    return last;
 
}
 
void traverse(Node *last)
{
    Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
 
    // Traversing the list.
    do
    {
        printf("%d ", p->data);
        p = p -> next;
 
    }
    while(p != last->next);
 
}
 
int main()
{
    Node *last = NULL;
 
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
 
    traverse(last);
    printf("\n");
 
    return 0;
}

