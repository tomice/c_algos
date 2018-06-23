/*
 * Hash Table
 *
 * Concept: 
 * Time Complexity: Best:
 *                  Average: 
 *                  Worst: 
 * Auxiliary Space: 
 * Usage: 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

typedef struct dataItem {
   int data;   
   int key;
} DataItem;

DataItem *hashArray[SIZE]; 
DataItem *dummyItem;
DataItem *item;

int hashCode(int key) {
   return key % SIZE;
}

DataItem *search(int key) {
    int hashIndex = hashCode(key);  
    
    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex]; 
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }        
    
    return NULL;        
}

void insert(int key,int data) 
{
    int hashIndex;
    DataItem *item = (DataItem*)malloc(sizeof(DataItem));
    if (item == NULL) {
        perror("malloc failed.\n");
	exit(EXIT_FAILURE);
    } 
    
    item->data = data;  
    item->key = key;
    hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

DataItem* delete(DataItem* item) {
    int key = item->key;
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            DataItem* temp = hashArray[hashIndex]; 
            /*assign a dummy item at deleted position */
            hashArray[hashIndex] = dummyItem; 
         
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }      
    
    return NULL;        
}

void display(void) 
{
    int i;
    
    for (i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) 
{
    dummyItem = (DataItem*)malloc(sizeof(DataItem));
    if (dummyItem == NULL) {
        perror("malloc failed.\n");
	return(EXIT_FAILURE);
    } 
    dummyItem->data = -1;  
    dummyItem->key = -1; 

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    
    printf("Current table:\n");
    display();
    
    printf("Searching for 37...\n");
    item = search(37);

    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }
    
    printf("Deleting 37...\n");
    delete(item);
    printf("Searching for 37...\n");
    item = search(37);

    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }
   
    printf("Current table:\n");
    display();
    
    return 0;
}
