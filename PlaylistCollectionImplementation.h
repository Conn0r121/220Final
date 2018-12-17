//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H
#define INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H

#include "PlaylistCollection.h"
#include "ArrayList.h"
#include "ArrayLib.h"
#include "List.h"


class PlaylistCollectionImplementation : public PlaylistCollection {
private:
    List<PlaylistImplementation *> *allPlaylists;

public:
    PlaylistCollectionImplementation(const PlaylistCollectionImplementation &playlistCollectionToCopy);

    PlaylistCollectionImplementation &operator=(const PlaylistCollectionImplementation &playlistCollectionToCopy);

    /**
     * constructor
     */
    PlaylistCollectionImplementation();

    ~PlaylistCollectionImplementation();

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
    void newPlaylist(PlaylistImplementation *newPlaylist);

    /**
     * @return an int of the playlist size
     */
    int getSize();

    /**
     *
     * @param name
     * @return a pointer of to the playlist with the given name
     */
    PlaylistImplementation *getPlaylistByName(std::string name);

    /**
     *
     * @return the name of every playlist in the collection
     */
    std::string displayAllPlaylistNames();

    PlaylistImplementation *getPlayListByLocation(int pos);

    bool isEmpty();
};


#endif //INC_220FINAL_PLAYLISTCOLLECTIONIMPLEMENTATION_H
