//
// Created by conno on 12/3/2018.
//

#ifndef INC_220FINAL_INVENTORYIMPLEMENTATION_H
#define INC_220FINAL_INVENTORYIMPLEMENTATION_H

#include "Inventory.h"
#include <string>
#include "List.h"
#include "Song.h"
#include "PlaylistImplementation.h"
#include "PlaylistCollectionImplementation.h"


class InventoryImplementation: public Inventory {
private:
    PlaylistImplementation allSongs;
    PlaylistCollectionImplementation allPlaylists;



public:
    InventoryImplementation();

    void addSongToLibrary(Song* &newSong);
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
    std::string displaySong(std::string artist, std::string title);

    void loadLibrary();

    void saveLibrary();
};


#endif //INC_220FINAL_INVENTORYIMPLEMENTATION_H
