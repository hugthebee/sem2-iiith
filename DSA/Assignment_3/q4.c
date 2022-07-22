#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in=0;

typedef struct n
{
    char data;
    int repeat;
    struct n* right;
    struct n* left;
}node;

void findPreorder(node* tree, char* preorder)
{
    if(tree == NULL)
    {
        return;
    }
    
    preorder[in] = tree->data;
    in++;

    //traverse left subtree
    findPreorder(tree->left, preorder);

    //traverse right subtree
    findPreorder(tree->right, preorder);
}

int main()
{
    int n, a ,b ,c, Q;
    scanf("%d",&n);
    char s[n + 1];
    node** tree = malloc(sizeof(node *) * n);

    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        //reading input and allocating to the node
        node* new = malloc(sizeof(node));
        tree[i] = new; 
        new->data = s[i];
        new->right = NULL;
        new->left = NULL;
        new->repeat = 0;
    }

    for(int i=0; i<(n-1);i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(c==1)
        {
            tree[a - 1]->left = tree[b - 1];
        }
        else if(c==2)
        {
            tree[a - 1]->right = tree[b - 1];
        }
    }

    char preorder[n];
    findPreorder(tree[0],preorder);

    /*
    for(int i=0;i<n;i++)
    {
        printf("%c",preorder[i]);
    }
    printf("\n");
    */

    //making the index array so that the preorder chars indexes in the original array are stored
    int index[n];
    for(int i=0; i<n;i++)
    {
        char c = preorder[i];
        for(int j=0;j<n;j++)
        {
            if(tree[j]->data == c && tree[j]->repeat!=1)
            {
                index[i] = j;
                tree[j]->repeat = 1;
                goto label;
            }
        }
        label: ;
    }

    char string[1000001];
    scanf("%s",string);
    scanf("%d",&Q);
    int T,I,L,R,ai=0;
    char C;
    int ans[Q];

    for(int i=0;i<Q;i++)
    {
        scanf("%d",&T);
        if(T==1)
        {
            //query 1
            scanf("%d %c",&I,&C);
            //go to index array and check where it is equal to I, then go to that index of preorder array and change there
            int pos;
            for(int i=0;i<n;i++)
            {
                if(index[i] == I - 1)
                {
                    pos = i;
                    preorder[pos] = C;
                    break;
                }
            }
        }
        else if(T==2)
        {
            //query 2
            scanf("%d %d %d",&L,&R,&I);
            //printf("index:%d  string:%d  len:%d  substring:%s  preorder:%s\n",index[L-1], L-1, R-L+1, &string[L - 1], &preorder[index[L-1]]);

            if(strncmp(&preorder[index[L-1]],&string[L - 1],R-L+1) == 0)
            {
                ans[ai] = 1; //YES
                ai++;
            }
            else
            {
                ans[ai] = 0; //NO
                ai++;
            }
        }
    }

    for(int i=0;i<ai;i++)
    {
        if(ans[i] == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}