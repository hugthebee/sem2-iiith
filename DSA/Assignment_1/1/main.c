#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "my_dll.h"

int main()
{
    my_dll list;
    list = initialize(list);

    /*
    printf("Your doubly linked list has been initialized!\n");
    printf("Choose what you'd like to do with your new list: \n");
    printf("Functions: insert, insert_at, find, delete, prune, print, print_reverse, get_size\n");
    printf("Eg: insert 2 (inserts 2 at the end of the list\n");
    printf("Press q to quit\n");
    */

    char s[20];
    int x,pos,result;
    scanf("%s",s);
    while(strcasecmp(s,"q") != 0)
    {
        if(strcasecmp(s,"insert") == 0)
        {
            scanf(" %d",&x);
            list = insert(list, x);
        }
        else if(strcasecmp(s,"insert_at") == 0)
        {
            scanf(" %d %d",&x , &pos);
            list = insert_at(list, x, pos); 
        }
        else if(strcasecmp(s,"delete") == 0)
        {
            scanf(" %d",&pos);
            list = delete(list,pos);
        }
        else if(strcasecmp(s,"find") == 0)
        {
            scanf(" %d",&x);
            result = find(list,x);
        }
        else if(strcasecmp(s,"prune") == 0)
        {
            list = prune(list);
        }
        else if(strcasecmp(s,"print") == 0)
        {
            print(list);
        }
        else if(strcasecmp(s,"print_reverse") == 0)
        {
            print_reverse(list);
        }
        else if(strcasecmp(s,"get_size") == 0)
        {
            result = get_size(list);
        }
        else
        {
            printf("Invalid command :(\n");
        }
        scanf("%s",s);
    }
}