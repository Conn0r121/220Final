//
// Created by conno on 12/3/2018.
//

#include "PlaylistImplementation.h"

PlaylistImplementation::PlaylistImplementation() {
    songList = new ArrayList<Song*>(10);
};

PlaylistImplementation::PlaylistImplementation(std::string name) {
    songList = new ArrayList<Song*>(10);
    playlistName = name;
    duration = 0;
}

std::string PlaylistImplementation::toString() {
    std::string result = "";
    result = songList->getValueAt(0)->toString();
    for (int i = 0; i < songList->getItemCount(); i++) {
        resultsongList[i]
    }
    return "";
}

void PlaylistImplementation::calcDuration() {

}

std::string PlaylistImplementation::playNext() {
    Song* currSong;

}

bool PlaylistImplementation::isEmpty() {
    return true;
}

void PlaylistImplementation::addSong() {

}

void PlaylistImplementation::removeSong() {

}

Song PlaylistImplementation::getSongByArtist(std::string artistName) {

}
Song PlaylistImplementation::getSongByTitle(std::string songName) {

}

Song getSongByPosition(int position){

}