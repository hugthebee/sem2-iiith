#include "musicplayer.h"
#include <stdlib.h>

musicplayer* createMusicPlayer()
{
    musicplayer* playlist = malloc(sizeof(musicplayer));
    playlist->que = NULL; //no song yet
    playlist->size = 0;
}

int addSongToQueue(musicplayer* mp, song* s)
{
    if(mp->que == NULL)
    {
        //adding the first song to the queue
        mp->que = s;
        s->next = NULL;
        mp->last = s;
        mp->size++;
        return 0;
    }
    else
    {
        (mp->last)->next = s;
        mp->last = s;
        s->next = NULL;
        mp->size++;
        return 0;
    }

    return 1;
}

int removeSongFromQueue(musicplayer* mp, int pos) //zero-indexed
{
    int i=0;
    if(pos == 0)
    {
        mp->que = (mp->que)->next;
        mp->size--;
        return 0;
    }

    song* prev = NULL;
    for(song* temp = mp->que;temp != NULL;temp = temp->next)
    {
        if(i==pos)
        {
            //delete the song
            prev->next = temp->next;
            free(temp);
            return 0;
        }
        prev = temp;
    }

    return 1;
}

int playSong(musicplayer* mp)
{
    //remove current song from the queue
    removeSongFromQueue(mp,0); //always at position zero because I add the new songs to the end of the list
    return 0;
}

song* getCurrentSong(musicplayer* mp)
{
    return mp->que;
}