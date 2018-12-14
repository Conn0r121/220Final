//
// Created by student on 12/1/2018.
//

#ifndef INC_220FINAL_PLAYLIST_H
#define INC_220FINAL_PLAYLIST_H

#include "Song.h"
#include "ArrayList.h"


class Playlist {
private:
public:
    /**
     * constructor
     */
    Playlist() {}
    /**
     * to string
     * @return string containing artist, title, duration in seconds, playcount
     */
    virtual std::string toString() =0;
    /**
     * calculates duration of entire playlist
     * @return duration of playlist
     */
    virtual int calcDuration() =0;
    /**
     * plays last song in playlist by removing it and returning it in string form
     * @return same as to string
     */
    virtual std::string playNext() =0;
    /**
     * is empty
     * @return true or false
     */
    virtual bool isEmpty() =0;
    /**
     * adds song at front playlist
     * @param artist
     * @param title
     */
    virtual void addSongAtEnd(Song* newSong) =0;
    /**
     * adds song to playlist alphabetically - necessary for the masterlist
     * @param artist
     * @param title
     */
    virtual void addSongAlphabetically(Song* newSong)=0;
    /**
     * removes song from playlist
     * @param artist
     * @param title
     */
    virtual void removeSong(std::string artist, std::string title) =0;
    /**
     * gets a song in the playlist by the postition in the playlist - good for checking every song
     * @param position
     * @return a song in the position specificd
     */
    virtual Song* getSongByPosition(int position)=0;
    /**
     * gets number of songs in the playlist
     * @return number of songs in playlist
     */
    virtual int getPlaylistSize()=0;
    /**
     *
     * @param artistIn
     * @param titleIn
     * @return song with specified parameters
     */
    virtual Song* getSongByArtistandTitle(std::string artistIn, std::string titleIn)=0;

    virtual std::string getPlaylistName()=0;

    virtual void removeSongFromPlaylist(std::string artist, std::string title) =0;

    virtual void deleteSongFromPlaylist(std::string artist, std::string title) =0;


};
#endif //INC_220FINAL_PLAYLIST_H
