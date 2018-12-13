//
// Created by student on 11/30/2018.
//

#ifndef INC_220FINAL_INVENTORY_H
#define INC_220FINAL_INVENTORY_H
#include <string>
#include "Song.h"
#include "List.h"
#include "PlaylistImplementation.h"
#include "PlaylistCollectionImplementation.h"
#include <fstream>
#include <iostream>

class Inventory {
private:
//    Inventory(const Inventory& invToCopy);
//    Inventory& operator=(const Inventory& invToCopy);


public:
    /**
     * constructor
     */
    Inventory() {}
    /**
     * add songs to the library
     * @param artist
     * @param title
     */
    virtual void addSongToLibrary(Song* &newSong)=0;
    /**
     * reads songs from a file and adds with no duplicates to master file
     */
    virtual void import(std::string fileName) =0;

    /**
     * reads songs from a file and deletes songs from the master file
     */
    virtual void discontinue(std::string fileIn) =0;

    /**
     * displays the full master file in alphabetical order by artist
     * @return a string
     */
    virtual std::string displayLibrary() =0;

    /**
     * displays all songs by a given artist from the master file
     * @return a string
     */
    virtual std::string displayByArtist(std::string artistName) =0;

    /**
     * display information on a given song from master file
     * @return a string
     */
    virtual std::string displaySong(std::string artist, std::string title) =0;
    /**
     * takes info from a file and populates inventory
     */

    virtual void loadLibrary() =0;
    /**
     * populates a file with song and playlist info
     */

    virtual void saveLibrary() =0;

    virtual std::string displayPlaylists()=0;

};
#endif //INC_220FINAL_INVENTORY_H
