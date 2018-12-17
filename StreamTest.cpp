//
// Created by labuser on 12/16/2018.
//
#include <sstream>
#include <iostream>
#include "Song.h"

int main() {
    std::string command;
    getline(std::cin, command);
    std::string artist;
    getline(std::cin, artist);
    std::cout << artist << std::endl;
    std::cout << "Billy Joel" << std::endl;
    std::string title;
    getline(std::cin, title);
    std::cout << title << std::endl;
    std::cout << "Piano Man" << std::endl;
    std::string dur;
    getline(std::cin, dur);
    std::stringstream ss;
    std::cout << dur << std::endl;
    std::cout << "270" << std::endl;
    std::string playCount;
    if (!(ss >> ))
    getline(std::cin, playCount);
    std::cout << playCount << std::endl;
    std::cout << "5" << std::endl;
    if (command == "add") {
        Song newSong(artist, title, dur, playCount);
        std::cout << newSong.toString() << std::endl;
    }
    std::cout << command;
    return 0;
}
