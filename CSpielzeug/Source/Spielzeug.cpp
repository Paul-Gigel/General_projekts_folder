#include "../Headers/Spielzeug.h"
#include <cstring>
Spielzeug::Spielzeug():gegenstand01("0")
{
    gegenstand02 = new char[5];
}
Spielzeug::Spielzeug(std::string g1, const char *g2):gegenstand01(g1)
{
    gegenstand02 = new char[strlen(g2) +1];
    strcpy(gegenstand02, g2);
}
Spielzeug::Spielzeug(const Spielzeug &spielzeug)
{
    gegenstand01 = spielzeug.gegenstand01;
    gegenstand02 = new char [strlen(spielzeug.gegenstand02)+1];
    strcpy(gegenstand02, spielzeug.gegenstand02);
}
Spielzeug::~Spielzeug()
{
    delete gegenstand02;
    std::cout <<"deleted"<<std::endl;
}

Spielzeug Spielzeug::operator=(const Spielzeug &s) {
    gegenstand01 = s.gegenstand01;
    gegenstand02 = new char[strlen(s.gegenstand02) +1];
    strcpy(gegenstand02, s.gegenstand02);
    return *this;
}
void Spielzeug::printAll()
{
    std::cout<<gegenstand01<<std::endl;
    std::cout<<gegenstand02<<std::endl;
};
void Spielzeug::set_string(std::string str)
{
    gegenstand01 =str;
}
void Spielzeug::tauschMich(Spielzeug *spielzeug)
{
    Spielzeug temp = *spielzeug;
    *spielzeug = *this;
    *this = temp;
}