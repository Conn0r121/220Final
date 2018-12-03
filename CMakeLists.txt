cmake_minimum_required(VERSION 3.6.1)
project(220Final)

set(CMAKE_CXX_STANDARD 14)

add_executable(220Final Song.cpp Song.h SongTest.cpp TestLib.cpp ArrayList.cpp PlaylistCollection.h PlayList.h Inventory.h PlaylistList.cpp PlaylistList.h SongList.cpp SongList.h)