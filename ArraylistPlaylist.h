//
// Created by Jeff Page on 11/27/18.
//

#ifndef INC_220FINAL_PLAYLIST_H
#define INC_220FINAL_PLAYLIST_H

#include "ArrayList.h"
#include "Song.h"
#include "Playlist.h"

class ArraylistPlaylist : public Playlist {
private:
    ArrayList * myList;
public:
    ArraylistPlaylist();
    void addSong(const Song *mySong);
    void removeSong();
    void findSong();
    void findArtist();

};



#endif //INC_220FINAL_PLAYLIST_H
