//
// Created by Jeff Page on 10/16/18.
//

#include "ArrayLib.h"
#include <iostream>
#include "ArrayList.h"


//int numLinesRun=0;
//template <class T>
//void ArrayList<T>::doubleCapacity() {
//    T* newArray = ::copyArray(this->ourList,currCapacity*2,numLinesRun);
//    this->currCapacity=currCapacity*2;
//    delete [] this->ourList;
//    this->ourList = newArray;
//}

template <class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    if(initialCapacity<1){
        throw std::invalid_argument( "Size Must be Greater than 0" );
    }
    else {
        this->currItemCount = 0;
        this->currCapacity = initialCapacity;
        ourList = new T*[initialCapacity];
    }
}
template <class T>
ArrayList<T>::ArrayList(const ArrayList& arrayListToCopy) {
    this->currItemCount=arrayListToCopy.currItemCount;
    this->currCapacity=arrayListToCopy.currCapacity;
    this->ourList= new T[arrayListToCopy.currCapacity];
    for(int i=0;i<currItemCount;i++){
        this->ourList[i]=arrayListToCopy.ourList[i];
    }
}
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy){
    if(this!=&arrayListToCopy) {
        delete[] this->ourList;
        this->ourList = nullptr;
        this->currCapacity = arrayListToCopy.currCapacity;
        this->ourList = new T[arrayListToCopy.currCapacity];
        for (int i = 0; i < currItemCount; i++) {
            this->ourList[i] = arrayListToCopy.ourList[i];
        }
        this->currItemCount = arrayListToCopy.currItemCount;
    }

    return *this;
}
template <class T>
ArrayList<T>::~ArrayList() {
    delete [] this->ourList;
    this->ourList = nullptr;
}
template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd){
    if(currItemCount==currCapacity){
        //double capacity;
    }
    std::cout<<itemToAdd<<"  in insertAtEnd in ArraylistInl"<<std::endl;
    ourList[currItemCount]=itemToAdd;
    //TODO this is the issue currently, item to add is a song and im trying to put it into ourlist, but from the print statement
    //TODO a different memory address is being added if i add &, and the list wont let me use it as is. ASK TOBY ABOUT THIS ISSUE
    std::cout<<ourList[currItemCount]<<"  IN the arrayList"<<std::endl;
    currItemCount++;
}
template <class T>
T ArrayList<T>::getValueAt(int index){
    if(index>=currItemCount || index<0){
        throw std::out_of_range( "Out of Range" );
    }
    else{
        T returnObject = *ourList[index];
        return returnObject;

    }
}
template <class T>
bool ArrayList<T>::isEmpty(){
    if(currItemCount==0){
        return true;
    }
    else{
        return false;
    }
}
template <class T>
int ArrayList<T>::itemCount(){
    return currItemCount;
}
template <class T>
void ArrayList<T>::clearList(){
    currItemCount=0;
}
//template <class T>
//T ArrayList<T>::find(T itemToFind){
//    return ::find(ourList,currItemCount,itemToFind,numLinesRun);
//}
//template <class T>
//T ArrayList<T>::findLast(T itemToFind){
//    return ::findLast(ourList,currItemCount,itemToFind,numLinesRun);
//}
//template <class T>
//int ArrayList<T>::findMaxIndex(){
//    if(currItemCount<1){
//        throw std::out_of_range("Arrays must be greater than 0");
//    }
//    else {
//        return ::findMaxIndex(ourList, currItemCount, numLinesRun);
//    }
//}

template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd){
    insertAt(itemToAdd,0);

}
template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index){
    if(index<0 || index>currItemCount){
        throw std::out_of_range( "Out of Range" );
    } else {
        currItemCount += 1;
        if(currItemCount>currCapacity){
//            doubleCapacity();
        }
        for (int i = currItemCount; i > -1; i--) {
            if (i < index) {
                ourList[i] = ourList[i];
            }
            if (i == index) {
                ourList[i] = &itemToAdd;
            }
            if (i > index) {
                ourList[i] = ourList[i -1 ];
            }
        }
    }
}
template <class T>
T ArrayList<T>::removeValueAtEnd(){
    return removeValueAt(currItemCount-1);
}
template <class T>
T ArrayList<T>::removeValueAtFront(){
    return removeValueAt(0);
}
template <class T>
T ArrayList<T>::removeValueAt(int index){
    if(currItemCount<1){
        throw std::out_of_range("Cannot remove anything from an empty list");
    }
    else {
        T tempNum = *ourList[index];
        for (int i = index; i < currItemCount - 1; ++i) {
            *ourList[i] = *ourList[i + 1];
        }
        currItemCount = currItemCount - 1;
        return tempNum;
    }
}


