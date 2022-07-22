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

deque* initializedeque()
{
    deque* Q = malloc(sizeof(deque));

    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;

    return Q;
}

void pushBack(deque* Q, type num)
{
    node* new = malloc(sizeof(node));

    if(Q->head == NULL)
    {
        //first node of the list
        Q->head = new;
        Q->tail = new;
        new->next = NULL;
        new->prev = NULL;
        new->data = num;
        Q->size++;
    }
    else
    {
        new->prev = Q->tail;
        (Q->tail)->next = new;
        new->next = NULL;
        Q->tail = new;
        new->data = num;
        Q->size++;
    }
}

void pushFront(deque* Q, type num)
{
    node* new = malloc(sizeof(node));

    if(Q->head == NULL)
    {
        //first node of the list
        Q->head = new;
        Q->tail = new;
        new->next = NULL;
        new->prev = NULL;
        new->data = num;
        Q->size++;
    }
    else
    {
        new->prev = NULL;
        (Q->head)->prev = new;
        new->next = Q->head;
        Q->head = new;
        new->data = num;
        Q->size++;
    }
}

type popFront(deque* Q)
{
    type ans;
    //remove Q->head

    if(Q->size == 1)
    {
        //popping the first element
        node* temp = Q->head;
        ans = temp->data;
        free(temp);
        Q->tail = NULL;
        Q->head = NULL;
        Q->size--;

        return ans;
    }

    node* temp = Q->head;
    ans = temp->data;
    Q->head = temp->next;
    free(temp);
    (Q->head)->prev = NULL;
    Q->size--;

    return ans;
}

type popBack(deque* Q)
{
    type ans;
    //remove Q->tail

    if(Q->size == 1)
    {
        //popping the last element
        node* temp = Q->tail;
        ans = temp->data;
        free(temp);
        Q->tail = NULL;
        Q->head = NULL;
        Q->size--;

        return ans;
    }

    node* temp = Q->tail;
    ans = temp->data;
    Q->tail = temp->prev;
    free(temp);
    (Q->tail)->next = NULL;
    Q->size--;

    return ans;
}

type front(deque* Q)
{
    return (Q->head)->data;
}

type back(deque* Q)
{
    return (Q->tail)->data;
}

type isEmpty(deque* Q)
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

type size(deque* Q)
{
    return Q->size;
}

void printDeque(deque* Q)
{
    for(node* temp = Q->head; temp!= NULL ; temp = temp->next)
    {
        printf("%d\n",temp->data);
    }
}


int main()
{
    int N, M, x, min;
    scanf("%d %d", &N, &M);
    int arr[N];

    deque* q = initializedeque();
    for(int i = 0; i<N;i++)
    {
        scanf("%d",&arr[i]);
    }

    //printDeque(q);
    //printf("===\n");

    int i;
    //first window is considered
    for(i=0; i<M; i++)
    {
        while(!isEmpty(q) && arr[i] <= arr[back(q)])
        {
            x = popBack(q);
        }
        pushBack(q,i);
    }

    //now we consider a shifted window

    for(i = M; i < N; i++)
    {
        printf("%d ",arr[front(q)]);

        while(!isEmpty(q) && front(q) <= (i-M))
        {
            x = popFront(q);
        }

        while(!isEmpty(q) && arr[i] <= arr[back(q)])
        {
            x = popBack(q);
        }

        pushBack(q,i);
    }

    //printing the maximum element of the last window
    printf("%d ",arr[front(q)]);
}