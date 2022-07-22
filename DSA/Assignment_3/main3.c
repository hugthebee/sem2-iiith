#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Item
{ 
    int key;
    int frequency;
    struct Item* next ;
};

struct Bucket
{
    struct Item* items; 
};

struct HashTable 
{
    int a, b, countBucket;
    struct Bucket* buckets;
    // countBucket = number of buckets
    // hash function will be : (a∗key+b)%countBucket struct Bucket ∗ buckets ;
};

struct HashTable* init_hash_table(int a, int b, int countBucket)
{
    struct HashTable* H = (struct HashTable*) malloc(sizeof(struct HashTable));

    //initializing these values
    H->a = a;
    H->b = b;
    H->countBucket = countBucket;

    H->buckets = (struct Bucket*) malloc(sizeof(struct Bucket) * countBucket); 
    //bucket* array[count]
    //H->buckets = array
    for(int i=0;i<H->countBucket;i++)
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
    pos = ((T->a * key) + T->b) % T->countBucket;

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
    pos = ((T->a * key) + T->b) % T->countBucket;

    struct Item* temp = T->buckets[pos].items;
    for(struct Item* t=temp; t!=NULL; t=t->next)
    {
        if(t->key == key)
        {
            return true;
        }
    }

    return false;
}

struct HashTable* Delete ( struct HashTable* T, int key)
{
    int pos;
    pos = ((T->a * key) + T->b) % T->countBucket;

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



int main()
{
    int a = 98, b = 45, count = 20;
    struct HashTable* H = init_hash_table(a,b,count);

    int insertcount = 0, insertoperations = 0, searchcount = 0, searchoperations = 0;
    int num;
    char op[15];

    while(1)
    {
        scanf("%s",op);
        if(strcmp(op,"QUIT") == 0)
        {
            break;
        }

        scanf("%d",&num);
        if(strcmp(op,"INSERT") == 0)
        {
            H = insert(H,num);
            insertcount++;
        }
        else if(strcmp(op,"SEARCH") == 0)
        {
            bool ans = search(H, num);
            if(ans == true)
            {
                printf("Found\n");
            }
            else
            {
                printf("Not found\n");
            }
            searchcount++;
        }
    }
}