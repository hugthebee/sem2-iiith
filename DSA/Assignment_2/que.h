#ifndef QUE_H
#define QUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct s{
    struct sr* head;
    struct sr* tail;
    type size;
}que;

typedef struct sr{
    type data;
    struct sr* next;
    struct sr* prev;
}node;

que* initializeque();
type dequeue(que* Q);
void enqueue(que* Q, type num);
type front(que* Q);
type isEmpty(que* Q);
type size(que* Q);
void printQue(que* Q);

#endif