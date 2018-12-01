//
// Created by student on 11/30/2018.
//

#ifndef INC_220FINAL_INVENTORY_H
#define INC_220FINAL_INVENTORY_H

#include "PlaylistCollection.h"

class Inventory {
private:
    PlaylistCollection* master;
public:
    /**
     * reads songs from a file and adds with no duplicates
     */
    virtual void import() =0;

    /**
     * reads songs from a file and deletes songs from libray listed in the file
     */
    virtual void discontinue() =0;

    /**
     * displays the full library in alphabetical order by artist
     * @return a string
     */
    virtual std::string displayLibrary() =0;

    /**
     * displays all songs by a given artist
     * @return a string
     */
    virtual std::string displayByArtist() =0;

    /**
     * display information on a given song
     * @return a string
     */
    virtual std::string displaySong() =0;

    virtual void loadLibrary() =0;

    virtual void saveLibrary() =0;

};
#endif //INC_220FINAL_INVENTORY_H
