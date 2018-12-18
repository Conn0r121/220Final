//
// Created by Daniel McCaffrey on 12/4/2018.
//
#include "PlaylistImplementation.h"
#include "TestLib.h"
#include "PlaylistCollectionImplementation.h"

PlaylistImplementation* hardcodedSongPlaylist() {
    PlaylistImplementation* newPlaylist = new PlaylistImplementation("Example");

    std::cout << "---AddSong tests---" << std::endl;

    std::cout << "First Song:" << std::endl;
    Song* song1 = new Song("Billy Joel", "Piano Man", 100, 0);
    newPlaylist->addSongAtEnd(song1);

    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Second Song:" << std::endl;
    Song* song2 = new Song("Miley Cyrus", "Party in the USA", 100, 0);
    newPlaylist->addSongAtEnd(song2);
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Third Song:" << std::endl;
    Song* song3 = new Song("Metallica", "Enter Sandman", 100, 0);
    newPlaylist->addSongAtEnd(song3);
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Fourth Song:" << std::endl;
    Song* song4 = new Song("Earth Wind and Fire", "September", 100, 0);
    newPlaylist->addSongAtEnd(song4);
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    return newPlaylist;
}
PlaylistImplementation* hardcodedSongPlaylist2() {
    PlaylistImplementation* newPlaylist = new PlaylistImplementation("Example2");

    std::cout << "---AddSong tests---" << std::endl;

    std::cout << "First Song:" << std::endl;
    Song* song1 = new Song("Billy Joel", "Piano Man", 100, 0);
    newPlaylist->addSongAtEnd(song1);

    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Second Song:" << std::endl;
    Song* song2 = new Song("Miley Cyrus", "Party in the USA", 100, 0);
    newPlaylist->addSongAtEnd(song2);
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Third Song:" << std::endl;
    Song* song3 = new Song("Metallica", "Enter Sandman", 100, 0);
    newPlaylist->addSongAtEnd(song3);
    std::cout << newPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Fourth Song:" << std::endl;
    Song* song4 = new Song("Earth Wind and Fire", "September", 100, 0);
    newPlaylist->addSongAtEnd(song4);
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
    std::cout<< " removing the billy Joel Song " << std::endl;
    testPlaylist->removeSong("Billy Joel", "Piano Man");
    std::cout << testPlaylist->toString() << std::endl;
    std::cout << std::endl;

    std::cout << "---PlayNext Test---" << std::endl;
    std::string testString = testPlaylist->playNext();
    printAssertEquals("Artist: Miley Cyrus, Title: Party in the USA, Duration: 0, Play Count: 0", testString);
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
    std::cout<<"\n\nend of single playlist Tests\n\n\n"<<std::endl;


    std::cout<<"testing collection"<<std::endl;
    PlaylistCollection* testCollection = new PlaylistCollectionImplementation();
    PlaylistImplementation* testPlaylist2 = hardcodedSongPlaylist();
    PlaylistImplementation* testPlaylist3 = hardcodedSongPlaylist2();

    testCollection->newPlaylist(*testPlaylist2);
    testCollection->newPlaylist(*testPlaylist3);
    std::cout<<"\ntesting displayplaylist"<<std::endl;
    std::cout<<"this should print each playlist, they look the same rn\n"<<std::endl;
    std::cout<<testCollection->displayPlaylist("Example")<<std::endl;
    std::cout<<"\n"<<std::endl;
    std::cout<<testCollection->displayPlaylist("Example2")<<std::endl;

    std::cout<<"\ntesting getPlaylist"<<std::endl;
    std::cout<<"this relys on playlist getName\n"<<std::endl;
    std::cout<<testCollection->getPlaylistByName("Example")->getPlaylistName()<<"\n"<<std::endl;

    std::cout<<"\ntesting getAllplaylist names"<<std::endl;
    std::cout<<testCollection->displayAllPlaylistNames()<<std::endl;

    std::cout<<"endTests"<<std::endl;
    return 0;
}
