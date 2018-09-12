//
//  PrioQ.h
//  Assignment_1C
//
//
//This Header file is intended to declare all the functions related to the linked list implemented priority queue and the data structure needed to implement this priority queue
//
//  Declared data structure:
//  PrioQ
//
//  Declared function:
//  *PQ_create
//  PQ_insert
//  *PQ_delete
//  PQ_count
//  *PQ_free
//
//
//  Created by Jingran He on 9/7/2018.
//  Copyright © 2018 Jingran He. All rights reserved.
//

#ifndef PrioQ_h
#define PrioQ_h

#include <stdio.h>

#define LEN_Q sizeof(struct PrioQ)
#define LEN_N sizeof(struct Node)


/* Define a data stucture to implement Priority Queue */
typedef struct Node{
    struct Node* next;
    double key;
    void* data;
}Node;

/* Define a data structure called PrioQ */
typedef struct PrioQ{
    /* nodes content */
    struct Node* head;
    struct Node* tail;
    int length;
    
}PrioQ;


/* Create a new priority queue and return a pointer to it */
PrioQ *PQ_create();


/* Insert the item pointed to by data into the priority queue PQ */
int PQ_insert(PrioQ *PQ, double key, void *data);


/* Remove the data item from the priority queue PQ with the smallest key (priority) */
void *PQ_delete(PrioQ *PQ, double *key);


/* Returns the number of items currently residing in the priority queue */
unsigned int PQ_count(PrioQ *PQ);


/* Delete the priority queue PQ by releasing all used memory */
void *PQ_free(struct PrioQ *PQ);

#endif /* PrioQ_h */
