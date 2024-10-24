#include "queue.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


// Opgave 3
void initialize(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(const queue *q) {
    if(q->size == 0){
        return true;
    }
    return false;
}

bool full(const queue *q) {
    return false;
}

void enqueue(queue *q, int x) {
    q->size++;
    node *n = malloc(sizeof(node));
    n->data = x;
    if(q->front == NULL){
        n->next = NULL;
        q->front = n;
        q->rear = n;
    }
    else if(q->front == q->rear){
        n->next = q->front;
        q->rear = n;
    }
    else{
        n->next = q->rear;
        q->rear = n;
    }
}

int dequeue(queue *q) {
    assert(!empty(q));
    int return_val = q->front->data;
    if(q->front == q->rear){
        return_val = q->front->data;
        q->front = NULL;
        q->rear = NULL;
    }
    else{
        node *cur_node = q->rear;
        for(int i = 2; i < q->size; i++){
            cur_node = cur_node->next;
        }
        return_val = q->front->data;
        free(q->front);
        q->front = cur_node;
        cur_node->next = NULL;
    }
    q->size--;
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

/*int main(){
    queue q;
    initialize(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 5);
    enqueue(&q, 8);
    printf("%d", dequeue(&q));
    printf("%d", dequeue(&q));
    printf("%d", dequeue(&q));
    printf("%d", dequeue(&q));

    return 0;
}*/