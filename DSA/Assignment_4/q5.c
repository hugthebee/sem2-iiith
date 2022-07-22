#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

void swap(ll *a, ll *b)
{
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int compfun(const void *a, const void *b)
{
    ll a1 = *(ll *)a;
    ll b1 = *(ll *)b;

    if (a1 > b1)
    {
        return 1;
    }
    else if (a1 < b1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    // so if a>b -> it returns a number greater than zero so the first element goes before the second hence decreasing order
}

void heapify(ll A[], int index, ll *size) // pass by reference
{
    // max heapify algorithm
    ll left = 2 * index + 1;  // left child of current element
    ll right = 2 * index + 2; // right children of current element

    // NOTE: parent of current element is at (index - 1)/2

    ll large = index; // assuming the parent is the largest

    if (left < *size /*to check if the current node has a valid left child*/ && A[left] > A[large])
    {
        large = left;
    }
    if (right < *size && A[right] > A[large])
    {
        large = right;
    }

    // now if the current element is not the largest, we swap
    if (large != index)
    {
        swap(&A[index], &A[large]);

        // now heapify the rest of the sub-tree with the new parent position
        heapify(A, large, size);
    }
}

void heapbuild(ll *size, ll A[*size])
{
    // building a heap first -> the loop only goes till (n-1)/2 because after that all the nodes are leaf nodes and leaf nodes are heaps already
    for (ll i = (*size - 1 / 2) - 1; i >= 0; i--)
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
    // increase size of heap
    *size = *size + 1;
    ll x = *size - 1;

    // insert the element at the end of heap
    while (x && (element > A[(x - 1) / 2]))
    {
        A[x] = A[((x - 1) / 2)];
        x = (x - 1) / 2;
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

void delete (ll *size, ll A[*size])
{
    ll delete = A[*size - 1]; // the last element in array
    // make the first element the last element -> essentially we're deleting the first element in the array
    A[0] = delete;
    *size = *size - 1;
    heapify(A, 0, size);
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int p = 0; p < T; p++)
    {
        ll k;
        scanf("%lld", &k);
        ll r1[k];
        ll r2[k];
        ll ans[k];
        ll sum;

        // scanning the first two rows out of the k rows and then sorting them both
        for (int i = 0; i < k; i++)
        {
            scanf("%lld", &r1[i]);
        }
        qsort(r1, k, sizeof(long long int), compfun);
        for (int i = 0; i < k; i++)
        {
            scanf("%lld", &r2[i]);
        }
        qsort(r2, k, sizeof(long long int), compfun);
        for(int i=0;i<k;i++)
        {
            ans[i] = r1[i] + r2[i];
        }

        heapbuild(&k, ans); // building the answer heap -> max element will now be available at the root
        
        /*
        printf("ans (before insertion): ");
            for (int q = 0; q < k; q++)
            {
                printf("%lld ", ans[q]);
            }
        */

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                sum = r1[i] + r2[j];
                if (sum >= ans[0] /*max element in heap*/)
                {
                    break; // because it is not possible to get a smaller element than this one
                }
                else if(i == j)
                {
                    //already present in the heap so don't insert
                    continue;
                }
                else
                {
                    delete (&k, ans);
                    insert(&k, ans, sum);

                    /*
                    printf("ans (after insertion of %lld from i=%d and j=%d): ",sum,i,j);
                        for (int q = 0; q < k; q++)
                        {
                            printf("%lld ", ans[q]);
                        }
                        printf("\n");
                    */
                }
            }
        }

        /*
        printf("\n========\n");
        printf("r1: "); 
        for (int i = 0; i < k; i++)
        {
            printf("%lld ", r1[i]);
        }
        printf("\n");
        printf("r2: "); 
        for (int i = 0; i < k; i++)
        {
            printf("%lld ", r2[i]);
        }
        printf("\n");
        printf("ans: "); 
        for (int i = 0; i < k; i++)
        {
            printf("%lld ", ans[i]);
        }
        printf("\n");
        printf("========\n");
        */

        // at the end of this we will have a heap with the min sum of the first two rows
        for (int i = 2; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                r1[j] = ans[j];
            }
            qsort(r1, k, sizeof(long long int), compfun);
            for (int j = 0; j < k; j++)
            {
                scanf("%lld", &r2[j]);
                ans[j] = r1[j] + r2[j];
            }
            qsort(r2, k, sizeof(long long int), compfun);
            for (int j = 0; j < k; j++)
            {
                ans[j] = r1[j] + r2[j];
            }
            heapbuild(&k, ans);
            /*
            printf("ans (before insertion): ");
            for (int q = 0; q < k; q++)
            {
                printf("%lld ", ans[q]);
            }
            printf("\n");
            printf("========\n");
            */

            for (int l = 0; l < k; l++)
            {
                for (int j = 0; j < k; j++)
                {
                    sum = r1[l] + r2[j];
                    if (sum >= ans[0] /*max element in heap*/)
                    {
                        break; // because it is not possible to get a smaller element than this one
                    }
                    else if(l == j)
                    {
                        //already present in the heap so don't insert
                        continue;
                    }
                    else
                    {
                        delete (&k, ans);
                        insert(&k, ans, sum);
                        /*
                        printf("ans (after insertion of %lld from i=%d and j=%d): ",sum,i,j);
                        for (int q = 0; q < k; q++)
                        {
                            printf("%lld ", ans[q]);
                        }
                        printf("\n");
                        printf("========\n");
                        */
                    }
                }
            }

            /*
            printf("========\n");
            printf("r1: ");
            for (int q = 0; q < k; q++)
            {
                printf("%lld ", r1[q]);
            }
            printf("\n");
            printf("r2: ");
            for (int q = 0; q < k; q++)
            {
                printf("%lld ", r2[q]);
            }
            printf("final ans: ");
            for (int q = 0; q < k; q++)
            {
                printf("%lld ", ans[q]);
            }
            printf("\n");
            printf("========\n");
            */
            
        }
        qsort(ans,k,sizeof(long long int),compfun);
        for (int i = 0; i < k; i++)
        {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}