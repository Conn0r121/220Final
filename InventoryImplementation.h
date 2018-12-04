//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_INVENTORYIMPLEMENTATION_H
#define INC_220FINAL_INVENTORYIMPLEMENTATION_H

#include "Inventory.h"
#include "PlaylistCollectionImplementation.h"
#include "PlaylistImplementation.h"

class InventoryImplementation: public Inventory {
private:
    PlaylistCollectionImplementation allPlaylists;
    PlaylistImplementation allSongs;
    int totalSongCount;


public:
    /**
     * reads songs from a file and adds with no duplicates
     */
    void import();

    /**
     * reads songs from a file and deletes songs from libray listed in the file
     */
    void discontinue();

    /**
     * displays the full library in alphabetical order by artist
     * THIS NEEDS THE SONGLIST TO BE SORTED BY ARTIST
     * @return a string

     */
    std::string displayLibrary();

    /**
     * displays all songs by a given artist
     * @return a string
     */
    std::string displayByArtist(std::string artistName);

    /**
     * display information on a given song
     * @return a string
     */
    std::string displaySong(std::string songName);

    void loadLibrary();

    void saveLibrary();
};


#endif //INC_220FINAL_INVENTORYIMPLEMENTATION_H
