
#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct Song {
    char title[100];
    char artist[100];
    struct Song* next;
    struct Song* prev;
} Song;

Song* addSong(Song* head, const char* title, const char* artist);
Song* deleteSong(Song* head, const char* title);
void displayPlaylist(Song* head);
void playNext(Song** current);
void playPrevious(Song** current);
Song* searchSong(Song* head, const char* title);
void freePlaylist(Song* head);

#endif
