//
//Created my conno
//
#include "Song.h"
#include "InventoryImplementation.h"
#include "PlaylistCollectionImplementation.h"
#include "PlaylistImplementation.h"


void inventoryTest(){
    Song* song1 = new Song("Billy Joel", "Piano Man", 270, 71354643);
    Song* song2 = new Song("Miley Cyrus", "Party in the USA", 202, 100275463);
    Song* song3 = new Song("Metallica", "Enter Sandman", 332, 87264930);
    Song* song4 = new Song("Earth Wind and Fire", "September", 215, 116435849);
    Song* song5 = new Song("Miley Cyrus", "Blarty in the Bu Bus Bay", 202, 100275463);
    std::cout<<"songsCreated"<<std::endl;

    InventoryImplementation *newInventory = new InventoryImplementation();
    std::cout<<"inventoryCreated"<<std::endl;
    newInventory->addSongToLibrary(song1);
    newInventory->addSongToLibrary(song2);
    newInventory->addSongToLibrary(song3);
    newInventory->addSongToLibrary(song4);
    newInventory->addSongToLibrary(song5);


    std::cout<<"testing display Library\nThis should be each songs info in alphabetical info by artist"<<std::endl;
    newInventory->displayLibrary();
    std::cout<<"Testing display by artist"<<std::endl;
    std::cout<<"This should be the 2 miley cyrus songs info"<<std::endl;
    newInventory->displayByArtist("Miley Cyrus");
    std::cout<<"Testing displayBySong"<<std::endl;
    std::cout<<"This should be party in the usa info"<<std::endl;
    newInventory->displaySong("Miley Cyrus","Party in the USA");

}



int main(){
    inventoryTest();
    return 0;
}