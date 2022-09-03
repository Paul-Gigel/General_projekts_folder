#include <iostream>
#include <string>
#include "Audioformat.h"
#ifndef AUDIOPLAYER_ABTRACT_OGG_FORMAT_H
#define AUDIOPLAYER_ABTRACT_OGG_FORMAT_H
class Ogg_Format : public Audioformat   {
private:
    std::string song;
public:
    Ogg_Format(const std::string& s) : song(s)  {};
    void abspielen()    {
        std::cout<<song<<"  wird gerade gespielt\n";
    }
    void info() {
        std::cout<<"Der Song ist eine Ogg-Datei\n";
    }
};
#endif