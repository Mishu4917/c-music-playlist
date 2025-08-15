#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Song {
    string title;
    string artist;
};

class Playlist {
private:
    vector<Song> songs;
    int currentIndex;

public:
    Playlist();

    void addSong(string title, string artist);
    void deleteSong(string title);
    void displayPlaylist();
    void playNext();
    void playPrevious();
    void searchSong(string title);
};

#endif