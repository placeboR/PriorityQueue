//
//  main.c
//  Assignment_1C
//
//  This file contains the test of priority queue implemented with the PrioQ.
//
//  Created by Jingran He on 9/7/2018.
//  Copyright © 2018 Jingran He. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PrioQ.h"

#define PQ_TEST_LEN 20

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));                              /* seed the random function */
    
    /*************** variable declaration ****************/
    
    int data[PQ_TEST_LEN];                          /* 20 data element */
    double* key = malloc(sizeof(double));           /* to save the key of removed item */
    
    /*************** variable declaration ****************/

    
    /********* create priority queue and check ***********/
    
    PrioQ* PQ = PQ_create();
    if (PQ == NULL) {
        return 1;
    }
    
    /********* create priority queue and check ***********/

    
    /************* create 20 data element ****************/
    
    for (int i = 0; i<PQ_TEST_LEN; ++i) {
        data[i] = i+1;
    }

    /************* create 20 data element ****************/

    
    /* assign the data with random priority and insert into the queue */
    
    for (int i = 0; i<PQ_TEST_LEN; ++i) {
        
        /* check if it successfully allocate memory for new node */
        if(!PQ_insert(PQ, (rand()/(double)RAND_MAX*10), &data[i]))  /* random double key value from 0 to 10 */
            return 1;
    }
    /* assign the data with random priority and insert into the queue */

    /************* remove the elements *******************/
    
    /* stop when the key pointer is null or data pointer is null or priority queue is empty */
    while (PQ_delete(PQ, key) != NULL) {
        
        printf("Remove the node with key %4.1f\n",(*key));
    }
    
    /************* remove the elements *******************/

    PQ_free(PQ);
    
    return 0;
}
