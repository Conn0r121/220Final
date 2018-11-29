//
// Created by Jeff Page on 11/27/18.
//

#include "Playlist.h"

Playlist::Playlist(){
    myList = new ArrayList(10);
}
void Playlist::addSong(const Song *mySong) {
    myList->insertAtFront(mySong);
}
void Playlist::removeSong(const Song *mySong) {

}
