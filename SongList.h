//
// Created by conno on 12/2/2018.
//

#ifndef INC_220FINAL_SONGLIST_H
#define INC_220FINAL_SONGLIST_H

#include "Song.h"

class SongList {
private:
    Song* songList;
    int listSize;
    int songCount;
    void doubleCapacity();
public:
    SongList();
    ~SongList();
    void addSong(Song songToAdd);
    void removeSong(std::string name);
    Song getSongByName(std::string name);


};


#endif //INC_220FINAL_SONGLIST_H
