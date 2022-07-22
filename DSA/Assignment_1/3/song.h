#include <stdio.h>

typedef struct s{
    char* name;
    char* artist;
    float duration;
    struct s* next;
}song;

song* makeSong(char* title, char* art, float dur);