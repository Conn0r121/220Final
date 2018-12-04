//
// Created by conno on 12/2/2018.
//

#ifndef INC_220FINAL_PLAYLISTLIST_H
#define INC_220FINAL_PLAYLISTLIST_H

#include "PlaylistCollection.h"
#include "List.h"

class PlaylistList : PlaylistCollection {
private:
    List* playlistList;
    int listSize;
    int playlistCount;
    void doubleCapacity();

public:
    PlaylistList();
    void addPlaylist(std::string playlistName);
    void removePlaylist(std::string name);
    PlaylistList getPlaylist(std::string name);
};


#endif //INC_220FINAL_PLAYLISTLIST_H
