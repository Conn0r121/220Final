//
// Created by Jeff Page on 11/27/18.
//

#ifndef INC_220FINAL_PLAYLIST_H
#define INC_220FINAL_PLAYLIST_H

#include "ArrayList.cpp"
#include "Song.cpp"

class Playlist {
private:
    ArrayList * myList;
public:
    Playlist();
    void addSong(const Song *mySong);
    void removeSong();
    void findSong();
    void findArtist();

};



#endif //INC_220FINAL_PLAYLIST_H
