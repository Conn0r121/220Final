cmake_minimum_required(VERSION 3.6.1)
project(220Final)

set(CMAKE_CXX_STANDARD 14)

add_executable(220Final
        Song.h
        Song.cpp
        TestLib.cpp
        TestLib.h
        Inventory.h
        InventoryImplementation.h
        InventoryImplementation.cpp
        PlaylistTest.cpp
        PlaylistCollection.h
        PlaylistCollectionImplementation.h
        PlaylistCollectionImplementation.cpp
        List.h
        ArrayList.h
        ArrayList.inl
        ArrayLib.h
        ArrayLib.cpp
        Playlist.h
        PlaylistImplementation.h
        PlaylistImplementation.cpp
        )