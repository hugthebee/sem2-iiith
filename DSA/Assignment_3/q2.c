#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll powoftwo(ll p)
{
    //works for powers of two
    ll ans = 1L << p;
    return ans;
}

int main()
{
    ll n, t, j;
    j = 0;
    char s[100001];
    ll room, height, level, temp, power, op;
    scanf("%lld %lld",&n, &t);
    ll ans[t];
    for(int i = 0; i<t;i++)
    {
        j = 0;
        scanf("%lld ",&room);
        scanf("%s",s); //scans the string and puts a null character at the end

        while(s[j] != '\0')
        {
            power = 1; //at level = 0
            level = 0;
            temp = room;
            
            while(temp % 2 != 1)
            {
                power *= 2;
                level++;
                temp /= 2;
                //this loop tells us which level our current room is on and the power variable has 2 ^ level value in it
            }
            if(s[j] == 76) //checking for 'L'
            {
                if(room % 2 != 1)
                {
                    //this condition makes sure that we're not at a leaf node

                    //since we're going left we subtract
                    op = powoftwo(level - 1);
                    room = room - op;
                }
            }
            else if(s[j] == 82) //checking for 'R'
            {
                if(room % 2 != 1)
                {
                    //this condition makes sure that we're not at a leaf node

                    //since we're going right we add stuff
                    op = powoftwo(level - 1);
                    room = room + op;
                }
            }
            else
            {
                //we have to go up
                if(room != ((n+1)/2))
                {
                    //this condition makes sure that we're not at the principal root of the tree (can't go up)

                    //while going up, there can be two conditions -> add and go or subtract and go
                    if((temp + 1) % 4 == 0)
                    {
                        //divisible by 4 which means we have to subtract to go up
                        op = powoftwo(level);
                        room = room - op;
                    }
                    else
                    {
                        //not divisible by 4 which means we have to add to go up
                        op = powoftwo(level);
                        room = room + op;
                    }
                }
            }
            j++;
        }
        ans[i] = room;
    }

    //printing output
    for(int i=0; i<t; i++)
    {
        printf("%lld\n",ans[i]);
    }
}