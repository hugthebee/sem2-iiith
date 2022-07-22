#include <stdio.h>
#include <stdlib.h>

//heapsort steps:
/* 
1. make a heap with all the elements in the array
2. delete all the elements in the heap
*/

typedef long long int ll;

void swap(ll* a, ll* b)
{
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(ll A[], int index, ll* size) //pass by reference
{
    //min heapify algorithm
    ll left = 2*index + 1; //left child of current element
    ll right = 2*index + 2; //right children of current element

    //NOTE: parent of current element is at (index - 1)/2

    ll small = index; //assuming the parent is the smallest

    if(left < *size /*to check if the current node has a valid left child*/ && A[left] < A[small])
    {
        small = left;
    }
    if(right < *size && A[right] < A[small])
    {
        small = right;
    }

    //now if the current element is not the smallest, we swap
    if(small != index)
    {
        swap(&A[index],&A[small]);

        //now heapify the rest of the sub-tree with the new parent position
        heapify(A,small,size);
    }
}

void heapsorted(ll *size, ll A[*size])
{
    //building a heap first -> the loop only goes till (n-1)/2 because after that all the nodes are leaf nodes and leaf nodes are heaps already
    for(ll i = (*size - 1/ 2) - 1; i>=0 ; i--)
    {
        heapify(A, i, size);
    }

    /*
    for(ll i=0 ; i<(*size - 1) ; i++)
    {
        //swap the first and last element and then heapify from here -> we are essentially just reducing the heap size each time and swapping the first and last elements in the heap each time
        swap(&A[0],&A[i]);
        heapify(A, 0 , &i);
    }
    */
}

void insert(ll *size, ll A[*size], ll element)
{
    //increase size of heap
    *size = *size + 1;
    ll x = *size - 1;
    ll parent, temp;

    //insert the element at the end of heap
    while(x && (element < A[(x-1)/2]))
    {
        A[x] = A[((x-1)/2)];
        x = (x-1)/2;
        /*
        if(A[parent] > A[x])
        {
            temp = A[parent];
            A[x] = temp;
            x = parent;
        }
        */
    }
    A[x] = element;
}

/*
ll delete(ll *size, ll A[*size])
{
    //ll delete = A[*size - 1];  //the last element in array
    //ll delete2 = A[*size - 2];
    //make the first element the last element -> essentially we're deleting the first element in the array
    //A[0] = delete;
    //A[1] = delete2;

    ll delete = A[*size - 1];  //the last element in array
    //make the first element the last element -> essentially we're deleting the first element in the array
    A[0] = delete;
    *size = *size - 1;
    ll x = 0, left, right, small, temp;
    while(x < (*size-1))
    {
        left = 2*x + 1;
        right = 2*x + 2;

        if(A[left] < A[right])
        {
            small = A[left];
        }
        else
        {
            small = A[right];
        }

        if(A[x] > A[small])
        {
            temp = A[small];
            A[small] = A[x];
            A[x] = A[small];
            x = small;
        }
        else
        {
            return small;
        }
    }
}
*/

ll extractMin(ll* size, ll A[*size])
{
    ll min = A[0];
    ll delete = A[*size - 1];  //the last element in array
    //make the first element the last element -> essentially we're deleting the first element in the array
    A[0] = delete;
    *size = *size - 1;
    heapify(A,0,size);

    return min;
}

int main()
{
    ll L, D;
    scanf("%lld %lld",&L, &D);

    ll train[D];
    for(int i=0; i<D;i++)
    {
        scanf("%lld",&train[i]);
    }
    
    ll answer = 0;
    ll sum = 0;
    heapsorted(&D,train);

    /*
    for(int i=0; i<D; i++)
    {
        printf("%lld ",train[i]);
    }
    printf("\n");
    */

    //first heapsort, then add the elements and heapsort again
    while(D > 1)
    {
        sum = extractMin(&D,train);
        sum += extractMin(&D,train);
        answer += sum;
        //now delete the two elements

        //then insert the new sum element
        insert(&D,train,sum);

        /*
        for(int i=0; i<D; i++)
        {
            printf("%lld ",train[i]);
        }
        printf("\n");
        */
       
        sum = 0;
       //printf("%lld\n",answer);
       
      sum = 0;
    }

    printf("%lld\n",answer);
}