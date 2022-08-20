#include <iostream>
#include <string>

#ifndef rollenspiel_h
#define rollenspiel_h
class character {
private:
    std::string klasse;
    int hp;
    int mp;
public:
    character(std::string, int, int);
    character operator+(character&);
    character& operator+=(const character&);
    void heilen();
    void inDenKampf(character&);
    void getStatus() const;
};
#endif