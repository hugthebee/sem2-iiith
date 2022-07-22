#include <stdio.h>

int sortFunction(int n, int H[n], int swapper)
{
    int answer = 0;
    int flag = 0;
    int temp;
    
    //check if the array is already sorted first
    for(int i=0;i<n-1;i++)
    {
        if(H[i] <= H[i+1])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        return answer; //sorted array, so we return minimum answer
    }
    flag = 0;

    for(int i=0; i<n;i++)
    {
        if(H[i] > swapper)
        {
            temp = H[i];
            H[i] = swapper;
            swapper = temp;
            answer++;
        }

        for(int i=0;i<n-1;i++)
        {
            if(H[i] <= H[i+1])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            return answer; //sorted array, so we return minimum answer
        }
        flag = 0;
    }

    //if we still haven't returned it means we can't sort anymore
    return -1;
}
int main()
{
    int answer, swapper;
    int n;

    scanf("%d %d",&n, &swapper);

    int H[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&H[i]);
    }

    answer = sortFunction(n, H, swapper);
    printf("%d\n",answer);
}