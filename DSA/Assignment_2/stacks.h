#ifndef STACKS_H
#define STACKS_H

#include <stdio.h>
#include <stdlib.h>

typedef long long int type;

typedef struct s{
    struct sr* head;
    struct sr* tail;
    type size;
}stack;

typedef struct sr{
    type data;
    struct sr* next;
}node;

stack* initializestack();
void push(stack* N, type num);
type pop(stack* N);
type top(stack* N);
type isEmpty(stack* N);
type size(stack* N);
void printList(stack* N);

#endif
