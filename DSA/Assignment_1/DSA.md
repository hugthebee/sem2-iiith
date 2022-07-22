# DSA - Assignment 1

## QUESTION 1

Terminal command -> gcc -o q1.out Q1/main.c Q1/my_dll.c

The user interface allows insertion of an element using 'insert 4'. Using this command causes 4 to be added to the end of the list.
Note that insert also allows the insertion of the first node of the list.

Entering 'q' causes the program to terminate. Otherwise, the user is expected to keep entering commands for the linked list

## QUESTION 2

Terminal command -> gcc -o q2.out -lm Q2/main.c Q2/complex.c -lm

The complex number interface accepts only one command at a time (in capital letters), along with the number of dimensions of the complex number.

The result will either be a float or 'N' dimensional complex number, depending on the function used.

## QUESTION 3
Terminal command -> gcc -o q3.out 3/main.c 3/song.c 3/musicplayer.c

New songs can be added to the music player using 'addSong (song name) (artist name) (duration)'
Then, we can see the current song playing using the command 'current'
The 'removeSongFromQueue' function is zero-indexed in my code

'q' is used to exit the user interface of the music player.




