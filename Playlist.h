//
// Created by student on 12/1/2018.
//

#ifndef INC_220FINAL_PLAYLIST_H
#define INC_220FINAL_PLAYLIST_H

#include "Song.h"
#include "List.h"

class Playlist : public List {
private:
    std::string title;
    List* songs;
    int duration;

public:
    virtual std::string toString() =0;
    virtual void calcDuration() =0;
    virtual std::string playNext() =0;
    virtual bool isEmpty() =0;
    virtual void addSong() =0;
    virtual void removeSong() =0;
};
#endif //INC_220FINAL_PLAYLIST_H
