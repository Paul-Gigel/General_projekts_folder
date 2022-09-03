#include <iostream>
#include <string>
#include "Audioformat.h"
#include "MP3_Format.h"
#include "Ogg_Format.h"
void abspielen(Audioformat& fmt)    {
    fmt.abspielen();
}
void info(Audioformat& i)   {
    i.info();
}
int main()  {
    MP3_Format song1("test.mp3");
    abspielen(song1);
    info(song1);
    Ogg_Format song2("test.ogg");
    abspielen(song2);
    info(song2);
    Audioformat *song = new MP3_Format("test1.mp3");
    abspielen(*song);
    delete song;    //would delete only Basepart Audioformat, the drived part MP3_Format would still rot there!!!!! (solve by marking Destruktor virtual)
    return 0;
}