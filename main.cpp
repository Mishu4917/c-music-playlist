#include <iostream>
#include <string>
#include "playlist.h"
using namespace std;

int main() {
    Playlist playlist;
    int choice;
    string title, artist;

    while (true) {
        cout << "\n🎵🎵 " << "\033[1;35m" << "C++ Music Playlist Manager" << "\033[0m" << " 🎵🎵\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Next\n";
        cout << "5. Play Previous\n";
        cout << "6. Search Song\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                playlist.addSong(title, artist);
                break;

            case 2:
                cout << "Enter title to delete: ";
                getline(cin, title);
                playlist.deleteSong(title);
                break;

            case 3:
                playlist.displayPlaylist();
                break;

            case 4:
                playlist.playNext();
                break;

            case 5:
                playlist.playPrevious();
                break;

            case 6:
                cout << "Enter title to search: ";
                getline(cin, title);
                playlist.searchSong(title);
                break;

            case 7:
                cout << "\033[1;34m👋 Exiting Playlist Manager. Goodbye!\033[0m\n";
                return 0;

            default:
                cout << "\033[1;31m⚠️ Invalid choice!\033[0m\n";
        }
    }
}