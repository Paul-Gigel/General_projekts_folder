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
    Spielzeug(std::string g1, const char *g2);
    void printAll();
    void set_string(std::string str);
};

#include "../Source/Spielzeug.cpp"
#endif //CSPIELZEUG_SPIELZEUG_H
