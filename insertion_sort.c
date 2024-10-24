#include "insertion_sort.h"
#include <stdlib.h>
#include <stdio.h>

node* isort(node *list) {
    if(list == NULL)
        return NULL;

    node *next_element = list->next;
    list->next = NULL;

    while(next_element != NULL){
        node *current = next_element;
        next_element = next_element->next;
        if(current->data <= list->data){
            current->next = list;
            list = current;
            continue;
        }
        node *list_element = list;
        while(list_element->next != NULL){
            if(current->data <= list_element->next->data){
                current->next = list_element->next;
                list_element->next = current;
                break;
            }
            list_element = list_element->next;
        }
        if(list_element->next == NULL){
            list_element->next = current;
            current->next = NULL;
        }

    }
    
    return list;
}


