#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int type;

typedef struct s{
    struct sr* head;
    struct sr* tail;
    type size;
}deque;

typedef struct sr{
    type data;
    struct sr* next;
    struct sr* prev;
}node;

deque* initializedeque();
type popFront(deque* Q);
type popBack(deque* Q);
void pushFront(deque* Q, type num);
void pushBack(deque* Q, type num);
type front(deque* Q);
type back(deque* Q);
type isEmpty(deque* Q);
type size(deque* Q);
void printDeque(deque* Q);

#endif