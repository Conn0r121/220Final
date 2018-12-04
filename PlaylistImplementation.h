//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_PLAYLISTIMPLEMENTATION_H
#define INC_220FINAL_PLAYLISTIMPLEMENTATION_H

#include "Playlist.h"

class PlaylistImplementation: public Playlist {
private:

public:
    std::string toString();

    void calcDuration();

    std::string playNext();

    bool isEmpty();

    void addSong();

    void removeSong();

};


#endif //INC_220FINAL_PLAYLISTIMPLEMENTATION_H
