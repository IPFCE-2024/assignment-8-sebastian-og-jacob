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

/*Note til instruktore: Havde sgu lidt svært ved både at forstå 
opgaven, samt hvordan de tomme funktioner I havde skrevet skulle 
bruges til at løse den. Men endte med at forstå formuleringen i 
PDF'en sådan, at det måtte være noget med at bruge stack-funktioner
til at opnå 'queue-behavior'. Så vi endte med at skrive enqueueStack
og dequeueStack således at nå de kaldtes på en stack, så ville de give
'queue-behavior': enqueue tilføjer elementer til stack, og dequeue fjerner
det først tilføjede element fra stack. Vi har dog ændret på de tomme funktioner
I skrev op, så det var nok ikke det I tænkte, men ved ikke lige ellers hvordan
vi skulle bruge stacks, samt de funktioner vi skrev i opgave 7 (som der stod vi
kunne gøre i opgaveformuleringen).*/

// Funktion fra sidste uge
stack *initializeStack() {
  stack *s = malloc(sizeof(stack));
  // Sætter stack til at være tom
  s->head = NULL;
  return s;
}

// Funktion fra sidste uge
void push(int x, stack *s) {
  // Laver ny node der har x som data
  node *n = malloc(sizeof(node));
  n->data = x;
  // Nye element peger på gamle head
  n->next = s->head;
  // Nye node bliver sat som head
  s->head = n;
}

// Funktion fra sidste uge
int pop(stack *s) {  
  // Flytter node som skal poppes over i ny node
  node* n = s->head;
  int return_val = n->data;
  // head for stacken bliver sat til forrige element
  s->head = n->next;
  free(n);
  // Returnerer dataen fra den poppede node
  return return_val;
}

// Funktion fra sidste uge
bool emptyStack(stack *s) {
  // Returnerer sand hvis head er NULL
  return s->head == NULL;
}



void enqueueStack(stack *s, int x) {
    /*Tilføjer element til stack*/
    push(x, s);
}

int dequeueStack(stack *s) {
    /*Tjekker at stack ikke er tom*/
    assert(!emptyStack(s));
    int return_val;
    /*Laver midlertidig stack, hvor alle elementer fra stack
    flyttes over for at ændre deres orden*/
    stack *temp_stack = initializeStack();
    while(!(emptyStack(s)))
        push(pop(s), temp_stack);
    /*Popper øverste element fra temp_stack, som må være det
    element som først blev tilføjet til den oprindelige stack*/
    return_val = pop(temp_stack);
    /*Flytter elementer tilbage til den oprindelige stack*/
    while(!emptyStack(temp_stack))
        push(pop(temp_stack), s);
    free(temp_stack);
    return return_val;
}

// Hvis nedenstående main køres tester den, at koden fra opgave 4 virker

/*
int main(){
    stack *s = initializeStack();
    enqueueStack(s, 1);
    enqueueStack(s, 2);
    enqueueStack(s, 3);
    printf("%d", dequeueStack(s));
    printf("%d", dequeueStack(s));
    printf("%d", dequeueStack(s));
    return 0;
}
*/