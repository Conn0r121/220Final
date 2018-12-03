//
// Created by conno on 12/2/2018.
//

#include "PlaylistList.h"
//
// Created by conno on 12/2/2018.
//

#include "SongList.h"
PlaylistList::PlaylistList(){
    listSize=5;
    playlistCount=0;
    playlistList=new Song[5];
}
//add copy constructor ad equals operator if needed
PlaylistList::~PlaylistList(){
    for (int i=0; i<playlistCount; i++){
        delete [] playlistList[i];
    }
}

void PlaylistList::doubleCapacity() {
    listSize*=2;
    Playlist* tempList = new Playlist[listSize];
    for(int i =0; i<playlistCount; i++) {
        tempList[i] = playlistList[i];
    }
    delete [] playlistList;
    playlistList=tempList;
}

void PlaylistList::addPlaylist(Playlist songToAdd) {
    if(playlistCount==listSize){
        doubleCapacity();
    }
    playlistList[songCount]=playlistToAdd;
    playlistCount++;
}

void PlaylistList::removePlaylist(std::string name) {
    for(int i=0; i<playlistCount; i++){
        if(name==playlistList[i].getTitle()){
            delete [] playlistList[i];
            for (int j=i; j<playlistCount; j++){
                playlistList[j]=playlistList[j+1];
            }
            playlistCount-=1;
        }
    }
}

Playlist PlaylistList::getPlaylistByName(std::string name) {
    for(int i=0; i<playlistCount; i++){
        if(name==playlistList[i].getTitle()){
            return playlistList[i];
        }
    }
}
