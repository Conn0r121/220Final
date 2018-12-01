//
// Created by Jeff Page on 11/27/18.
//

#include "ArraylistPlaylist.h"

ArraylistPlaylist::ArraylistPlaylist(){
    myList = new ArrayList(10);
}
void ArraylistPlaylist::addSong(const Song *mySong) {
    myList->insertAtFront(mySong);
}
void ArraylistPlaylist::removeSong(const Song *mySong) {

}
