//
//  PrioQ.c
//  Assignment_1C
//
//  This file contains the specific implementation of functions declared in PrioQ.h.
//
//  Created by Jingran He on 9/7/2018.
//  Copyright © 2018 Jingran He. All rights reserved.
//

#include "PrioQ.h"
#include <stdlib.h>


/******* Create a new priority queue and return a pointer to it *********/

PrioQ *PQ_create(){
    PrioQ* PQ = NULL;
    PQ = malloc(LEN_Q);
    
    /* If the request fails, malloc returns NULL and print error message to srceen */
    if (PQ == NULL) {
        printf("Error: Failed to allocate memory for Priority Queue\n");
        return NULL;
    }
    else{
        /* initialization */
        PQ->head = NULL;
        PQ->tail = NULL;
        PQ->length = 0;
        return PQ;
    }
}

/******* Create a new priority queue and return a pointer to it *********/


/***** Insert the item pointed to by data into the priority queue PQ ****/

int PQ_insert(PrioQ *PQ, double key, void *data){
    
    Node* p1;           /* the current node position */
    Node* p2;           /* the previous node position */
    
    if (data == NULL) {
        printf("Warning: Data is null\n");
    }
    
    Node* new = malloc(LEN_N);
    
    /* return NULL if the operation failed and print the error message */
    if (new == NULL) {
        printf("Error: Failed to allocate memory for new node\n");
        return 0;
    }
    else{
        new->data = data;
        new->key = key;
        
        /* case 1: insert to an empty priority queue */
        if (PQ->length == 0) {
            new->next = NULL;
            
            /* let the head and tail pointer both point to the new node */
            PQ->head = new;
            PQ->tail = new;
        }
        else{
            p1 = PQ->head;
            p2 = PQ->head;
            /* case 2: insert at the front of the priority queue head */
            if (p1->key > new->key) {
                new->next = p1;
                PQ->head = new;
            }
            else{
                /* find the right place to insert the node according to its priority */
                while (p1->next != NULL && p1->key <= new->key) {
                    p2 = p1;
                    p1 = p1->next;
                }
                /* case 3: insert at the end of the priority queue */
                if (p1->next == NULL) {
                    if (p1->key <= new->key) {
                        new->next = NULL;
                        p1->next = new;
                        PQ->tail = new;
                    }
                    else{
                        new->next = p1;
                        p2->next = new;
                    }
                    
                }
                /* case 4: insert at the middle of the priority queue */
                else{
                    new->next = p1;
                    p2->next = new;
                }
            }
        }
    }
    /* increase the length of priority queue */
    ++PQ->length;
    return 1;
}

/***** Insert the item pointed to by data into the priority queue PQ ****/


/* Remove the data item from the priority queue PQ with the smallest key (priority) */

void *PQ_delete(PrioQ *PQ, double *key){
    
    if (key != NULL) {
        Node* delete = PQ->head;
        void* data;
        
        /* parameter checks */
        if (PQ->head == NULL) {
            printf("This is an empty priority queue. No data to be removed.\n");
            return NULL;
        }
        /* remove the data item from the priority queue with the smallest key, which is the first element */
        else{
            PQ->head = PQ->head->next;
            data = delete->data;
            *key = delete->key;
            /* free the corresponding memory */
            free(delete);
        }
        /* decrease the length of priority queue */
        --PQ->length;
        if (data == NULL) {
            printf("Warning: Data is null\n");
        }
        return data;
    }
    /* parameter checks */
    else{
        printf("Error: The key pointer is NULL. BAD ACCESS.\n");
        return NULL;
    }
}

/* Remove the data item from the priority queue PQ with the smallest key (priority) */


/*** Returns the number of items currently residing in the priority queue ***/
unsigned int PQ_count(PrioQ *PQ){
    
    /* parameter checks */
    if (PQ == NULL) {
        printf("Error: Priority queue pointer equals to NULL.\n");
        return -1;
    }
    return PQ->length;
}


/*** Returns the number of items currently residing in the priority queue ***/


/********* Delete the priority queue PQ by releasing all used memory ********/
void *PQ_free(struct PrioQ *PQ){
    
    /* parameter checks */
    if (PQ == NULL) {
        printf("Error: Priority queue pointer equals to NULL.");
        return NULL;
    }
    Node* p = PQ->head;
    
    /* empty queue */
    if (PQ->length == 0) {
        printf("It's already empty.\n");
        free(PQ);
        return NULL;
    }
    
    /* free the node one by one */
    while (PQ->length != 1) {
        PQ->head = PQ->head->next;
        free(p);
        p = PQ->head;
        --PQ->length;
    }
    
    /* free the last node and the entire priority queue */
    if (PQ->length == 1) {
        free(p);
        free(PQ);
    }
    
    return NULL;
}

/********* Delete the priority queue PQ by releasing all used memory ********/















