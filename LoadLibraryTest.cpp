//
// Created by Jeff Page on 12/12/18.
//

#include "Song.h"
#include "InventoryImplementation.h"
#include "PlaylistCollectionImplementation.h"
#include "PlaylistImplementation.h"

void LibraryTest(){
    InventoryImplementation *newInventory = new InventoryImplementation();
    newInventory->loadLibrary();
    newInventory->genRandPlaylist("coolioList",1200);
    std::cout<<newInventory->getAllPlaylists()->getPlaylistByName("coolioList")->calcDuration()<<std::endl;





}
int main(){
    LibraryTest();
    return 0;
}