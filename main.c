
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main() {
    Song* playlist = NULL;
    Song* current = NULL;
    int choice;
    char title[100], artist[100];

    while (1) {
        printf("\n🎵🎵 C Music Playlist Manager 🎵🎵\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Next\n");
        printf("5. Play Previous\n");
        printf("6. Search Song\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                printf("Enter artist name: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = 0;
                playlist = addSong(playlist, title, artist);
                if (current == NULL) current = playlist;
                break;
            case 2:
                printf("Enter title to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                playlist = deleteSong(playlist, title);
                break;
            case 3:
                displayPlaylist(playlist);
                break;
            case 4:
                playNext(&current);
                break;
            case 5:
                playPrevious(&current);
                break;
            case 6:
                printf("Enter title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                Song* found = searchSong(playlist, title);
                if (found) {
                    printf("✅ Found: %s by %s\n", found->title, found->artist);
                    current = found;
                } else {
                    printf("❌ Song not found!\n");
                }
                break;
            case 7:
                freePlaylist(playlist);
                exit(0);
            default:
                printf("⚠️ Invalid choice!\n");
        }
    }
    return 0;
}
