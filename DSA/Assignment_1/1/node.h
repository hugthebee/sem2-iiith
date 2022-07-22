#ifndef NODE_H
#define NODE_H

typedef struct Node{
    int num;
    struct Node* next;
    struct Node* prev;
}node;

#endif