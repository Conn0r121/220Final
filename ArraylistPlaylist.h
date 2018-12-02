//
// Created by Jeff Page on 11/27/18.
//

#ifndef INC_220FINAL_ARRAYLISTPLAYLIST_H
#define INC_220FINAL_ARRAYLISTPLAYLIST_H

#include "ArrayList.h"
#include "Song.h"
#include "Playlist.h"

class ArraylistPlaylist : public Playlist {
private:
    ArrayList * myList;
    int duration;
public:
    ArraylistPlaylist();
    std::string toString();
    void calcDuration();
    std::string playNext();
    bool isEmpty();
    void addSong();
    void removeSong();

};



#endif //INC_220FINAL_ARRAYLISTPLAYLIST_H
