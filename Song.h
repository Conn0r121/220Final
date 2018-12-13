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
    Song(std::string artistIn, std::string titleIn, int durationIn, int playCountIn);
    Song(std::string csvInfo);
    Song();
    const std::string getArtist();
    const std::string getTitle();
    const int getDuration();
    const int getPlayCount();
    std::string toString();
};

#endif //INC_220FINAL_SONG_H
