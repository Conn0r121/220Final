//
// Created by Jeff Page on 10/16/18.
//

#include "ArrayLib.h"
#include "ArrayList.h"
#include <string>
#include <iostream>

int numLinesRun=0;
template <class T>
void ArrayList<T>::doubleCapacity() {
    T* newArray=::copyArray(this->array,currCapacity*2,numLinesRun);
    this->currCapacity=currCapacity*2;
    delete [] this->array;
    this->array = newArray;
}
template <class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    if(initialCapacity<1){
        throw std::invalid_argument( "Size Must be Greater than 0" );
    }
    else {
        this->currItemCount = 0;
        this->currCapacity = initialCapacity;
        this->array = new T[initialCapacity];
    }
}
template <class T>
ArrayList<T>::ArrayList(const ArrayList& arrayListToCopy) {
    this->currItemCount=arrayListToCopy.currItemCount;
    this->currCapacity=arrayListToCopy.currCapacity;
    this->array= new T[arrayListToCopy.currCapacity];
    for(int i=0;i<currItemCount;i++){
        this->array[i]=arrayListToCopy.array[i];
    }
}
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy){
    if(this!=&arrayListToCopy) {
        delete[] this->array;
        this->array = nullptr;
        this->currCapacity = arrayListToCopy.currCapacity;
        this->array = new T[arrayListToCopy.currCapacity];
        for (int i = 0; i < currItemCount; i++) {
            this->array[i] = arrayListToCopy.array[i];
        }
        this->currItemCount = arrayListToCopy.currItemCount;
    }

    return *this;
}
template <class T>
ArrayList<T>::~ArrayList() {
    delete [] this->array;
    this->array = nullptr;
}
template <class T>
void ArrayList::insertAtEnd(int itemToAdd){
    insertAt(itemToAdd,currItemCount);
}
template <class T>
int ArrayList::getValueAt(int index){
    if(index>=currItemCount || index<0){
        throw std::out_of_range( "Out of Range" );
    }
    else{
        return array[index];
    }
}
template <class T>
std::string ArrayList::toString(){
    return ::toString(array,currItemCount);
}
template <class T>
bool ArrayList::isEmpty(){
    if(currItemCount==0){
        return true;
    }
    else{
        return false;
    }
}
template <class T>
int ArrayList::itemCount(){
    return currItemCount;
}
template <class T>
void ArrayList::clearList(){
    currItemCount=0;
}
template <class T>
int ArrayList::find(int numToFind){
    return ::find(array,currItemCount,numToFind,numLinesRun);
}
template <class T>
int ArrayList::findLast(int numToFind){
    return ::findLast(array,currItemCount,numToFind,numLinesRun);
}
template <class T>
int ArrayList::findMaxIndex(){
    if(currItemCount<1){
        throw std::out_of_range("Arrays must be greater than 0");
    }
    else {
        return ::findMaxIndex(array, currItemCount, numLinesRun);
    }
}
template <class T>
void ArrayList::insertAtFront(int itemToAdd){
    insertAt(itemToAdd,0);
}
template <class T>
void ArrayList::insertAt(int itemToAdd, int index){
    if(index<0 || index>currItemCount){
        throw std::out_of_range( "Out of Range" );
    }
    else {
        currItemCount += 1;
        if(currItemCount>currCapacity){
            doubleCapacity();
        }
        for (int i = currItemCount; i > -1; i--) {
            if (i < index) {
                this->array[i] = this->array[i];
            }
            if (i == index) {
                this->array[i] = itemToAdd;
            }
            if (i > index) {
                this->array[i] = this->array[i -1 ];
            }
        }
    }
}
template <class T>
int ArrayList::removeValueAtEnd(){
    return removeValueAt(currItemCount-1);
}
template <class T>
int ArrayList::removeValueAtFront(){
    return removeValueAt(0);
}
template <class T>
int ArrayList::removeValueAt(int index){
    if(currItemCount<1){
        throw std::out_of_range("Cannot remove anything from an empty list");
    }
    else {
        int tempNum = array[index];
        for (int i = index; i < currItemCount - 1; ++i) {
            array[i] = array[i + 1];
        }
        currItemCount = currItemCount - 1;
        return tempNum;
    }
}



