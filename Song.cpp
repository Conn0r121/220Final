//
// Created by Daniel McCaffrey on 11/27/18.
//
#include "Song.h"
#include <string>
#include <stdexcept>
#include <iostream>

Song::Song(const std::string artistIn, const std::string titleIn, const int durationIn, const int playCountIn) {
    artist = artistIn;
    title = titleIn;
    duration = durationIn;
    playCount = playCountIn;
}

Song::Song(){
    artist="";
    title="";
    duration=0;
    playCount=0;
}

const std::string Song::getArtist() {
    return artist;
}

const std::string Song::getTitle() {
    return title;
}

const int Song::getDuration() {
    return duration;
}

const int Song::getPlayCount() {
    return playCount;
}
std::string Song::toString() {
    std::string returnString = artist + ", " + title + ", " + std::to_string(duration) + ", " + std::to_string(playCount);
    std::cout<<returnString<<"in toString for song"<<std::endl;
    return returnString;
}

