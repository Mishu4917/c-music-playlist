#include "playlist.h"

Playlist::Playlist() {
    currentIndex = -1;
}

void Playlist::addSong(string title, string artist) {
    Song newSong = {title, artist};
    songs.push_back(newSong);
    if (currentIndex == -1) currentIndex = 0;
    cout << "✅ Song added: " << title << " by " << artist << endl;
}

void Playlist::deleteSong(string title) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (it->title == title) {
            cout << "🗑️ Song deleted: " << it->title << endl;
            it = songs.erase(it);
            if (songs.empty()) currentIndex = -1;
            else if (currentIndex >= (int)songs.size()) currentIndex = songs.size() - 1;
            return;
        }
    }
    cout << "⚠️ Song not found!" << endl;
}

void Playlist::displayPlaylist() {
    if (songs.empty()) {
        cout << "📂 Playlist is empty.\n";
        return;
    }
    cout << "\n🎶 Playlist:\n";
    for (int i = 0; i < (int)songs.size(); i++) {
        cout << i + 1 << ". " << songs[i].title << " - " << songs[i].artist;
        if (i == currentIndex) cout << "  ⏯️ (Current)";
        cout << endl;
    }
}

void Playlist::playNext() {
    if (songs.empty()) {
        cout << "⚠️ Playlist is empty.\n";
        return;
    }
    currentIndex = (currentIndex + 1) % songs.size();
    cout << "▶️ Now playing: " << songs[currentIndex].title
         << " by " << songs[currentIndex].artist << endl;
}

void Playlist::playPrevious() {
    if (songs.empty()) {
        cout << "⚠️ Playlist is empty.\n";
        return;
    }
    currentIndex = (currentIndex - 1 + songs.size()) % songs.size();
    cout << "▶️ Now playing: " << songs[currentIndex].title
         << " by " << songs[currentIndex].artist << endl;
}

void Playlist::searchSong(string title) {
    for (const auto& song : songs) {
        if (song.title == title) {
            cout << "🔍 Found: " << song.title << " by " << song.artist << endl;
            return;
        }
    }
    cout << "❌ Song not found!" << endl;
}