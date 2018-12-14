#include <iostream>
#include <sstream>
#include "Inventory.h"
#include "InventoryImplementation.h"

int main() {
    Inventory* inventory = new InventoryImplementation();
    inventory->loadLibrary();
    bool programExit = false;
    std::string fullString;
    std::cout << "Playlist program" << std::endl;
    std::cout << "Type help for a list of commands" << std::endl;
    while (!programExit) {
        std::cin >> fullString;
        std::istringstream ss(fullString);
        std::string command;
        ss >> command;
        if (command == "help") {
            std::cout << "help\tdisplays all available commands\n"
                    "import <filename>\timports songs from a text file and adds to library\n"
                    "discontinue <filename>\tremoves all songs listed in file from library\n"
                    "library\tdisplays all songs in the library"
                    "artist <artist>\tdisplays all songs by a given artist\n"
                    "song <artist, title>\tdisplays all information about the given song\n"
                    "playlists\tdisplays the names of all playlists and their durations\n"
                    "playlist <name>\tdisplays all songs in a given playlist and the playlist's duration\n"
                    "new <name>\tcreates a new empty playlist with the given name\n"
                    "add <name, artist, title>\tadds the given song to end of the given playlist\n"
                    "remove <name, artist, title>\tremoves the given song from the given playlist\n"
                    "playnext <name>\tdisplays the next song in the playlist and removes it\n"
                    "newrandom <name, duration>\tcreates a playlist with random songs that total the given duration\n"
                    "quit\tsaves all songs and quits the program" << std::endl;
        } else if (command == "quit"){
            inventory->saveLibrary();
            programExit = true;
        } else if (command == "add") {
            std::string title;
            ss >> title;
            std::string artist;
            ss >> artist;
            std::string name;
            ss >> name;
            Song* songToAdd = inventory->getAllSongs()->getSongByArtistandTitle(artist, title);
            inventory->getAllPlaylists()->getPlaylistByName(name)->addSongAtEnd(songToAdd);
        } else if (command == "library") {
            std::cout<<inventory->displayLibrary()<<std::endl;
        } else if (command == "remove") {
            std::string artist;
            ss >> artist;
            std::string title;
            ss >> title;
            std::string name;
            ss >> name;
            inventory->getAllPlaylists()->getPlaylistByName(name)->removeSong(artist, title);
        } else if (command == "import") {
            std::string fileName;
            ss >> fileName;
            inventory->import(fileName);
        } else if (command == "discontinue") {
            std::string fileName;
            ss >> fileName;
            inventory->discontinue(fileName);
        } else if (command == "playnext") {
            std::string name;
            ss >> name;
            inventory->getAllPlaylists()->getPlaylistByName(name)->playNext();
        } else if (command == "artist") {
            std::string artist;
            ss >> artist;
            inventory->displayByArtist(artist);
        } else if (command == "song") {
            std::string artist;
            ss >> artist;
            std::string title;
            ss >> title;
            inventory->displaySong(artist, title);
        } else if (command == "new") {

        } else if (command == "playlists") {
            inventory->displayPlaylists();
        } else if (command == "playlist") {
            std::string name;
            ss >> name;
            inventory->getAllPlaylists()->displayPlaylist(name);
        } else if (command == "newrandom") {
            std::string name;
            ss >> name;
        }
    }
    return 0;
}