//
// Created by Jeff Page on 10/2/18.
//
#include "ArrayLib.h"
#include <string>
#include <iostream>
#include "random"

template <class T>
int binFind(const int* const arrayPtr, const int size, const T itemToFind,int& numLinesRun ) { //stub function
    numLinesRun+=4;
    if (size > 0) {
        numLinesRun+=2;
        return binFind(arrayPtr, size, itemToFind, 0, numLinesRun);
    } else {
        numLinesRun+=2;
        return -1;
    }

}
template <class T>
int binFind(const int* const arrayPtr, const int size, const T itemToFind,int startPos,int &numLinesRun ) { //tail
    if (size <= 1) {
        numLinesRun+=1;
        if (itemToFind == arrayPtr[0]) {
            numLinesRun+=2;
            return startPos;
        }
        else{
            numLinesRun+=2;
            return -1;
        }
    }
    else {
        numLinesRun+=1;
        if (size % 2 == 0) { //even
            numLinesRun+=1;
            int middleNum = size / 2;
            numLinesRun+=1;
            if (arrayPtr[middleNum] == itemToFind) {
                numLinesRun+=2;
                return startPos + middleNum;
            } else if (arrayPtr[middleNum] < itemToFind) { //right
                numLinesRun+=2;
                return binFind((arrayPtr+middleNum+1), middleNum-1, itemToFind, startPos+middleNum+1,numLinesRun);
            } else { //left
                numLinesRun+=2;
                return binFind(arrayPtr, middleNum, itemToFind, startPos,numLinesRun);
            }

        } else {//odd
            int middleNum = (size - 1) / 2;
            numLinesRun+=2;
            if (arrayPtr[middleNum] == itemToFind) {
                numLinesRun+=2;
                return (startPos + middleNum);
            } else if (arrayPtr[middleNum] > itemToFind) { //left
                numLinesRun+=2;
                return binFind(arrayPtr, middleNum, itemToFind, startPos,numLinesRun);
            } else { //right
                numLinesRun+=2;
                return binFind((arrayPtr + middleNum + 1), middleNum , itemToFind, (startPos + middleNum + 1),numLinesRun);
            }
        }
    }
}
int genRandInt(int min, int max, int& numLinesRun){
    numLinesRun += 3;
    if(min>max){
        int temp=0;
        temp=min;
        min=max;
        max=temp;
        numLinesRun+=5;

    }
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(min, max);
    numLinesRun+=4;
    return distr(eng);
}

template <class T>
std::string toString( const int* arrayPtr, int size){
    int i;
    std::string array ="{";
    if(size==1){
        array=array+std::to_string(*arrayPtr)+"}";
        return array;
    }
    else {
        for (i = 0; i < size; i++) {
            std::string temp = std::to_string(arrayPtr[i]);
            if(i==size-1) {
                array = array + temp;
            }
            else{
                array = array + temp + ", ";
            }
        }
        array = array + "}";
        return array;
    }
}
template <class T>
int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    int i;
    numLinesRun+=5;
    for(i=0;i<size;i++){
        numLinesRun+=3;
        if(arrayPtr[i]==numToFind){
            numLinesRun+=2;
            return i;
        }
    }
    numLinesRun+=2;
    i=-1;
    return i;
}
template <class T>
int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    int i;
    int num;
    bool foundNum=false;
    numLinesRun+=7;
    for(i=0;i<size;i++){
        numLinesRun+=3;
        if(arrayPtr[i]==numToFind){
            num=i;
            foundNum=true;
            numLinesRun+=3;
        }
    }
    if(foundNum){
        numLinesRun+=2;
        return num;
    }
    else{
        numLinesRun+=2;
        return -1;
    }
}
template <class T>
int findMaxIndex(const int* arrayPtr, int size, int&numLinesRun){
    int i;
    int maxIndex;
    numLinesRun+=6;
    if(size<1){
        numLinesRun+=2;
        throw std::invalid_argument("Arrays must be greater than 0");
    }
    else{
        int tempMax=arrayPtr[0]-1;
        numLinesRun+=1;
        for(i=0;i<size;i++) {
            numLinesRun+=3;
            if(arrayPtr[i]>tempMax){
                numLinesRun+=3;
                tempMax=arrayPtr[i];
                maxIndex=i;
            }
        }
        numLinesRun+=1;
        return maxIndex;
    }
}
template <class T>
T* copyArray(const T* arrayToCopy, int size, int& numLinesRun){
    T *newArray = new T[size];
    int i;
    for(i=0;i<size;i++){
        newArray[i]=arrayToCopy[i];
    }
    return newArray;
}
template <class T>
T* genShuffledArray(int size, int& numLinesRun){
    int i;
    int unusedTimer=0;
    int *newArray = new int[size];
    numLinesRun+=5;
    if(size<1){
        newArray= nullptr;
        numLinesRun+=3;
        return newArray;
    }

    for(i=0;i<size;i++){
        numLinesRun+=4;
        newArray[i]=i+1;
    }
    if(size==1){
        numLinesRun+=2;
        return newArray;
    }
    for(i=0;i<size;i++){
        numLinesRun+=7;//sets array index values to random then assigns random number in range
        int randNum=genRandInt(1,size-1,numLinesRun);
        int temp = newArray[i];
        newArray[i]=newArray[randNum];
        newArray[randNum]=temp;
    }
    numLinesRun+=1;
    return newArray;
}
template <class T>
int countOccurrences(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    int i;
    int occurrenceNum=0;
    numLinesRun+=6;
    numLinesRun+=3;
    for(i=0;i<size;i++){
        numLinesRun+=1;
        if(arrayPtr[i]==numToFind){
            occurrenceNum=occurrenceNum+1;
            numLinesRun+=2;
        }
    }
    numLinesRun+=1;
    return occurrenceNum;
}

template <class T>
int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun) {
    if (size1 + size2 < 1) {
        numLinesRun+=2;
        return nullptr;
    } else {
        int *newArray = new int[size1 + size2];
        int i=0;
        int a1Count=0;
        int a2Count=0;
        bool done=false;
        numLinesRun+=6;
        if(size1==0){ //deals with first list being size 0
            numLinesRun+=3;
            for(a2Count;a2Count<size2+1;a2Count++){
                newArray[i]=a2[a2Count];
                i+=1;
                numLinesRun+=3;
            }
            numLinesRun+=1;
            return newArray;
        }
        else if(size2==0){ //deals with second list being size 0
            numLinesRun+=4;
            for(a1Count;a1Count<size1+1;a1Count++){
                numLinesRun+=2;
                newArray[i]=a1[a1Count];
            }
            return newArray;
        }
        numLinesRun+=3;
        for (i = 0;done==false; i++) { //finishes once one list runs out
            numLinesRun+=1;
            if (a1[a1Count] > a2[a2Count]) {
                newArray[i] = a2[a2Count];
                a2Count+=1;
                numLinesRun+=3;
                if(a2Count==size2){
                    numLinesRun+=2;
                    done=true;
                }
            } else {
                numLinesRun+=3;
                newArray[i] = a1[a1Count];
                a1Count+=1;
                if(a1Count==size1){
                    numLinesRun+=2;
                    done=true;
                }
            }
        }
        if(a1Count!=size1){ //adds additional elements if a1 was largest
            numLinesRun+=4;
            for(a1Count;a1Count<size1;a1Count++){
                numLinesRun+=3;
                newArray[i]=a1[a1Count];
                i+=1;
            }
        }
        if(a2Count!=size2) {
            numLinesRun+=4;
            for (a2Count; a2Count < size2; a2Count++) { //adds additional elements if a2 was the largest
                numLinesRun+=3;
                newArray[i] = a2[a2Count];
                i+=1;
            }
        }
        numLinesRun+=1;
        return newArray;
    }
}





