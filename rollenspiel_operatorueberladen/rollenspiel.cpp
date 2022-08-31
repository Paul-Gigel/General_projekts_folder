#include <iostream>
#include <string>
using namespace std;
#include "rollenspiel.h"

Character::character(string s, int h, int m) : klasse(s), hp(h), mp(m) {
    cout<<"ein Neuer Held wurde geboren. Status : ";
    getStatus();
    cout<<endl;
}
Character::character(int n, std::string s, int hp): klasse(s), mp(n), hp(hp) {};
bool character::operator<(int n) {
    return mp<n;
}
bool character::operator>(int n) {
    return mp>n;
}
int character::operator+(int n) {
    return hp + n;
}
int operator+(int lOperand, character& rOperand)  {
    return lOperand + rOperand.hp;
}
bool character::operator==(const character& c) {
    return ((c.klasse == this->klasse)&&(c.hp == this->hp)&&(c.mp == this->mp));
};
bool character::operator!=(const character& c) {
    return ((c.klasse != this->klasse)||(c.hp != this->hp)||(c.mp != this->mp));
};
bool operator!(const character& c)    {
    return (c.hp <=0);
}
character character::operator+(character &c) {
    character Allianz("Allianz", this->hp+c.hp, this->mp+c.mp);
    cout<< this->klasse<<" und "<< c.klasse<<" haben eine Allianz gegründet\n";
    return Allianz;
}
character& character::operator+=(const character &c) {
    this->hp +=c.hp;
    this->mp +=c.mp;
    cout<< this->klasse <<" erhält die HP und MP con "<<c.klasse<<"\n";
    return *this;
}
character& character::operator++() {
    mp++;
    return *this;
}
character& character::operator--() {
    if (mp >0) mp--;
    return *this;
}
character character::operator++(int) {
    character tmp = *this;
    ++this->mp;
    return tmp;
};
character character::operator--(int) {
    character tmp = *this;
    if (tmp.mp >0) --this->mp;
    return tmp;
};
character::operator int() const {
    return hp;
}
std::ostream& operator<<(std::ostream& os, const character& c)  {
    os<<c.klasse<<'/'<<c.hp<<'/'<<c.mp;
    return os;
}
std::istream& operator>>(std::istream& is, character& c)  {
    std::cout<<"Hp      : "; is>>c.hp;
    std::cout<<"Mp      : "; is>>c.mp;
    std::cout<<"klasse  : "; is>>c.klasse;

    return is;
}
std::ostream& operator<<(std::ostream& os, const character* c)  {
    os<<c->klasse<<'/'<<c->hp<<'/'<<c->mp;
    return os;
}
std::istream& operator>>(std::istream& is, character* c)  {
    std::cout<<"Hp      : "; is>>c->hp;
    std::cout<<"Mp      : "; is>>c->mp;
    std::cout<<"klasse  : "; is>>c->klasse;

    return is;
}
int character::operator()(const character& c)  {
    return mp-c.mp;
}
void character::heilen() {
    hp+=10;
}
void character::inDenKampf(character &c1) {
    while (1)   {
        this->getStatus();
        cout<<"greift an!\n";
        c1.hp -= this->mp;
        if (!c1)  {
            cout <<c1.klasse<<" hat verloren!\n";
            break;
        }

        c1.getStatus();
        cout<<"greift an!\n";
        this->hp -= c1.mp;
        if (!this)   {
            cout<< this->klasse <<"hat verloren!\n";
            break;
        }
    }
}
void character::getStatus() const {
    cout<<klasse<<" (hp :"<<hp<<" (mp :"<<mp<<")";
}