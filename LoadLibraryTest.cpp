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
    newInventory->discontinue("Discontinue.txt");
    newInventory->import("importTest.txt");
    newInventory->saveLibrary();




}
int main(){
    LibraryTest();
    return 0;
}