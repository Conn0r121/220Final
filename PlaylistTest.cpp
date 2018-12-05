//
// Created by Daniel McCaffrey on 12/4/2018.
//
#include "PlaylistImplementation.h"
#include "TestLib.h"


Playlist* hardcodedSongPlaylist() {
    Playlist* newPlaylist = new PlaylistImplementation("Example");

    std::cout << "---AddSong tests---" << std::endl;

    std::cout << "First Song:" << std::endl;
    newPlaylist->addSong("Billy Joel", "Piano Man");
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Second Song:" << std::endl;
    newPlaylist->addSong("Miley Cyrus", "Party in the USA");
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Third Song:" << std::endl;
    newPlaylist->addSong("Metallica", "Enter Sandman");
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Fourth Song:" << std::endl;
    newPlaylist->addSong("Earth Wind and Fire", "September");
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    return newPlaylist;
}

int main() {
    Playlist* testPlaylist = hardcodedSongPlaylist();

    std::cout << "Full Playlist:" << std::endl;
    std::cout << testPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "---RemoveSong Test---" << std::endl;
    testPlaylist->removeSong("Billy Joel", "Piano Man");
    std::cout << testPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "---PlayNext Test---" << std::endl;
    std::string testString = testPlaylist->playNext();
    printAssertEquals(testString, "Artist: Miley Cyrus, Title: Party in the USA, Duration: 0, Play Count: 0");
    std::cout << std::endl;

    std::cout << "Should be without Miley Cyrus:" << std::endl;
    std::cout << testPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Testing removing from empty playlist:" << std::endl;
    testPlaylist->playNext();
    testPlaylist->playNext();
    try {
        testPlaylist->playNext();
        std::cout << "FAIL: removing from empty playlist should throw exception";
    } catch (std::out_of_range& e) {
        std::cout << "pass" << std::endl;
    }

    return 0;
}