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
    character(int, std::string s="standart");
    bool operator<(int);
    character operator+(character&);
    int operator+(int);
    friend bool operator!(const character&);
    friend int operator+(int, character&);
    character& operator+=(const character&);
    character& operator++();
    character& operator--();
    character operator++(int);
    character operator--(int);
    void heilen();
    void inDenKampf(character&);
    void getStatus() const;
};
typedef character Character;
#endif