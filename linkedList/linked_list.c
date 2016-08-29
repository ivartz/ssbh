#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{
    list *a = NULL;

    a=malloc(sizeof(list));

    *a.head = NULL;
    *a.tail = NULL;
    *a.lenght = 0;

    return a;
}

void list_delete(list_t list)
{
    free(list);
}

void list_insert(list_t list, int index, int data)
{

}

void list_append(list_t list, int data)
{   
    node *a = NULL;

    a=malloc(sizeof(node));

    a.prev = list.tail;
    a.next = NULL;
    *a.data=data;

    (*list.tail).next = a;

    list.tail=a;
}

void list_print(list_t list)
{
    node *p;
    p=list.head;

    int i;
    for (i = 0; i < list.length; ++i){
        printf("%i ",p.data);
        p=p.next;
    }
}

long list_sum(list_t list)
{

}

int list_get(list_t list, int index)
{

}

int list_extract(list_t list, int index)
{

}
