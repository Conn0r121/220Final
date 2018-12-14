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
    std::cout<<"\n"<<std::endl;
    std::cout<<newInventory->getAllPlaylists()->displayAllPlaylistNames()<<std::endl;
    newInventory->saveLibrary();





}
int main(){
    LibraryTest();
    return 0;
}