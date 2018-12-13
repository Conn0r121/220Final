//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_PLAYLISTIMPLEMENTATION_H
#define INC_220FINAL_PLAYLISTIMPLEMENTATION_H

#include "Playlist.h"


class PlaylistImplementation: public Playlist {
private:
    List<Song*>* songList;
    std::string playlistName;
    int duration;

public:
    /**
     * constructor
     */
    PlaylistImplementation();


    PlaylistImplementation(std::string name);

    std::string toString();

    int calcDuration();

    std::string playNext();

    bool isEmpty();

    void addSongAtEnd(Song* &newSong);

    void addSongAlphabetically(Song* &newSong);

    void removeSong(std::string artist, std::string title);

    Song* getSongByPosition(int position);

    int getPlaylistSize();

    Song* getSongByArtistandTitle(std::string artistIn, std::string titleIn);

    std::string getPlaylistName();

    bool songPresent(std::string songIn);

};


#endif //INC_220FINAL_PLAYLISTIMPLEMENTATION_H
