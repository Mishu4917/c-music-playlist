
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

Song* createSong(const char* title, const char* artist) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

Song* addSong(Song* head, const char* title, const char* artist) {
    Song* newSong = createSong(title, artist);
    if (head == NULL) {
        return newSong;
    }
    Song* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->prev = temp;
    return head;
}

Song* deleteSong(Song* head, const char* title) {
    Song* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void displayPlaylist(Song* head) {
    Song* temp = head;
    printf("\n🎶 Playlist:\n");
    while (temp != NULL) {
        printf("Title: %s | Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

void playNext(Song** current) {
    if (*current && (*current)->next) {
        *current = (*current)->next;
        printf("▶️ Now playing: %s by %s\n", (*current)->title, (*current)->artist);
    } else {
        printf("⚠️ No next song!\n");
    }
}

void playPrevious(Song** current) {
    if (*current && (*current)->prev) {
        *current = (*current)->prev;
        printf("⏮️ Now playing: %s by %s\n", (*current)->title, (*current)->artist);
    } else {
        printf("⚠️ No previous song!\n");
    }
}

Song* searchSong(Song* head, const char* title) {
    Song* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void freePlaylist(Song* head) {
    Song* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
