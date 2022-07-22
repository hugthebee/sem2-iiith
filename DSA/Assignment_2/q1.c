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
        printf("%lld ",temp->data);
    }
}



type gcd(type a, type b)
{
    if (a == 0)
        return b;
    
    return gcd(b % a, a);
}

type lcm(type a, type b)
{
    type ans = a*b;
    ans /= gcd(a,b);

    return ans;
}

void arrayFunction(stack* s1, stack* s2)
{
    int count = 0;
    type a;
    push(s2,top(s1));
    a = pop(s1);
    int size1 = s1->size;

    for(int i = 0; i<size1;i++)
    {
        if(gcd(top(s1),top(s2))>1)
        {
            type ans = lcm(top(s1),top(s2));

            a = pop(s1);
            a = pop(s2);
            push(s2,ans);
            count++;
        }
        else
        {
            push(s2,top(s1));
            a = pop(s1);
        }
    }

    int size = s2->size;

    for(int i=0;i<size;i++)
    {
        push(s1,top(s2));
        a = pop(s2);
    }
    if(count != 0)
    {
        //gcd is found and we call the function again
       return arrayFunction(s1,s2);
    }
    else
    {
        return;
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    type x;

    stack* s1 = initializestack();
    stack* s2 = initializestack();

    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        push(s1,x);
    }

    arrayFunction(s1,s2);

    int size = s1->size;
    type a;


    for(int i=0;i<size;i++)
    {
        push(s2,top(s1));
        a = pop(s1);
    }
    printf("%d\n", size);
    printList(s2);
}
