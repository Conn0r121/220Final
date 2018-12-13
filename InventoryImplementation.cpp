//
// Created by conno on 12/3/2018.
//

#include "InventoryImplementation.h"

InventoryImplementation::InventoryImplementation() {
    PlaylistImplementation *allSongs = new PlaylistImplementation();
    PlaylistCollectionImplementation *allPlaylists = new PlaylistCollectionImplementation();
}

void InventoryImplementation::addSongToLibrary(Song *&newSong) {
    allSongs.addSongAlphabetically(newSong);
}

void InventoryImplementation::discontinue() {
//TODO
}

std::string InventoryImplementation::displayLibrary() {
    return allSongs.toString();

}

std::string InventoryImplementation::displayByArtist(std::string artistName) {
    std::string returnString = "";
    for (int i = 0; i < allSongs.getPlaylistSize(); i++) {
        if (allSongs.getSongByPosition(i)->getArtist() == artistName) {
            returnString += allSongs.getSongByPosition(i)->toString() + "\n";
        }
    }
    return returnString;
}

std::string InventoryImplementation::displaySong(std::string artist, std::string title) {
    for (int i = 0; i < allSongs.getPlaylistSize(); i++) {
        if (allSongs.getSongByPosition(i)->getArtist() == artist &&
            allSongs.getSongByPosition(i)->getTitle() == title) {
            return allSongs.getSongByPosition(i)->toString();
        }
    }
    return "No Songs to Display";
}

void InventoryImplementation::loadLibrary() {
    std::string readFile ="Library.txt";
    std::ifstream infile;
    infile.open(readFile);
    if (!infile) {
        std::cerr << "Unable to open file datafile.txt";
        exit(1);
    }
    try {

        while (!infile.eof()) {
            std::string song;
            getline(infile, song);
            std::cout << song << std::endl;
            Song *mySong = new Song(song);
            allSongs.addSongAlphabetically(mySong);
        }
    }
    catch (std::out_of_range){

    }
    infile.close();
}

void InventoryImplementation::saveLibrary() {
    std::string fileName = "Library.txt";
    std::ofstream out(fileName);
    std::string line;
    for(int i=0;i<allSongs.getPlaylistSize();i++){
        line=allSongs.getSongByPosition(i)->toString();
        if(out){
            out << line << std::endl;
        }
    } out.close();
}
void InventoryImplementation::import(std::string fileName) {
//TODO
    std::ifstream songsToAdd;
    songsToAdd.open(fileName);
    std::string line;
    while (std::getline(songsToAdd, line)) {
        std::cout << line;
    }
    songsToAdd.close();
}

