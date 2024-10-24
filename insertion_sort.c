#include "insertion_sort.h"
#include <stdlib.h>
#include <stdio.h>

node* isort(node *list) {
    // Hvis listen er tom returneres null
    if(list == NULL)
        return NULL;

    /*List bliver en liste med et element svarende til lists oprindelige
    første element, og next_element bliver en liste med de resterende 
    elementer der var i list. List vil til sidst være startelement for
    den sortede liste (der sorteres fra mindst til størst)*/
    node *next_element = list->next;
    list->next = NULL;

    /*Der loopes igennem alle elementer i next_element*/
    while(next_element != NULL){
        /*Curelement skal sættes ind i den sortede liste*/
        node *current = next_element;
        next_element = next_element->next;

        /*Hvis current er mindre end det mindste element i list,
        så sættes current til at være det nye mindste element,
        og derfor starten af list */
        if(current->data <= list->data){
            current->next = list;
            list = current;
            continue;
        }

        /*Der loopes igennem alle elementer i den sortede liste (list).*/
        node *list_element = list;
        while(list_element->next != NULL){
            /*Når et element der er større end current nås, så sættes current imellem
            det større element end current og det forrige element*/
            if(current->data <= list_element->next->data){
                current->next = list_element->next;
                list_element->next = current;
                break;
            }
            list_element = list_element->next;
        }
        /*Hvis current har været større end samtlige elementer i den sortede liste,
        så sættes current som det nye forreste element*/
        if(list_element->next == NULL){
            list_element->next = current;
            current->next = NULL;
        }

    }
    
    return list;
}


