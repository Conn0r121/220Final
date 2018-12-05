//
// Created by Daniel McCaffrey on 12/4/2018.
//
#include "PlaylistImplementation.h"


Playlist* hardcodedSongPlaylist() {
    Playlist* newPlaylist = new PlaylistImplementation("Example");

    newPlaylist->addSong("Billy Joel", "Piano Man");
    newPlaylist->addSong("Miley Cyrus", "Party in the USA");
    newPlaylist->addSong("Metallica", "Enter Sandman");
    newPlaylist->addSong("Earth Wind and Fire", "September");

    return newPlaylist;
}

int main() {
    Playlist* testPlaylist = hardcodedSongPlaylist();
    std::cout << testPlaylist->toString() << std::endl;
    std::cout << std::endl;
    testPlaylist->removeSong("Billy Joel", "Piano Man");
    std::cout << testPlaylist->toString() << std::endl;
    std::cout << std::endl;
    std::string testString = testPlaylist->playNext();
    std::cout << testPlaylist->toString();

    return 0;
}