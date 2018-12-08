//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H
#define INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H

#include "PlaylistCollection.h"

class PlaylistCollectionImplementation:public PlaylistCollection {
private:
    List<Playlist*>* allPlaylists;
public:
    /**
     * constructor
     */
    PlaylistCollectionImplementation();
    /**
     * lists all the playlist names
     * @return a string of all the playlist names, line by line
     */

    std::string displayAll();
    /**
     * finds a specific playlist and tostrings it
     * @param playlistToFind
     * @return
     */

    std::string displayPlaylist(std::string playlistToFind);
    /**
     * auto deletes a playlist if its empty
     */

    void delWhenEmpty();
    /**
     * creates a new playlist
     */

    void newPlaylist();
    /**
     * i honestly dont know what this is supposed todo
     */

    void newRandPlaylist();

};


#endif //INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H
