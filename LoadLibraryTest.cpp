//
// Created by Jeff Page on 12/12/18.
//

#include "Song.h"
#include "InventoryImplementation.h"
#include "PlaylistCollectionImplementation.h"
#include "PlaylistImplementation.h"

void LibraryTest(){
    InventoryImplementation *newInventory = new InventoryImplementation();
    newInventory->loadLibrary();
    std::cout<<newInventory->displayLibrary()<<std::endl;
    std::cout<<"\n"<<std::endl;
    newInventory->import("importTest.txt");
    std::cout<<"Testing Import"<<std::endl;
    std::cout<<newInventory->displayLibrary()<<std::endl;
    std::cout<<"Testing discontinue"<<std::endl;
    newInventory->discontinue("Discontinue.txt");
    std::cout<<"\n"<<std::endl;
    std::cout<<newInventory->displayLibrary()<<std::endl;
    newInventory->saveLibrary();

}
int main(){
    LibraryTest();
    return 0;
}