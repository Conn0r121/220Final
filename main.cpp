#include <iostream>
#include <sstream>
#include "Inventory.h"
#include "InventoryImplementation.h"
#include <string>


int main() {
    Inventory *inventory = new InventoryImplementation();
    inventory->loadLibrary();
    bool programExit = false;
    std::cout << "Playlist program" << std::endl;
    std::cout << "Type help for a list of commands" << std::endl;
    while (!programExit) {
        std::string command;
        getline(std::cin, command);
        if (command == "help") {
            std::cout << "help\tdisplays all available commands\n"
                         "import <filename>\timports songs from a text file and adds to library\n"
                         "discontinue <filename>\tremoves all songs listed in file from library\n"
                         "library\tdisplays all songs in the library\n"
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
        } else if (command == "quit") {
            inventory->saveLibrary();
            programExit = true;
        } else if (command == "add") {
            std::string title;
            std::string artist;
            std::string name;

            std::cout << "enter title: ";
            getline(std::cin, title);

            std::cout << "enter artist: ";
            getline(std::cin, artist);

            std::cout << "enter name of playlist: ";
            getline(std::cin, name);
            std::cout << artist <<" " <<title << std::endl;
            Song *songToAdd = inventory->getAllSongs()->getSongByArtistandTitle(artist,title);
            inventory->getAllPlaylists()->getPlaylistByName(name)->addSongAlphabetically(songToAdd);

        } else if (command == "library") {
            std::cout << inventory->displayLibrary() << std::endl;
        } else if (command == "remove") {
            std::string artist;
            std::cout << "enter artist: ";
            getline(std::cin, artist);
            std::cout << "enter title: ";
            std::string title;
            getline(std::cin, title);
            std::string name;
            std::cout << "enter name: ";
            getline(std::cin, name);
            inventory->getAllPlaylists()->getPlaylistByName(name)->removeSong(artist, title);
        } else if (command == "import") {
            std::string fileName;
            std::cout << "enter file name: ";
            getline(std::cin, fileName);
            inventory->import(fileName);
        } else if (command == "discontinue") {
            std::string fileName;
            std::cout << "enter file name: ";
            getline(std::cin, fileName);
            inventory->discontinue(fileName);
        } else if (command == "playnext") {
            std::string name;
            std::cout << "enter name: ";
            getline(std::cin, name);
            std::cout << inventory->getAllPlaylists()->getPlaylistByName(name)->playNext() << std::endl;
        } else if (command == "artist") {
            std::string artist;
            std::cout << "enter artist: ";
            getline(std::cin, artist);
            std::cout << inventory->displayByArtist(artist) << std::endl;
        } else if (command == "song") {
            std::string artist;
            std::cout << "enter artist: ";
            getline(std::cin, artist);
            std::string title;
            std::cout << "enter title: ";
            getline(std::cin, title);
            std::cout << inventory->displaySong(artist, title) << std::endl;
        } else if (command == "new") {
            //overwrites any existing playlists
            std::string name;
            std::cout << "enter name: " << std::endl;
            getline(std::cin, name);
            PlaylistImplementation *newPlaylist = new PlaylistImplementation(name);
            inventory->getAllPlaylists()->newPlaylist(newPlaylist);
        } else if (command == "playlists") {
            std::cout << inventory->displayPlaylists() << std::endl;
        } else if (command == "playlist") {
            std::string name;
            std::cout << "enter name: ";
            getline(std::cin, name);
            std::cout << inventory->getAllPlaylists()->displayPlaylist(name) << std::endl;
        } else if (command == "newrandom") {
            //overwrites existing playlists
            std::string name;
            std::cout << "enter name: ";
            getline(std::cin, name);
            int dur;
            std::cout << "enter duration: ";
            std::cin >> dur;
            inventory->genRandPlaylist(name, dur);
        }
    }
    return 0;
}