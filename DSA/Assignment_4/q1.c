#include <stdio.h>
#include <stdlib.h>

int compfun(const void* a, const void* b)
{
    int a1 = *(int*)a;
    int b1 = *(int*)b;

    return (b1 - a1);
    //so if a>b -> it returns a number greater than zero so the first element goes before the second hence decreasing order
}

int main()
{
    int t;
    int n;
    int index = 0;
    int count = 0;
    int max = 0;

    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        count = 0;
        max = 0;
        index = 0;
        scanf("%d",&n);
        long long int A[n];
        //int freq[n];
        //int e[n];

        for(int i=0; i<n;i++)
        {
            scanf("%lld",&A[i]);
            //freq[i] = 0;
        }
        qsort(A,n,sizeof(long long int),compfun);
        
        /*
        for(int i=0; i<n;i++)
        {
            printf("%lld ",A[i]);
        }
        printf("\n");
        */
        /*
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<index;j++)
            {
                if(A[i] == e[j])
                {
                    flag = 0;
                }
            }
            if(flag)
            {
                //the element is not in the e array
                e[index] = A[i];
                index++;
            }
            flag = 1;
        }
        */
        //index--;
        
        //now find the frequency of each element in the original array
        for(int i=0;i<n;i+=0)
        {
            if(A[i] == A[i+1])
            {
                count++;
                i++;
                continue;
            }
            //when it comes out the next element is not the same as the current element so increment count for the last time and increment index
            count++;
            i++;

            if(i == n-1)
            {
                if(A[n-2] == A[n-1])
                {
                    count++;
                }
            }

            if(max < count)
            {
                max = count;
            }
            count = 0;
        }

        count = 0;
        for(int i=0;i<n;i+=0)
        {
            if(A[i] == A[i+1])
            {
                count++;
                i++;
                continue;
            }
            //when it comes out the next element is not the same as the current element so increment count for the last time and increment index
            count++;
            i++;

            if(i == n-1)
            {
                if(A[n-2] == A[n-1])
                {
                    count++;
                }
            }

            if(max == count)
            {
                index++;
            }
            count = 0;
        }

        //now find how many elements has the maximum frequency
        //printf("%d %d\n",max, index);
        if(max == 1)
        {
            printf("%d\n",n);
        }
        else
        {
            int answer;
            answer = n - index;
            answer = answer/(max - 1);
            printf("%d\n",answer - 1);
        }
    }
}