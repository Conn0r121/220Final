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
    std::string returnString ="";
    for (int i=0; i<allPlaylists->itemCount(); i++){
        if(allPlaylists->getValueAt(i)->getPlaylistName()==playlistToFind){
            return allPlaylists->getValueAt(i)->toString();
        }
    }
}

std::string PlaylistCollectionImplementation::displayAllPlaylistNames(){
    std::string returnString ="";
    for (int i=0; i<allPlaylists->itemCount(); i++){
        returnString += allPlaylists->getValueAt(i)->getPlaylistName() += "\n";
    }
    return returnString;
}

void PlaylistCollectionImplementation::newPlaylist(PlaylistImplementation *newPlaylist ){
    allPlaylists->insertAtEnd(newPlaylist);
}

void PlaylistCollectionImplementation::delWhenEmpty() {

}

void PlaylistCollectionImplementation::newRandPlaylist() {

}

PlaylistImplementation* PlaylistCollectionImplementation::getPlaylistByName(std::string name){
    for (int i=0; i<allPlaylists->itemCount(); i++){
        if(allPlaylists->getValueAt(i)->getPlaylistName()==name){
            return allPlaylists->getValueAt(i);
        }
    }

}

PlaylistCollectionImplementation::PlaylistCollectionImplementation(
        const PlaylistCollectionImplementation &playlistCollectionToCopy) {

}

PlaylistCollectionImplementation &
PlaylistCollectionImplementation::operator=(const PlaylistCollectionImplementation &playlistCollectionToCopy) {
    return *this;
}
