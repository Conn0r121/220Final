//
// Created by Jeff Page on 10/2/18.
//
#include "ArrayLib.h"
#include <string>
#include <iostream>
#include "random"


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


//template <class T>
//int find(const T* arrayPtr, int size, T numToFind, int& numLinesRun){
//    int i;
//    numLinesRun+=5;
//    for(i=0;i<size;i++){
//        numLinesRun+=3;
//        if(arrayPtr[i]==numToFind){
//            numLinesRun+=2;
//            return i;
//        }
//    }
//    numLinesRun+=2;
//    i=-1;
//    return i;
//}
//template <class T>
//int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
//    int i;
//    int num;
//    bool foundNum=false;
//    numLinesRun+=7;
//    for(i=0;i<size;i++){
//        numLinesRun+=3;
//        if(arrayPtr[i]==numToFind){
//            num=i;
//            foundNum=true;
//            numLinesRun+=3;
//        }
//    }
//    if(foundNum){
//        numLinesRun+=2;
//        return num;
//    }
//    else{
//        numLinesRun+=2;
//        return -1;
//    }
//}
//template <class T>
//int findMaxIndex(const int* arrayPtr, int size, int&numLinesRun){
//    int i;
//    int maxIndex;
//    numLinesRun+=6;
//    if(size<1){
//        numLinesRun+=2;
//        throw std::invalid_argument("Arrays must be greater than 0");
//    }
//    else{
//        int tempMax=arrayPtr[0]-1;
//        numLinesRun+=1;
//        for(i=0;i<size;i++) {
//            numLinesRun+=3;
//            if(arrayPtr[i]>tempMax){
//                numLinesRun+=3;
//                tempMax=arrayPtr[i];
//                maxIndex=i;
//            }
//        }
//        numLinesRun+=1;
//        return maxIndex;
//    }
//}

template <class T>
T copyArray(const T arrayToCopy, int size, int& numLinesRun){
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

