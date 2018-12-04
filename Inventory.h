//
// Created by student on 11/30/2018.
//

#ifndef INC_220FINAL_INVENTORY_H
#define INC_220FINAL_INVENTORY_H
#include <string>
#include "Song.h"

class Inventory {
private:
    Inventory(const Inventory& invToCopy);
    Inventory& operator=(const Inventory& invToCopy);

public:
    virtual void addSongToLibrary(Song songIn)=0;
    /**
     * reads songs from a file and adds with no duplicates to master file
     */
    virtual void import() =0;

    /**
     * reads songs from a file and deletes songs from the master file
     */
    virtual void discontinue() =0;

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
    virtual std::string displaySong() =0;

    virtual void loadLibrary() =0;

    virtual void saveLibrary() =0;

};
#endif //INC_220FINAL_INVENTORY_H
