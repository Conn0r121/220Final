//
// Created by conno on 12/3/2018.
//

#include "InventoryImplementation.h"

InventoryImplementation::InventoryImplementation(){
    std::cout<<"pl made"<<std::endl;
    PlaylistImplementation *allSongs = new PlaylistImplementation();
    std::cout<<"pc made"<<std::endl;
    PlaylistCollectionImplementation *allPlaylists = new PlaylistCollectionImplementation();
}

void InventoryImplementation::addSongToLibrary(std::string artist, std::string title){
    allSongs.addSongAlphabetically(artist, title);
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

