//
// Created by Daniel McCaffrey on 11/27/18.
//
#include "Song.h"

Song::Song(const std::string artistIn, const std::string titleIn, const int durationIn, const int playCountIn) {
    artist = artistIn;
    title = titleIn;
    duration = durationIn;
    playCount = playCountIn;
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