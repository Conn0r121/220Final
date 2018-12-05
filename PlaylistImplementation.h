//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_PLAYLISTIMPLEMENTATION_H
#define INC_220FINAL_PLAYLISTIMPLEMENTATION_H

#include "Playlist.h"

class PlaylistImplementation: public Playlist {
private:
    List<Song*>* songList;
    std::string playlistName;
    int duration;

public:
    PlaylistImplementation();

    PlaylistImplementation(std::string name);

    std::string toString();

    void calcDuration();

    std::string playNext();

    bool isEmpty();

    void addSong(std::string artist, std::string title);

    void removeSong(std::string artist, std::string title);
//
//    Song getSongByArtist(std::string artistName);
//
//    Song getSongByTitle(std::string songName);
//
//    Song getSongByPosition(int position);

};


#endif //INC_220FINAL_PLAYLISTIMPLEMENTATION_H
