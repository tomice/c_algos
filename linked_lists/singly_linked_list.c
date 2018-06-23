/*
 * Singly Linked List
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

/* Creates a basic data structure to make a linked list */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Given a ref to the head of a list, add new node and data at the beginning */
void addToBeginning(Node **head_ref, int data)
{
    Node *new_node = NULL;

    new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc failed in addToBeginning.\n");
	exit(EXIT_FAILURE);
    } 
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Given a ref to the head of a list, add new node and data at the end */
void addToEnd(Node **head_ref, int data)
{
    Node *new_node = NULL;
    Node *last = *head_ref;
    
    new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc failed in addToEnd.\n");
	exit(EXIT_FAILURE);
    } 
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

/* Add a node after when given a pointer to the prev node */
void addAfter(Node *prev_node, int data)
{
    Node *new_node = NULL;

    if (prev_node == NULL) { return; }
    
    new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc failed in addAfter.\n");
	exit(EXIT_FAILURE);
    } 
    
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/* Delete a node when given a specific piece of data to search for */
void deleteNodeGivenData(Node **head_ref, int data)
{
    Node *tmp = *head_ref;
    Node *prev = NULL;
    
    if (tmp != NULL && tmp->data == data) {
        *head_ref = tmp->next;
	free(tmp);
	return;
    }

    while (tmp != NULL && tmp->data != data) {
        prev = tmp;
	tmp = tmp->next;
    }
    
    if (tmp == NULL) { return; }
    
    prev->next = tmp->next;
    free(tmp);
}

/* Delete a node when given a specific position to search for */
void deleteNodeGivenPosition(Node **head_ref, int position)
{
    int i;
    Node *tmp = *head_ref;
    Node *next = NULL;

    if (*head_ref == NULL) { return; }
    
    if (position == 0) {
        *head_ref = tmp->next;
	free(tmp);
	return;
    }

    for (i = 0; tmp != NULL && i < position - 1; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL || tmp->next == NULL) { return; }

    next = tmp->next->next;
    
    free(tmp->next);
    tmp->next = next;
}

/* Given a ref to the head of a list, swap two given nodes */
void swapTwoNodes(Node **head_ref, int x, int y)
{
    if (x == y) { return; }
    
    Node *previousNodeX = NULL;
    Node *currentNodeX = *head_ref;
    Node *previousNodeY = NULL;
    Node *currentNodeY = *head_ref;
    Node *temp = NULL;
    
    while (currentNodeX && currentNodeX->data != x) {
        previousNodeX = currentNodeX;
        currentNodeX = currentNodeX->next;
    }

    while (currentNodeY && currentNodeY->data != y) {
        previousNodeY = currentNodeY;
        currentNodeY = currentNodeY->next;
    }
  
    if (currentNodeX == NULL || currentNodeY == NULL) { return; }
 
    if (previousNodeX != NULL) {
        previousNodeX->next = currentNodeY;
    }
    else {
        *head_ref = currentNodeY;  
    }
 
    if (previousNodeY != NULL) {
        previousNodeY->next = currentNodeX;
    }
    else { 
        *head_ref = currentNodeX;
    }
 
    temp = currentNodeY->next;

    currentNodeY->next = currentNodeX->next;
    currentNodeX->next = temp;
}

/* Prints contents of a linked list starting from a given node */
void printList(Node *n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
	n = n->next;
    }
}

/* Prints the middle node if odd and the second of the two if even */
void printMiddle(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;
 
    if (head != NULL) {
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is:\n %d\n", slow_ptr->data);
    } 
}

/* Reverses a linked list given a reference to the head */
void reverseLinkedList(Node **head_ref) {
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = *head_ref;

    while (current != NULL) {
        next = current->next;
	current->next = prev;
	prev = current;
	current = next;
    }
    *head_ref = prev;
}

int main(int argc, char *argv[])
{
    /* Create three nodes and allocate them to the heap */
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        perror("malloc failed.\n");
	return(EXIT_FAILURE);
    } 
    second = (Node*)malloc(sizeof(Node));
    if (second == NULL) {
        perror("malloc failed.\n");
	return(EXIT_FAILURE);
    } 
    third = (Node*)malloc(sizeof(Node));
    if (third == NULL) {
        perror("malloc failed.\n");
	return(EXIT_FAILURE);
    } 
    
    /* Manually assign data and link it to the next node */
    head->data = 1;
    head->next = second;

    /* Manually assign data and link it to the next node */
    second->data = 2;
    second->next = NULL;

    /* Use function to add a new node to the end */
    addToEnd(&head, 3);

    /* Use function to add a new node to the beginning */
    addToBeginning(&head, 0);

    /* Use function to add after a specific node */
    addAfter(head->next, 6);

    printf("Contents of the linked list:\n");
    printList(head);
    printf("\n");

    printf("Contents of the linked list reversed:\n");
    reverseLinkedList(&head);
    printList(head);
    printf("\n");
    
    printf("Delete the node containing the value 2:\n");
    deleteNodeGivenData(&head, 2);
    printList(head);
    printf("\n");

    printf("Delete position 3 of the list:\n");
    deleteNodeGivenPosition(&head, 3);
    printList(head);
    printf("\n");
    
    printf("Swap 3 and 6:\n");
    swapTwoNodes(&head, 3, 6);
    printList(head);
    printf("\n");

    printMiddle(head);
    
    printf("Adding node to show how printMiddle handles even lists:\n");
    addAfter(head->next, 9);
    printList(head);
    printf("\n");
    
    printMiddle(head);
    
    return 0;
}
