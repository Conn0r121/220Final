//
// Created by student on 12/1/2018.
//

#ifndef INC_220FINAL_PLAYLIST_H
#define INC_220FINAL_PLAYLIST_H

#include "Song.h"
#include "ArrayList.h"
#include "List.h"

class Playlist {
private:
    Playlist(const Playlist& playlistToCopy);
    Playlist& operator=(const Playlist& playlistToCopy);

public:
    Playlist() {}
    virtual std::string toString() =0;
    virtual void calcDuration() =0;
    virtual std::string playNext() =0;
    virtual bool isEmpty() =0;
    virtual void addSong(std::string artist, std::string title) =0;
    virtual void removeSong(std::string artist, std::string title) =0;
    virtual Song* getSongByPosition(int position)=0;
    virtual int getPlaylistSize()=0;
    virtual Song* getSongByArtistandTitle(std::string artistIn, std::string titleIn)=0;
    virtual std::string getName() =0;
};
#endif //INC_220FINAL_PLAYLIST_H
