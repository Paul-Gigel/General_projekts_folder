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
    character(int, std::string s="standart", int hp = 30);
    bool operator<(int);
    bool operator>(int);
    bool operator==(const character&);
    bool operator!=(const character&);
    character operator+(character&);
    int operator+(int);
    character& operator+=(const character&);
    character& operator++();
    character& operator--();
    character operator++(int);
    character operator--(int);
    explicit operator int() const;
    friend bool operator!(const character&);
    friend int operator+(int, character&);
    friend std::ostream& operator<<(std::ostream&, const character&);
    friend std::istream& operator>>(std::istream&, character&);
    friend std::ostream& operator<<(std::ostream&, const character*);
    friend std::istream& operator>>(std::istream&, character*);
    int operator()(const character&);
    void heilen();
    void inDenKampf(character&);
    void getStatus() const;
};
typedef character Character;
#endif