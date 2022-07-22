#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "my_dll.h"

my_dll initialize(my_dll list)
{
    list.root = NULL;
    list.size = 0;

    return list;
}

my_dll insert(my_dll list, int data)
{
    node *new = (node *)malloc(sizeof(node));
    assert(new != NULL);

    if (list.root == NULL)
    {
        // first element of the list
        list.root = new;
        new->num = data;
        new->prev = NULL;
        new->next = NULL;
        list.last = new;
        list.size++;
        return list;
    }

    (list.last)->next = new;

    new->num = data;
    new->prev = list.last;
    new->next = NULL;

    list.last = new; // new is now the last node
    list.size++;

    return list;
}

my_dll insert_at(my_dll list, int data, int pos)
{
    // zero-indexed position
    node *new = (node *)malloc(sizeof(node));
    assert(new != NULL);

    if (pos > (list.size - 1))
    {
        printf("The position entered is invalid!\n");
        return list;
    }
    else if (pos == 0)
    {
        // start of the list
        new->next = list.root;
        (list.root)->prev = new;
        list.root = new;

        (list.root)->num = data;
        (list.root)->prev = NULL;
        list.size++;
        return list;
    }
    else if (pos == (list.size - 1))
    {
        // end of list
        new->next = NULL;
        new->prev = list.last;
        (list.last)->next = new;

        list.last = new; // new is now the last node
        new->num = data;
        list.size++;
        return list;
    }

    int i = 0;
    for (node *tempp = list.root; tempp != NULL; tempp = tempp->next)
    {
        if (pos == i)
        {
            new->next = tempp;
            (tempp->prev)->next = new;

            new->num = data;
            new->prev = tempp->prev;

            list.size++;
            return list;
        }
        i++;
    }
}

my_dll delete (my_dll list, int pos)
{
    // reduce list.size
    if (pos > (list.size - 1))
    {
        printf("The position entered is invalid!\n");
        return list;
    }
    else if (pos == 0)
    {
        node *temp;
        temp = (list.root)->next;
        temp->prev = NULL;
        free(list.root);
        list.root = temp;
        list.size--;
        return list;
    }
    else if (pos == (list.size - 1))
    {
        node *temp;
        temp = (list.last)->prev;
        temp->next = NULL;
        free(list.last);
        list.last = temp;
        list.size--;
        return list;
    }

    int i = 0;
    for (node *tempp = list.root; tempp != NULL; tempp = tempp->next)
    {
        if (pos == i)
        {
            (tempp->prev)->next = tempp->next;
            (tempp->next)->prev = tempp->prev;
            free(tempp);
            list.size--;
            return list;
        }
        i++;
    }
}

int find(my_dll list, int data)
{
    int i = 0;
    for (node *tempp = list.root; tempp != NULL; tempp = tempp->next)
    {
        if (tempp->num == data)
        {
            return i;
        }
        i++;
    }

    // if we reach here, means it was not found
    return -1;
}

my_dll prune(my_dll list)
{
    // reduce list.size
    /*
    else if (pos == (list.size - 1))
    {
        node *temp;
        temp = (list.last)->prev;
        temp->next = NULL;
        free(list.last);
        list.last = temp;
        list.size--;
        return;
    }
    */

    int odd=0;
    int i = 0;
    for (node *tempp = list.root; tempp != NULL; tempp = tempp->next)
    {
        if (i == (list.size - 1))
        {
            if (i % 2 != 0)
            {
                node *temp;
                temp = (list.last)->prev;
                temp->next = NULL;
                list.last = temp;
                odd++;
            }
        }
        else if ((i % 2) != 0)
        {
            node* bef = tempp->prev;
            node* after = tempp->next;
            bef->next = tempp->next;
            after->prev = tempp->prev;
            odd++;
        }
        i++;
    }

    list.size = list.size - odd;
    return list;
}

void print(my_dll list)
{
    for (node *tempp = list.root; tempp != NULL; tempp = tempp->next)
    {
        printf("%d\n", tempp->num);
    }
}

void print_reverse(my_dll list)
{
    for (node *tempp = list.last; tempp != NULL; tempp = tempp->prev)
    {
        printf("%d\n", tempp->num);
    }
}

int get_size(my_dll list)
{
    return list.size;
}