//
// Created by Daniel McCaffrey on 12/4/2018.
//
#include "PlaylistImplementation.h"
#include "TestLib.h"


Playlist* hardcodedSongPlaylist() {
    Playlist* newPlaylist = new PlaylistImplementation("Example");

    std::cout << "---AddSong tests---" << std::endl;

    std::cout << "First Song:" << std::endl;
    newPlaylist->addSongAtFront("Billy Joel", "Piano Man");
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Second Song:" << std::endl;
    newPlaylist->addSongAtFront("Miley Cyrus", "Party in the USA");
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Third Song:" << std::endl;
    newPlaylist->addSongAtFront("Metallica", "Enter Sandman");
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Fourth Song:" << std::endl;
    newPlaylist->addSongAtFront("Earth Wind and Fire", "September");
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

    std::cout <<"-----Song By Position Test--------"<<std::endl;
    for (int i=0;i<testPlaylist->getPlaylistSize();i++){
        std::string s = std::to_string(i);
        std::cout<< "Getting at Position "+ s <<std::endl;
        std::cout<< testPlaylist->getSongByPosition(i)->toString() <<std::endl;
    }
    std::cout <<std::endl;

    std::cout << "------Get Song by Artist and Title Test------"<<std::endl;
    for (int i=0;i<testPlaylist->getPlaylistSize();i++){
        std::cout<<"Getting "+testPlaylist->getSongByPosition(i)->getTitle() +" by "+testPlaylist->getSongByPosition(i)->getArtist() <<std::endl;
        std::cout <<testPlaylist->getSongByArtistandTitle(testPlaylist->getSongByPosition(i)->getArtist(),testPlaylist->getSongByPosition(i)->getTitle())->toString()<<std::endl;
    }
    std::cout<<std::endl;
    std::cout << "Testing getting Song by Artist and Title not present" <<std::endl;
    try{
        testPlaylist->getSongByArtistandTitle("NickelBack","Rockstar");
        std::cout<<" FAIL: getting song not present should throw exception";
    }
    catch(std::invalid_argument & e) {
        std::cout<< "pass" <<std::endl;

    }
    try{
        testPlaylist->getSongByArtistandTitle("Metallica","Nothing Else Matters");
        std::cout<<" FAIL: getting song not present should throw exception";
    }
    catch(std::invalid_argument & e) {
        std::cout<< "pass" <<std::endl;
    }
    try{
        testPlaylist->getSongByArtistandTitle("Smash Mouth","September");
        std::cout<<" FAIL: getting song not present should throw exception";
    }
    catch(std::invalid_argument & e) {
        std::cout<< "pass" <<std::endl;
    }
    std::cout<<std::endl;
    std::cout << "Testing removing from empty playlist:" << std::endl;
    testPlaylist->playNext();
    testPlaylist->playNext();
    try {
        testPlaylist->playNext();
        std::cout << "FAIL: removing from empty playlist should throw exception";
    } catch (std::out_of_range& e) {
        std::cout << "pass" << std::endl;
    }
    std::cout<<"\n\nend of tests"<<std::endl;
    return 0;
}