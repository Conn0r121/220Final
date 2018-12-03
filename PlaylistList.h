//
// Created by conno on 12/2/2018.
//

#ifndef INC_220FINAL_PLAYLISTLIST_H
#define INC_220FINAL_PLAYLISTLIST_H

#include "Playlist.h"


class PlaylistList {
private:
    Playlist* playlistList;
    int listSize;
    int playlistCount;
    void doubleCapacity();

public:
    void addPlaylist(Playlist playlistToAdd);
    void removePlaylist(std::string name);
    Playlist getPlaylist(std::string name)
};


#endif //INC_220FINAL_PLAYLISTLIST_H
