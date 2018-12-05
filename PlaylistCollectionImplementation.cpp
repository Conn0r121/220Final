//
// Created by conno on 12/3/2018.
//

#include "PlaylistCollectionImplementation.h"

PlaylistCollectionImplementation::PlaylistCollectionImplementation() {
    playlistList = new ArrayList<Playlist*>*(10);
}


std::string PlaylistCollectionImplementation::displayAll() {
    std::string result = "";
    for (int i = 0; i < playlistList->itemCount(); i++) {
        result += playlistList->getValueAt(i)->toString();
    }
    return result;
}

std::string PlaylistCollectionImplementation::displayPlaylist(std::string playlistToFind) {
    for (int i = 0; i < playlistList->itemCount(); i++) {
        if (playlistList->getValueAt(i)->getName() == playlistToFind) {
            return playlistList->getValueAt(i)->toString();
        }
    }
}

void PlaylistCollectionImplementation::delWhenEmpty() {

}

void PlaylistCollectionImplementation::newRandPlaylist() {

}