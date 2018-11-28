//
// Created by Daniel McCaffrey on 11/27/18.
//
#include "Song.h"
#include "TestLib.h"

void songTest() {
    //creating songs (stack)
    Song* song1 = new Song("Billy Joel", "Piano Man", 270, 71354643);
    Song* song2 = new Song("Miley Cyrus", "Party in the USA", 202, 100275463);
    Song* song3 = new Song("Metallica", "Enter Sandman", 332, 87264930);
    Song* song4 = new Song("Earth Wind and Fire", "September", 215, 116435849);

    //testing getArtist
    printAssertEquals("Billy Joel", song1->getArtist());
    printAssertEquals("Miley Cyrus", song2->getArtist());
    printAssertEquals("Metallica", song3->getArtist());
    printAssertEquals("Earth Wind and Fire", song4->getArtist());

    //testing getTitle
    printAssertEquals("Piano Man", song1->getTitle());
    printAssertEquals("Party in the USA", song2->getTitle());
    printAssertEquals("Enter Sandman", song3->getTitle());
    printAssertEquals("September", song4->getTitle());

    //testing getDuration
    printAssertEquals(270, song1->getDuration());
    printAssertEquals(202, song2->getDuration());
    printAssertEquals(332, song3->getDuration());
    printAssertEquals(215, song4->getDuration());

    //testing getPlayCount
    printAssertEquals(71354643, song1->getPlayCount());
    printAssertEquals(100275463, song2->getPlayCount());
    printAssertEquals(87264930, song3->getPlayCount());
    printAssertEquals(116435849, song4->getPlayCount());
};

int main() {
    songTest();
    return 0;
}