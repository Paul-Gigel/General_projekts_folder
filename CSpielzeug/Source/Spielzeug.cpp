#include "../Headers/Spielzeug.h"
#include <cstring>
Spielzeug::Spielzeug(std::string g1, const char *g2):gegenstand01(g1)
{
    gegenstand02 = new char[strlen(g2) +1];
    strcpy(gegenstand02, g2);
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
//void Spielzeug::set_chararray(char)