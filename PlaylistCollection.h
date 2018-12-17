//
// Created by student on 12/1/2018.
//

#ifndef INC_220FINAL_PLAYLISTCOLLECTION_H
#define INC_220FINAL_PLAYLISTCOLLECTION_H

#include "ArrayList.h"
#include "PlaylistImplementation.h"
#include "Song.h"
#include "Playlist.h"




class PlaylistCollection {
private:
    PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);
    PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy);

public:

    PlaylistCollection() {}

    ~PlaylistCollection() {}

    virtual std::string displayPlaylist(std::string playlistToFind) =0;

    virtual void newPlaylist(PlaylistImplementation *newPlaylist) =0;

    virtual PlaylistImplementation* getPlaylistByName(std::string name)=0;

    virtual std::string displayAllPlaylistNames()=0;

    virtual int getSize()=0;

    virtual PlaylistImplementation* getPlayListByLocation(int pos)=0;

    virtual bool isEmpty() =0;


};
#endif //INC_220FINAL_PLAYLISTCOLLECTION_H
