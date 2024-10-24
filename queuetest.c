#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

int main() {

    // Tester om initialiseret liste er tom
    queue q;
    initialize(&q);
    assert(empty(&q));

    /*Tester om elementer bliver queuet og dequeuet i rigtig
    rækkefølge, og om listen er ens før og efter elementer bliver
    queuet og dequeuet*/
    int x0, y0, x1, y1;
    x0 = 5;
    x0 = 37;
    enqueue(&q, x0);
    enqueue(&q, x1);
    y0 = dequeue(&q);
    y1 = dequeue(&q);
    assert(x0 == y0 && x1 == y1);
    assert(empty(&q));

    // Hvis ingen assertions er kaldt er testene passed
    printf("tests passed!");
}