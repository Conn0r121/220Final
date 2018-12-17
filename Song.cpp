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

Song::Song(std::string csvInfo){
    unsigned long first= csvInfo.find(",");
    artist = csvInfo.substr(0,first);
    unsigned long  length = csvInfo.size();
    csvInfo=csvInfo.substr(first+2,length);
    unsigned long second = csvInfo.find(",");
    title = csvInfo.substr(0,second);
    length = csvInfo.size();
    csvInfo= csvInfo.substr(second+2,length);
    unsigned long third = csvInfo.find(",");
    length = csvInfo.size();
    duration = std::stoi(csvInfo.substr(0,third));
    csvInfo=csvInfo.substr(third+2,length);
    playCount = std::stoi(csvInfo);

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
    return returnString;
}
void Song::updatePlayCount(){
    playCount=playCount+1;
}


