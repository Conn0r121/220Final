//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H
#define INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H

#include "PlaylistCollection.h"
#include "List.h"

class PlaylistCollectionImplementation:public PlaylistCollection {
private:
    List<Playlist*>* playlistList;

public:
    PlaylistCollectionImplementation();

    PlaylistCollectionImplementation(int initialCapacity);

    std::string displayAll();

    std::string displayPlaylist(std::string playlistToFind);

    void delWhenEmpty();

    void newPlaylist();

    void newRandPlaylist();

};


#endif //INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H
