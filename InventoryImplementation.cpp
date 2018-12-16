//
// Created by conno on 12/3/2018.
//

#include "InventoryImplementation.h"
#include <cstdlib>
#include <ctime>


InventoryImplementation::InventoryImplementation() {
    PlaylistImplementation *allSongs = new PlaylistImplementation();
    PlaylistCollectionImplementation *allPlaylists = new PlaylistCollectionImplementation();
}

void InventoryImplementation::addSongToLibrary(Song *&newSong) {
    allSongs.addSongAlphabetically(newSong);
}

std::string InventoryImplementation::displayLibrary() {
    return allSongs.toString();

}
std::string InventoryImplementation::displayPlaylists(){
    return allPlaylists.displayAll();

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
    std::string song;
    if (!infile) {
        std::cerr << "Unable to open file file";
        exit(1);
    }
    try {

        while (!infile.eof()) {
            if(song!="-"){
                getline(infile, song);
            }
            if(song=="-"){
                std::string playList;
                getline(infile,playList);
                PlaylistImplementation *myPlaylist = new PlaylistImplementation(playList);
                std::string nextLine;
                getline(infile,nextLine);
                while(nextLine!="-"){
                    Song mySong = Song(nextLine);
                    myPlaylist->addSongAlphabetically(allSongs.getSongByArtistandTitle(mySong.getArtist(),mySong.getTitle()));
                    getline(infile,nextLine);
                }
                allPlaylists.newPlaylist(myPlaylist);
            }
            else {
                Song *mySong = new Song(song);
                allSongs.addSongAlphabetically(mySong);
            }
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

    }
    for(int i=0;i<allPlaylists.getSize();i++){
        out<<"-"<<std::endl;
        out<<allPlaylists.getPlayListByLocation(i)->getPlaylistName()<<std::endl;
        out<<allPlaylists.getPlayListByLocation(i)->toString()<<std::endl;
    }
    out<<"-"<<std::endl;
    out.close();
}
void InventoryImplementation::import(std::string fileName) {
    std::ifstream infile;
    infile.open(fileName);
    if (!infile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    try {
        while (!infile.eof()) {
            std::string song;
            getline(infile, song);
            if(allSongs.songPresent(song)){
                std::cout<<song<<" is already present ya dingus"<<std::endl;
            }
            else{
                Song *mySong = new Song(song);
                allSongs.addSongAlphabetically(mySong);
            }
        }
    }
    catch (std::out_of_range){
    }
    infile.close();
}
void InventoryImplementation::discontinue(std::string fileIn){
    std::ifstream infile;
    infile.open(fileIn);
    if (!infile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    try {
        while (!infile.eof()) {
            std::string song;
            getline(infile,song);
            if(!allSongs.songPresent(song)){
                std::cout<< song << " is not in library!" <<std::endl;
            }
            if (allSongs.songPresent(song)){
                Song mySong = Song(song);
                removeSongFromLibrary(mySong.getArtist(),mySong.getTitle());
            }
        }
    }
    catch (std::out_of_range){
    }
    infile.close();
}

PlaylistImplementation* InventoryImplementation::getAllSongs() {
    return &allSongs;
}

PlaylistCollectionImplementation* InventoryImplementation::getAllPlaylists() {
    return &allPlaylists;
}

void InventoryImplementation::removeSongFromLibrary(std::string artist, std::string title){
    //this loop goes through each playlist
    for(int i=0; i>allPlaylists.getSize(); i++){
        //this removes the song from the playlist
        allPlaylists.getPlayListByLocation(i)->removeSongFromPlaylist(artist, title);
    }
    //this removes it from the master library
    allSongs.deleteSongFromPlaylist(artist, title);
}
PlaylistImplementation * InventoryImplementation::genRandPlaylist(std::string name, int duration){
    srand(time(NULL));
    PlaylistImplementation * myPlaylist= new PlaylistImplementation("TempList");
    for(int i=0;i<allSongs.getPlaylistSize();i++){
        myPlaylist->addSongAlphabetically(allSongs.getSongByPosition(i));
    }
    for(int i=0;i<myPlaylist->getPlaylistSize();i++){
        int r = (rand() % myPlaylist->getPlaylistSize());
        Song * tempSong = myPlaylist->getSongByPosition(i);
        Song * nextTemp = myPlaylist->getSongByPosition(r);
        myPlaylist->setSongAt(nextTemp,i);
        myPlaylist->setSongAt(tempSong,r);
    }
    int myDuration=0;
    int breakpoint;
    for(int i=0;i<myPlaylist->getPlaylistSize();i++){
        myDuration=myDuration+myPlaylist->getSongByPosition(i)->getDuration();
        if(myDuration>duration){
            breakpoint=i;
            break;
        }
    }
    PlaylistImplementation * myFinalPlaylist = new PlaylistImplementation(name);
    for(int i=0;i<breakpoint;i++){
        myFinalPlaylist->addSongAtEnd(myPlaylist->getSongByPosition(i));
    }
    allPlaylists.newPlaylist(myFinalPlaylist);
    std::cout<<myFinalPlaylist->toString()<<std::endl;
    delete myPlaylist;
    myPlaylist = nullptr;

}


