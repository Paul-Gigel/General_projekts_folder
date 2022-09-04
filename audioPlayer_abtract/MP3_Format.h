#include <iostream>
#include <string>
#include "Audioformat.h"
#ifndef AUDIOPLAYER_ABTRACT_MP3_FORMAT_H
#define AUDIOPLAYER_ABTRACT_MP3_FORMAT_H
class MP3_Format : public Audioformat {
private:
    std::string song;
public:
    MP3_Format(const std::string& s) : song(s)  {};
    void abspielen() override {
        std::cout<<song<<"  wird gerade gespielt\n";
    };
    void info() override {
        std::cout<<"Der Song ist eine MP3-Datei\n";
    };
};
#endif