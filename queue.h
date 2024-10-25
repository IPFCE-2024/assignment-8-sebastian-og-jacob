#pragma once

#include <stdbool.h>

#include "node.h"
 
typedef struct queue {
  int size;
  node *front;
  node *rear;
} queue;

typedef struct {
  node *head;
} stack;

void initialize(queue *q);
bool empty(const queue *q);
bool full(const queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void push(int x, stack *s);
int pop(stack *s);
void enqueueStack(stack *s, int x);
int dequeueStack(stack *s);
