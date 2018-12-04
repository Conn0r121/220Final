cmake_minimum_required(VERSION 3.6.1)
project(220Final)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        220Final
        Song.cpp
        List.h
        ArrayLib.cpp
        ArrayLib.h
        Song.h
        TestLib.cpp
        ArrayList.inl
        PlaylistCollection.h
        PlayList.h
        Inventory.h
        Playlist.h
        SongList.h
        PlaylistImplementation.cpp
        PlaylistImplementation.h
        PlaylistCollectionImplementation.cpp
        PlaylistCollectionImplementation.h
        InventoryImplementation.cpp
        InventoryImplementation.h
        SongTest.cpp)