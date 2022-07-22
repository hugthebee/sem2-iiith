#include "stacks.h"

stack* initializestack()
{
    stack* N = malloc(sizeof(stack));
    N->head = NULL;
    N->tail = NULL;
    N->size = 0;

    return N;
}

void push(stack* N, type num)
{
    node* new = malloc(sizeof(node));

    if(N->tail == NULL)
    {
        //last element in the stack
        N->tail = new;
        N->head = new; //tail will be NULL only if the stack is empty
        N->size++;
        new->data = num;
        new->next = NULL;
    }
    else
    {
        new->next = N->head;
        N->head = new;
        N->size++;
        new->data = num;
    }
}

type pop(stack* N)
{
    type ans=0;

    node* temp = N->head;
    if(temp == NULL)
    {
        return -1;
    }

    ans = temp->data;
    N->head = temp->next;
    free(temp);
    N->size--;

    return ans;
}

type top(stack* N)
{
    return (N->head)->data;
}

type isEmpty(stack* N)
{
    if(N->tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

type size(stack* N)
{
    return N->size;
}

void printList(stack* N)
{
    for(node* temp = N->head;temp != NULL;temp = temp->next)
    {
        printf("%d\n",temp->data);
    }
}
