//
// Created by conno on 12/3/2018.
//

#include "InventoryImplementation.h"
#include "Song.h"


void InventoryImplementation::addSongToLibrary(Song songIn){
    allSongs.insertAtFront(songIn);
}

void InventoryImplementation::discontinue() {

}

std::string InventoryImplementation::displayLibrary() {
    return "";

}
std::string InventoryImplementation::displayByArtist(std::string artistName) {
    std::string returnString="";
    for(int i=0; i<totalSongCount; i++){
        if(allSongs.getValueAt(i).getArtist()==artistName){
            returnString+=allSongs.getValueAt(i).toString()+"\n";
        }
    }
    return returnString;
}

std::string InventoryImplementation::displaySong(std::string songName) {
    for (int i = 0; i < totalSongCount; i++) {
        if (allSongs.getValueAt(i).getArtist() == songName) {
            return allSongs.getValueAt(i).toString();
        }
    }
    return "No Songs to Display";
}
void InventoryImplementation::loadLibrary() {

}

void InventoryImplementation::saveLibrary() {

}
void InventoryImplementation::import(){

}

