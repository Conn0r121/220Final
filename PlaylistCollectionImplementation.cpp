//
// Created by conno on 12/3/2018.
//

#include "PlaylistCollectionImplementation.h"

PlaylistCollectionImplementation::PlaylistCollectionImplementation() {
    allPlaylists = new ArrayList<PlaylistImplementation*>(5);
}

std::string PlaylistCollectionImplementation::displayAll() {
    std::string returnString="";
    for(int i=0; i<allPlaylists->itemCount(); i++){
        returnString+=allPlaylists->getValueAt(i)->toString()+"\n";
    }
    return returnString;
}

std::string PlaylistCollectionImplementation::displayPlaylist(std::string playlistToFind) {
    return "";
}

void PlaylistCollectionImplementation::newPlaylist(){

}

void PlaylistCollectionImplementation::delWhenEmpty() {

}

void PlaylistCollectionImplementation::newRandPlaylist() {

}

PlaylistCollectionImplementation::PlaylistCollectionImplementation(
        const PlaylistCollectionImplementation &playlistCollectionToCopy) {

}

PlaylistCollectionImplementation &
PlaylistCollectionImplementation::operator=(const PlaylistCollectionImplementation &playlistCollectionToCopy) {
    return *this;
}
