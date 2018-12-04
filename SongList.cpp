//
// Created by conno on 12/2/2018.
//

#include "SongList.h"
SongList::SongList(){
    listSize=5;
    songCount=0;
    songList=new Song(5);
}
//add copy constructor ad equals operator if needed
SongList::~SongList(){
    for (int i=0; i<songCount; i++){
        delete [] songList[i];
    }
}

void SongList::doubleCapacity() {
    listSize*=2;
    Song* tempList = new Song[listSize];
    for(int i =0; i<songCount; i++) {
        tempList[i] = songList[i];
    }
    delete [] songList;
    songList=tempList;
}

void SongList::addSong(Song songToAdd) {
    if(songCount==listSize){
        doubleCapacity();
    }
    songList[songCount]=songToAdd;
    songCount++;
}

void SongList::removeSong(std::string name) {
    for(int i=0; i<songCount; i++){
        if(name==songList[i].getTitle()){
            delete [] songList[i];
            for (int j=i; j<songCount; j++){
                songList[j]=songList[j+1];
            }
            songCount-=1;
        }
    }
}

Song SongList::getSongByName(std::string name) {
    for(int i=0; i<songCount; i++){
        if(name==songList[i].getTitle()){
            return songList[i];
        }
    }
}
