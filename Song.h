//
// Created by Daniel McCaffrey on 11/27/18.
//

#ifndef INC_220FINAL_SONG_H
#define INC_220FINAL_SONG_H

#include <string>

class Song {
private:
    std::string artist;
    std::string title;
    int duration;
    int playCount;

public:
    Song(const std::string artistIn, const std::string titleIn, const int durationIn, const int playCountIn);
    const std::string getArtist();
    const std::string getTitle();
    const int getDuration();
    const int getPlayCount();
};

#endif //INC_220FINAL_SONG_H
