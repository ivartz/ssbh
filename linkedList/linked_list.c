#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{
    list_t a = NULL;

    a=malloc(sizeof(struct list));

    a->head = NULL;
    a->tail = NULL;
    a->length = 0;

    return a;
}

void list_delete(list_t list)
{
    free(list);
}

void list_insert(list_t list, int index, int data)
{   
    node_t a = NULL;

    a=malloc(sizeof(struct node));

    a->data=data;

    node_t p;
    p=list->head;

    if(list->length ==0){
        list->head = a;
        list->tail = a;
        a->next=NULL;
        list->length++;
        return;
    }

    if(index == list->length){
        a->prev = list->tail;
        a->next = NULL;
        a->data=data;
        list->tail->next = a;
        list->tail=a;
        list->length++;
        return;
    }

    int i;
    for (i = 1; i < list->length; ++i){
        if(i == index+1){
            p->prev->next = a;
            a->next = p;
            a->prev = p->prev;
            p->prev =a;
            list->length++;
            return; 
        }
        p=p->next;
    }

    printf("Insert failed \n");
}

void list_append(list_t list, int data)
{   
    node_t a = NULL;

    a=malloc(sizeof(struct node));


    if(list->length==0){
        a->prev = NULL;
        a->next = NULL;
        a->data=data;
        list->tail = a;
        list->head=a;
        list->length++;
        return;
    }

    a->prev = list->tail;
    a->next = NULL;
    a->data=data;
    list->tail->next = a;
    list->tail=a;
    list->length++;
}

void list_print(list_t list)
{
    node_t p;
    p=list->head;

    int i;
    for (i = 0; i < list->length; ++i){
        printf("%i ",p->data);
        p=p->next;
    }
    printf("\n");
}

long list_sum(list_t list)
{
    long sum;
    sum = 0;
    node_t p;
    p=list->head;

    int i;
    for (i = 0; i < list->length; ++i){
        sum += p->data;
        p=p->next;
    }

    return sum;
}

int list_get(list_t list, int index)
{
    node_t p;
    p=list->head;

    int i;
    for (i = 0; i < list->length; ++i){
        if (i == index){
            return p->data;
        }
        p=p->next;
    }

    return -1;
}

int list_extract(list_t list, int index)
{

    node_t p;
    p = list->head;
    int extracted;

    if(list->length == 1){
        extracted = p->data;
        list->head=NULL;
        list->tail=NULL;
        free(p);
        list->length--;
        return extracted;
    }

    if(index == 0){
        extracted = p->data;
        list->head = p->next;
        p->next->prev = NULL;
        free(p);
        list->length--;
        return extracted;
    }

    if(index == list->length){
        extracted = p->data;
        p->prev->next = NULL;
        list->tail = p->prev;
        free(p);
        list->length--;
        return extracted;     
    }

    int i;
    
    for (i = 0; i < list->length; ++i){

        if(i == index){
            //printf("%i \n");

            if(p->prev == NULL){
            printf("oisfdhgoidshg \n");    
            }
            
            extracted = p->data;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            list->length--; 
            return extracted;
        }
        p=p->next;
    }
    return -1;

}
