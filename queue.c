#include "queue.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


// Opgave 3
void initialize(queue *q) {
    /*queue gøres tom, og dens længde sættes lig 0*/
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(const queue *q) {
    /*Hvis size er 0, må queue være tom*/
    if(q->size == 0){
        return true;
    }
    return false;
}

bool full(const queue *q) {
    /*En queue baseret på singly linked list kan 
    aldig være fuld.*/
    return false;
}

void enqueue(queue *q, int x) {
    /*Det nye element som skal tilføjes til queue kaldes n*/
    node *n = malloc(sizeof(node));
    n->data = x;
    /*Hvis queue er tom, sættes front og rear begge til n*/
    if(empty(q)){
        n->next = NULL;
        q->front = n;
        q->rear = n;
    }
    /*Hvis queue kun indeholder 1 element sættes n til at pege
    på front og rear sættes til n*/
    else if(q->size == 1){
        n->next = q->front;
        q->rear = n;
    }
    else{
        /*n sættes bagest i queue og rear sættes til n*/
        n->next = q->rear;
        q->rear = n;
    }
    /*størrelsen af q forøges med 1*/
    q->size++; 
}

int dequeue(queue *q) {
    /*q må ikke være tom, da vi da ikke kan returnere nogen int*/
    assert(!empty(q));
    /*Værdien for front må skulle returneres*/
    int return_val = q->front->data;
    
    /*Hvis q kun indeholder 1 element, gøres q tom*/
    if(q->size == 1){
        initialize(q);
    }
    else{
        node *cur_node = q->rear;
        /*Kører loop indtil at cur_node er elementet før front*/
        for(int i = 2; i < q->size; i++){
            cur_node = cur_node->next;
        }
        /*Front frigøres, da den skal 'poppes'*/
        free(q->front);
        /*cur_node sættes som ny front, da den var element lige før
        front. Cur_node sættes nu til at pege på NULL*/
        q->front = cur_node;
        cur_node->next = NULL;
        q->size--;
    }
    return return_val;
}

// Opgave 4
void push(int element, node **head) {

}

int pop(node **head) {
    return -1;
}

void enqueueStack(queue *q, int x) {

}

int dequeueStack(queue *q) {
    return -1;
}


    return 0;
}*/