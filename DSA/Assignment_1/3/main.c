#include "musicplayer.h"
#include <stdlib.h>
#include <strings.h>

int main()
{
    musicplayer* pl = createMusicPlayer();
    char s[30], n[100], a[100];
    float x;
    int pos;
    scanf("%s",s);

    while(strcasecmp(s,"q") != 0)
    {
        if(strcasecmp(s,"makeSong") == 0)
        {
            scanf(" %s %s %f",n,a,&x);
            song* s1 = makeSong(n,a,x);
        }
        else if(strcasecmp(s,"addSong") == 0)
        {
            //making a song to add
            scanf(" %s %s %f",n,a,&x);
            song* s0 = makeSong(n,a,x);

            int index = addSongToQueue(pl,s0);
        }
        else if(strcasecmp(s,"removeSong") == 0)
        {
            scanf(" %d",&pos);
            int index = removeSongFromQueue(pl,pos);
        }
        else if(strcasecmp(s,"playSong") == 0)
        {
            int index = playSong(pl);
        }
        else if(strcasecmp(s,"current") == 0)
        {
            song* s = getCurrentSong(pl);
            printf("%s\n",s->name);
        }

        scanf("%s",s);
    }
}