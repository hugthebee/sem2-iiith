#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

struct HashTable* init hash table(int a, int b, int countBucket)
{
    struct HashTable* H = (HashTable*) malloc(sizeof(struct HashTable));

    //initializing these values
    H->a = a;
    H->b = b;
    H->countBucket = countBucket;

    H->buckets = (struct Bucket*) malloc(sizeof(struct Bucket) * countBucket); 
    //bucket* array[count]
    //H->buckets = array
    for(int i=0;i<T->countBucket;i++)
    {
        struct Item* temp = malloc(sizeof(struct Item));
        (H->buckets[i]).items = temp;
        temp->frequency = 0;
        temp->next = NULL;
    }
    
    return H;
}

struct HashTable* insert (struct HashTable* T, int key)
{
    int pos;
    pos = ((T->a * key) + T->b) % countBucket;

    struct Item* temp = T->buckets[pos].items;

    if(temp->next == NULL)
    {
        //first element in the linked list
        struct Item* new = malloc(sizeof(struct Item));
        new->frequency++;
        new->key = key;
        new->next = NULL;

        return T;
    }

    //checking if an element with this key already exists -> if so we just increase frequency
    for(struct Item* t=temp; t!=NULL; t=t->next)
    {
        if(t->key == key)
        {
            //it does exist so increase freq
            t->frequency++;
            return T;
        }
    }

    struct Item* new = malloc(sizeof(struct Item));
    new->frequency++;
    new->key = key;
    for(struct Item* t = temp; t!=NULL; t=t->next)
    {
        //iterating through the list and makes next of the last item in the list point to new
        if(t->next == NULL)
        {
            t->next = new;
        }
    }
    new->next = NULL;

    return T;
}

bool search(struct HashTable* T, int key)
{
    int pos;
    pos = ((T->a * key) + T->b) % countBucket;

    struct Item* temp = T->buckets[pos].items;
    for(struct Item* t=temp; t!=NULL; t=t->next)
    {
        if(t->key == key)
        {
            return True;
        }
    }

    return False;
}

struct HashTable* Delete ( struct HashTable* T, int key)
{
    int pos;
    pos = ((T->a * key) + T->b) % countBucket;

    struct Item* temp = T->buckets[pos].items;
    struct Item* prev = temp;

    //check if the current key is already present in the list
    for(struct Item* t=temp; t!=NULL; t=t->next)
    {
        if(t->key == key && t->frequency != 1)
        {
            //it does exist so decrease freq
            t->frequency--;
            return T;
        }
        else if(t->key == key && t->frequency == 1)
        {
            //we have to delete the item node here
            prev->next = t->next;
            free(t);
            return T;
        }
        prev = t;
    }

    return T;
}

void print_table ( struct HashTable* T)
{
    struct Item* temp;
    for(int i=0; i < T->countBucket;i++)
    {
        temp = T->buckets[i].items;
        for(struct Item* t=temp; t!=NULL; t=t->next)
        {
            printf("%d %d ",t->key,t->frequency);
        }
        printf("\n");
    }
}

