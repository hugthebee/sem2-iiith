#include "song.h"
#include <stdlib.h>

song* makeSong(char* title, char* art, float dur)
{
    song* s = malloc(sizeof(song));

    s->name = title;
    s->artist = art;
    s->duration = dur;
    s->next = NULL;

    return s;
}

