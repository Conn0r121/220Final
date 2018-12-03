//
// Created by conno on 12/2/2018.
//

#ifndef INC_220FINAL_SONGLIST_H
#define INC_220FINAL_SONGLIST_H


class SongList {
private:
    Song* songList;
    int listSize;
    int songCount;
    void doubleCapacity();
public:
    void addSong(Song songToAdd);
    void removeSong(std::string name);
    Song getSongbyName(std::string name);


};


#endif //INC_220FINAL_SONGLIST_H
