//
// Created by conno on 12/3/2018.
//

#include "PlaylistCollectionImplementation.h"


PlaylistCollectionImplementation::PlaylistCollectionImplementation() {
    allPlaylists = new ArrayList<PlaylistImplementation*>(5);
}

PlaylistCollectionImplementation::~PlaylistCollectionImplementation() {
    delete allPlaylists;
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
PlaylistImplementation*  PlaylistCollectionImplementation::getPlayListByLocation(int pos){
    return allPlaylists->getValueAt(pos);
}

int PlaylistCollectionImplementation::getSize(){
    return allPlaylists->itemCount();
}
std::string PlaylistCollectionImplementation::displayAllPlaylistNames(){
    if (isEmpty()) {
        std::cerr << "Called playlists on empty playlist";
        exit(1);
    }
    std::string returnString ="";
    int duration = 0;
    for (int i=0; i<allPlaylists->itemCount(); i++){
        if (allPlaylists->getValueAt(i) == nullptr) {
            allPlaylists->removeValueAt(i);
        } else {
            returnString += allPlaylists->getValueAt(i)->getPlaylistName() += " ";
            duration = allPlaylists->getValueAt(i)->calcDuration();
            returnString += std::to_string(duration) + "\n";
        }
    }
    return returnString;
}

void PlaylistCollectionImplementation::newPlaylist(PlaylistImplementation *newPlaylist ){
    allPlaylists->insertAtEnd(newPlaylist);
}

void PlaylistCollectionImplementation::delWhenEmpty() {
    for (int i = 0; i < getSize(); i++) {
        if (getPlayListByLocation(i)->isEmpty()) {
            delete getPlayListByLocation(i);
        }
    }
}


PlaylistImplementation* PlaylistCollectionImplementation::getPlaylistByName(std::string name){
    for (int i=0; i<allPlaylists->itemCount(); i++){
        if(allPlaylists->getValueAt(i)->getPlaylistName()==name){
            return allPlaylists->getValueAt(i);
        }
    }


}

PlaylistCollectionImplementation &
PlaylistCollectionImplementation::operator=(const PlaylistCollectionImplementation &playlistCollectionToCopy) {
    return *this;
}

bool PlaylistCollectionImplementation::isEmpty() {
    if (allPlaylists->itemCount() == 0) {
        return true;
    } else {
        return false;
    }
}