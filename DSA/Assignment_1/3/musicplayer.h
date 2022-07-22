#include <stdio.h>
#include "song.h"

typedef struct st{
    char current[100];
    song* que; //points to the queue of songs to be played 
    song* last;
    int size;
}musicplayer;

musicplayer* createMusicPlayer();
int addSongToQueue(musicplayer* mp, song* s);
int removeSongFromQueue(musicplayer* mp, int pos); //zero-indexed
int playSong(musicplayer* mp);
song* getCurrentSong(musicplayer* mp);
