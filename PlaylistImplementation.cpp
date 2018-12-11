//
// Created by conno on 12/3/2018.
//

#include "PlaylistImplementation.h"

PlaylistImplementation::PlaylistImplementation() {
    songList = new ArrayList<Song*>(1);
    playlistName="";
    duration=0;
};

PlaylistImplementation::PlaylistImplementation(std::string name) {
    songList = new ArrayList<Song*>(10);
    playlistName = name;
    duration = 0;
}

std::string PlaylistImplementation::toString() {
    std::string result = songList->getValueAt(0)->toString();
    for (int i = 1; i < songList->itemCount(); i++) {
        result = result +  "\n" + songList->getValueAt(i)->toString();
        std::cout<<result<<std::endl;
    }


    return result;
}

int PlaylistImplementation::calcDuration() {
    for (int i = 0; i < songList->itemCount(); i++) {
        duration += songList->getValueAt(i)->getDuration();
    }
    return duration;
}

std::string PlaylistImplementation::playNext() {
    return songList->removeValueAtFront()->toString();

}

bool PlaylistImplementation::isEmpty() {
    return songList->isEmpty();
}

void PlaylistImplementation::addSongAtEnd(Song* &newSong) {
    std::cout<<newSong<<" inaddSongAtEnd in PlaylistImplementation"<<std::endl;
    songList->insertAtEnd(newSong);
}

void PlaylistImplementation::addSongAlphabetically(Song* &newSong) {
    songList->insertAtEnd(newSong);
}

void PlaylistImplementation::removeSong(std::string artist, std::string title) {
    if (isEmpty()) {
        throw std::out_of_range("Playlist is empty");
    } else {
        bool found = false;
        for (int i = 0; i < songList->itemCount(); i++) {
            if (songList->getValueAt(i)->getArtist() == artist || songList->getValueAt(i)->getTitle() == title) {
                songList->removeValueAt(i);
                found = true;
            }
        }
        if (!found) {
            throw std::out_of_range("Song is not in playlist");
        }
    }
}
//
//Song PlaylistImplementation::getSongByArtist(std::string artistName) {
//    for(int i=0;i<songList->itemCount(); i++){
//        if(songList->getValueAt(i)->getArtist())
//    }
//
//}
//Song PlaylistImplementation::getSongByTitle(std::string songName) {
//
//}
//
Song* PlaylistImplementation::getSongByPosition(int position){
    return songList->getValueAt(position);
}
int PlaylistImplementation::getPlaylistSize(){
    return songList->itemCount();
}

Song* PlaylistImplementation::getSongByArtistandTitle(std::string artistIn, std::string titleIn){
    for(int i=0;i<songList->itemCount();i++){
        if(songList->getValueAt(i)->getArtist()==artistIn && songList->getValueAt(i)->getTitle()==titleIn){
            return songList->getValueAt(i);
        }
    }
    throw std::invalid_argument("Song Not Found");
}


