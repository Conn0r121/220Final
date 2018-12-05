cmake_minimum_required(VERSION 3.6.1)
project(220Final)

set(CMAKE_CXX_STANDARD 14)

add_executable(220Final Song.h Song.cpp SongTest.cpp TestLib.cpp TestLib.h Inventory.h InventoryImplementation.cpp InventoryImplementation.h List.h ArrayList.h ArrayLib.h ArrayLib.cpp PlaylistImplementation.cpp)