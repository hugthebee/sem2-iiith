#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

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

struct HashTable* init_hash_table(int a, int b, int countBucket); // function for initializing a hash table with given parameters.
struct HashTable* insert ( struct HashTable* T, int key) ; // function for inserting new key into hash table .
bool search(struct HashTable* T, int key); // return true if element is present in hash table , otherwise false .
struct HashTable* Delete ( struct HashTable* T, int key) ; //delete given key from the hash table. Do nothing if element is not present inside hash table.
void print_table ( struct HashTable* T) ; // function should print one line for each bucket. A one line bucket outpt looks like : key 1 freq 1 key 2 freq 2 ...... key m freq m

#endif