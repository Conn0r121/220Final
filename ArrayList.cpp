//
// created by Connor Robinson 10/18/18
//
#include <stdexcept>
#include <string>
#include <iostream>
#include "ArrayList.h"
#include "Song.h"

ArrayList::ArrayList(int initialCapacity){
    if(initialCapacity<1){
        throw std::invalid_argument( "size must be greater than 1");
    }
    array = new Song*[initialCapacity];
    currItemCount = 0;
    currCapacity = initialCapacity;

}

ArrayList::ArrayList(const ArrayList& arrayListToCopy) {
    this->array = new Song*[arrayListToCopy.currCapacity];
    this->currItemCount = arrayListToCopy.currItemCount;
    this->currCapacity = arrayListToCopy.currCapacity;
    for (int i =0; i <currCapacity; i++){
        array[i] = arrayListToCopy.array[i];
    }
}

ArrayList &ArrayList::operator=(const ArrayList &arrayListToCopy) {
    if(this != &arrayListToCopy){
        delete [] array;
        array=nullptr;
        array = new Song*[currCapacity];
        this->currItemCount = arrayListToCopy.currItemCount;
        this->currCapacity = arrayListToCopy.currCapacity;

        for(int i = 0; i<currItemCount; i++){
            this->array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}

ArrayList::~ArrayList(){
    delete [] array;
}

void ArrayList::doubleCapacity(){
    currCapacity*=2;
    Song** tempArray = new Song*[currCapacity];
    for(int i =0; i<currItemCount; i++) {
        tempArray[i] = array[i];
    }
    delete [] array;
    array=tempArray;
}
void ArrayList::insertAtEnd(Song* itemToAdd){
    if(currCapacity<=currItemCount){
        doubleCapacity();
    }
    array[currItemCount]=itemToAdd;
    this->currItemCount++;
}
Song* ArrayList::getValueAt(int index){
    if(index<0 || index>=currItemCount){
        throw std::out_of_range("bad argument dummy");
    }
    Song *value = this->array[index];
    return value;
}
//std::string ArrayList::toString(){
//
//    std::string returnString="{";
//    std::string tempString;
//    if(currItemCount==0){
//        return "{}";
//    }
//    for(int i=0; i<currItemCount-1; i++){
//        returnString+=std::to_string(array[i])+", ";
////        tempString=*(array+i);
////        returnString=returnString+tempString+", ";
//    }
//    //tempString=*(array+currItemCount-1);
//    returnString+=std::to_string(array[currItemCount-1])+"}";
//    //returnString=returnString+tempString+"}";
//    return returnString;
//}
bool ArrayList::isEmpty(){
    return currItemCount==0;
}
int ArrayList::itemCount(){
    return currItemCount;
}
void ArrayList::clearList(){
    currItemCount=0;
    delete this;
    //THIS NEEDS TO BE FIXED
}
//int ArrayList::find(int numToFind){
//    for(int i=0; i<currItemCount; i++){
//        if(*(array+i)==numToFind){
//            return i;
//        }
//    }
//    return -1;
//}
//int ArrayList::findLast(int numToFind){
//    for(int i=0; i<currItemCount; i++){
//        if(*(array+currItemCount-i-1)==numToFind){
//            return currItemCount-i-1;
//        }
//    }
//    return -1;
//}
//int ArrayList::findMaxIndex() {
//    int maxIndex=0;
//    if (this->isEmpty()) {
//        throw std::out_of_range("Array size must be > 0");
//    } else {
//        int maxValue = array[0];
//        for (int i = 0; i < currItemCount; i++) {
//            if (maxValue < *(array + i)) {
//                maxValue = *(array + i);
//                maxIndex = i;
//            }
//        }
//    }
//
//    return maxIndex;
//}
//void ArrayList::insertAtFront(int itemToAdd){
//    if(currItemCount>=currCapacity){
//        doubleCapacity();
//    }
//    for(int i=currItemCount; i>=0; i--){
//        array[i+1]=array[i];
//    }
//    array[0]=itemToAdd;
//    currItemCount++;
//}
//void ArrayList::insertAt(int itemToAdd, int index){
//    if(index<0 || index>currItemCount){
//        throw std::out_of_range("bad argument dummy");
//    }
//    if(currItemCount>=currCapacity){
//        doubleCapacity();
//    }
//    for(int i=currItemCount;i>=index; i--){
//        array[i+1]=array[i];
//    }
//    *(array+index)=itemToAdd;
//    currItemCount++;
//}
int ArrayList::removeValueAtEnd(){
    return removeValueAt(currItemCount-1);
}
int ArrayList::removeValueAtFront(){
    return removeValueAt(0);
}
Song* ArrayList::removeValueAt(int index){
    if(index<0 || index>currItemCount) {
        throw std::out_of_range("bad argument dummy");
    }
    Song* myReturn=array[index];
    for(int i=index; i<currItemCount-1;i++){
        array[i]=array[i+1];
    }
    currItemCount--;
    return myReturn;
}