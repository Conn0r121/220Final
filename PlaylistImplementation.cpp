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
    result += songList->getValueAt(0)->toString();
    for (int i = 1; i < songList->getItemCount(); i++) {
        result += ", " + songList->getValueAt(i)->toString();
    }
    return result;
}

void PlaylistImplementation::calcDuration() {
    for (int i = 0; i < songList->getItemCount(); i++) {
        duration += songList->getValueAt(i)->getDuration();
    }
}

std::string PlaylistImplementation::playNext() {
    return songList->removeValueAtFront()->toString();

}

bool PlaylistImplementation::isEmpty() {
    return songList->isEmpty();
}

void PlaylistImplementation::addSong(std::string artist, std::string title) {
    Song* newSong = new Song(artist, title, 0, 0);
    return songList->insertAtEnd(newSong);
}

void PlaylistImplementation::removeSong() {

}

Song PlaylistImplementation::getSongByArtist(std::string artistName) {

}
Song PlaylistImplementation::getSongByTitle(std::string songName) {

}

Song getSongByPosition(int position){

}