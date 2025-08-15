# 🎵 C++ Music Playlist Manager

A colorful, interactive, and fully-featured *C++ music playlist manager* built using a *Circular Doubly Linked List*.  
It works like a mini music player in your terminal — with wrap-around next/previous navigation, neat playlist display, and emoji-based output.

---

## ✨ Features
- 📀 *Circular Doubly Linked List* for infinite next/previous navigation.
- 🎨 *Colorful & Emoji Output* for an engaging CLI experience.
- 📜 *Formatted Table View* for clean playlist display.
- 🔍 *Search & Play* any song instantly.
- ♻️ *Automatic Memory Cleanup* on exit.
- 📂 Simple 3-file structure (main.cpp, playlist.cpp, playlist.h).

---

## 📁 Project Structure
PlaylistManager/
├── main.cpp # User menu & interaction
├── playlist.cpp # Playlist class implementation
└── playlist.h # Song & Playlist class definitions

Copy
Edit

---

## ⚙️ How to Compile & Run
Make sure you have *g++* installed.

### Compile
```bash
g++ main.cpp playlist.cpp -o playlist
Run
bash
Copy
Edit
./playlist
🖥️ Menu Options
Copy
Edit
1. Add Song
2. Delete Song
3. Display Playlist
4. Play Next
5. Play Previous
6. Search Song
7. Exit
🎯 Example Usage
Copy
Edit
🎵🎵 C++ Music Playlist Manager 🎵🎵
1. Add Song
Enter song title: Believer
Enter artist name: Imagine Dragons
🎶 Added first song: "Believer" by Imagine Dragons

3. Display Playlist
No.  Title                          Artist
1    Believer                       Imagine Dragons

4. Play Next
▶️ Now playing: "Believer" by Imagine Dragons
🚀 Future Enhancements
⏱️ Auto-play Mode: Play all songs automatically with delays.

💾 Save & Load playlist from a file.

🔄 Shuffle mode.

📝 License
This project is open-source and available under the MIT License.
