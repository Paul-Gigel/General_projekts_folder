//
// Created by paul on 15.06.22.
//

#ifndef CSPIELZEUG_SPIELZEUG_H
#define CSPIELZEUG_SPIELZEUG_H
#include <iostream>
#include <string>
class Spielzeug
{
private:
    std::string gegenstand01;
    char *gegenstand02;
public:
    Spielzeug();
    Spielzeug(std::string g1, const char *g2);
    Spielzeug(const Spielzeug &spielzeug);
    ~Spielzeug();
    Spielzeug& operator = (const Spielzeug &s);
    void printAll();
    void set_string(std::string str);
    void tauschMich(Spielzeug *spielzeug);
};

#include "../Source/Spielzeug.cpp"
#endif //CSPIELZEUG_SPIELZEUG_H
