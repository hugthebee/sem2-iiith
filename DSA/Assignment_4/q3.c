#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int compfun(const void* a, const void* b)
{
    ll a1 = *(ll*)a;
    ll b1 = *(ll*)b;

    if(a1 > b1)
    {
        return 1;
    }
    else if(a1 < b1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    //so if a>b -> it returns a number greater than zero so the first element goes before the second hence decreasing order
}

int main()
{
    ll n,k;
    scanf("%lld %lld",&n,&k);

    ll answer;
    ll A[n];
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&A[i]);
        sum+=A[i];
    }

    ll ans[n];
    ans[0] = sum;
    for(int i=1;i<n;i++)
    {
        ans[i] = ans[i-1] - A[i-1];
    }

    answer = ans[0];
    ll sort[n-1];
    for(int i=0;i<(n-1);i++)
    {
        sort[i] = ans[i+1];
    }
    qsort(sort,n-1,sizeof(long long int),compfun);
    /*
    for(int i=0;i<(n-1);i++)
    {
       printf("%lld ",sort[i]);
    }
    printf("\n");
    */

    k--;
    for(int i=0;i<k;i++)
    {
        answer+=sort[n-2-i];
    }

    printf("%lld\n",answer);
}