//
// Created by student on 12/1/2018.
//

#ifndef INC_220FINAL_PLAYLISTCOLLECTION_H
#define INC_220FINAL_PLAYLISTCOLLECTION_H

#include "Playlist.h"

class PlaylistCollection {
private:
    List* songs;
public:
    virtual std::string displayAll() =0;
    virtual std::string displayPlaylist(std::string playlistToFind) =0;
    virtual void delWhenEmpty() =0;
    virtual void newPlaylist() =0;
    virtual void newRandPlaylist() =0;

};
#endif //INC_220FINAL_PLAYLISTCOLLECTION_H
