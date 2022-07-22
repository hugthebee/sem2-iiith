#ifndef DLL_H
#define DLL_H

#include "node.h"

typedef struct structure{
    node* root; //points to the first node
    node* last;
    int size;
    /*
    struct structure* prev;
    struct structure* next;
    int num;
    */
}my_dll;

my_dll initialize(my_dll list); //initializing data in the linked list -> DOESN'T MAKE A NODE THOUGH
my_dll insert(my_dll list, int data);
my_dll insert_at(my_dll list, int data, int pos);
my_dll delete(my_dll list, int pos);
int find(my_dll list, int data); //returns the index at where the data is found - returns -1 if not found (return zero indexed position)
my_dll prune(my_dll list); //delete all nodes at odd indexes
void print(my_dll list); //print from index 0
void print_reverse(my_dll list);
int get_size(my_dll list);


#endif