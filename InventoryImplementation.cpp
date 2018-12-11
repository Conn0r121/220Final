//
// Created by conno on 12/3/2018.
//

#include "InventoryImplementation.h"

InventoryImplementation::InventoryImplementation(){
    PlaylistImplementation *allSongs = new PlaylistImplementation();
    PlaylistCollectionImplementation *allPlaylists = new PlaylistCollectionImplementation();
}

void InventoryImplementation::addSongToLibrary(Song* &newSong){
    allSongs.addSongAlphabetically(newSong);
}

void InventoryImplementation::discontinue() {
//TODO
}

std::string InventoryImplementation::displayLibrary() {
    return allSongs.toString();

}
std::string InventoryImplementation::displayByArtist(std::string artistName) {
    std::string returnString="";
    for(int i=0; i<allSongs.getPlaylistSize(); i++){
        if(allSongs.getSongByPosition(i)->getArtist()==artistName){
            returnString+=allSongs.getSongByPosition(i)->toString()+"\n";
        }
    }
    return returnString;
}

std::string InventoryImplementation::displaySong(std::string artist, std::string title) {
    for (int i = 0; i < allSongs.getPlaylistSize(); i++) {
        if (allSongs.getSongByPosition(i)->getArtist() == artist && allSongs.getSongByPosition(i)->getTitle() == title) {
            return allSongs.getSongByPosition(i)->toString();
        }
    }
    return "No Songs to Display";
}
void InventoryImplementation::loadLibrary() {
//TODO
}

void InventoryImplementation::saveLibrary() {
//TODO
}
void InventoryImplementation::import(){
//TODO
}

