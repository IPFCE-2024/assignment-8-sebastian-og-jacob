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
    // Laver ny node der har element som data
    node *n = malloc(sizeof(node));
    n->data = element;
    // Sætter n til at pege på head og gør n til ny head
    n->next = *head;
    *head = n;
}

int pop(node **head) {
    // Pointer til node som skal poppes
    node *n = *head;
    // Returnværdi sættes
    int return_val = n->data;
    // Nyt head delkareres
    *head = n->next;
    // Gamle head slettes
    free(n);
    return return_val;
}

bool emptyStack(node **head){
    return *head == NULL;
}

void initializeStack(stack *s) {
  // Sætter stack til at være tom
  s->head = NULL;
}


void enqueueStack(queue *q, int x) {
    /*Hvis q allerede indeholder et element tilføjes det nye
    element blot til rear. Hvis q er tom sættes element også
    som head*/
    push(x, &q->rear);
    if(empty(q)){
        push(x, &q->front);
    }
    q->size++;
}

int dequeueStack(queue *q) {
    /*Tjekker at q ikke er tom*/
    assert(!empty(q));
    /*Laver stack hvor alle elementer fra rear flyttes over via push
    Herved ændres rækkefølgen på dem.*/
    stack temp_stack;
    initializeStack(&temp_stack);
    while(!emptyStack(&q->rear))
        push(pop(&q->rear), &temp_stack.head);
    
    /*Det første element i temp_stack, må nu være lig det første element
    som tilføjedes til q. Dette sættes derfor til return_val*/
    int return_val = pop(&temp_stack.head);

    /*Hvis temp_stack ikke er tom, flyttes elementerne fra temp_stack
    tilbage til q. Ellers sættes front blot lig NULL*/
    if(!emptyStack(&temp_stack.head)){
        push(pop(&temp_stack.head), &q->rear);
        q->front = q->rear;
        while(!emptyStack(&temp_stack.head)){
            push(pop(&temp_stack.head), &q->rear);
        }
    }
    else{
        q->front = NULL;
    }
    
    q->size--;
    return return_val;
}


/*int main(){
    queue *q;
    initialize(q);
    enqueue(q, 1);
    enqueueStack(q, 2);
    enqueue(q,3);
    enqueueStack(q, 4);
    printf("%d", dequeueStack(q));
    printf("%d", dequeue(q));
    printf("%d", dequeue(q));
    printf("%d", dequeueStack(q));
    enqueue(q, 6);
    enqueueStack(q, 12);
    enqueue(q,2);
    printf("%d", dequeueStack(q));
    printf("%d", dequeue(q));
    printf("%d", dequeueStack(q));
    enqueue(q, -13);
    return 0;
}*/