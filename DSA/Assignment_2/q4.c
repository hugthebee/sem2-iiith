#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("%d\n",temp->data);
    }
}

long long int maxArea(long long int M, long long int A[M])
{
    stack* s = initializestack();

    type x, max, width, area, i;
    max = 0;

    for(i=0;i<M;i++)
    {
        if(isEmpty(s) || (A[i] >= A[top(s)]))
        {
            push(s,i);
        }
        else
        {
            while (A[i] < A[top(s)] && s->size != 1)
            {
                x = pop(s);
                width = i - top(s) - 1;
                area = A[x] * width;

                if(max <= area)
                {
                    max = area;
                }
            }
            push(s,i);
        }
    }

    //if the stack is not empty yet, we pop and calculate the maximum area
    while(isEmpty(s) == 0 && s->size != 1)
    {
        x = pop(s);
        width = i - top(s) - 1;
        area = A[x] * width;

        if(max <= area)
        {
            max = area;
        }
    }

    return max;
}

int main()
{
    long long int N,M, areaMax, temp;
    areaMax = 0;
    scanf("%lld %lld",&N, &M);
    char c[M+1]; //terminating character too

    long long int A[N][M];
    for(int i=0; i<N ;i++)
    {
        scanf("%s",c);
        for(int j=0; j<M; j++)
        {
            if((int)c[j] == 42)
            {
                A[i][j] = 0; //there will be a tree here
            }
            else
            {
                A[i][j] = 1;
            }
        }
    }

    //now we create a 1D array of size M that essentially represents a histogram
    long long int arr[M];
    for(int i=0; i<M; i++)
    {
        arr[i] = A[0][i]; //copying the first row into our histogram array
    }
    temp = maxArea(M,arr);
    if(temp >= areaMax)
    {
        areaMax = temp;
    }

    //adding the other rows of the 2D matrix
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(A[i][j] != 0)
            {
                arr[j] += A[i][j]; 
            }
            else
            {
                arr[j] = 0;
            }
        }
        temp = maxArea(M,arr);
        if(temp >= areaMax)
        {
            areaMax = temp;
        }
    }
    printf("%lld\n",areaMax);
}