#include "que.h"

que* initializeque()
{
    que* q = malloc(sizeof(que));

    q->size = 0;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void enqueue(que* Q, type num)
{
    node* new = malloc(sizeof(node));

    if(Q->head == NULL)
    {
        //first element in the queue
        Q->head = new;
        Q->tail = new;
        new->data = num;
        new->next = NULL;
        new->prev = NULL;
        Q->size++;
    }
    else
    {
        new->prev = Q->tail;
        (new->prev)->next = new;
        Q->tail = new; //adding to the end of the que
        Q->size++;
        new->data = num;
        new->next = NULL;
    }
}

type dequeue(que* Q)
{
    type ans = 0;

    //remove Q->head
    node* temp = Q->head;
    ans = temp->data;
    Q->head = (Q->head)->next;
    (Q->head)->prev = NULL;
    Q->size--;
    free(temp);

    return ans;
}

type front(que* Q)
{
    return (Q->head)->data;
}

type isEmpty(que* Q)
{
    if(Q->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

type size(que* Q)
{
    return Q->size;
}

void printQue(que* Q)
{
    for(node* temp = Q->head; temp!= NULL; temp = temp->next)
    {
        printf("%d\n",temp->data);
    }
}
