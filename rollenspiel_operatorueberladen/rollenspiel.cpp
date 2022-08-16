#include <iostream>
#include <string>
using namespace std;
#include "rollenspiel.h"

character::character(string s, int h, int m) : klasse(s), hp(h), mp(m) {
    cout<<"ein Neuer Held wurde geboren. Status : ";
    getStatus();
    cout<<endl;
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
void character::heilen() {
    hp+=10;
}
void character::inDenKampf(character &c1) {
    while (1)   {
        this->getStatus();
        cout<<"greift an!\n";
        c1.hp -= this->mp;
        if (c1.hp <=0)  {
            cout <<c1.klasse<<" hat verloren!\n";
            break;
        }

        c1.getStatus();
        cout<<"greift an!\n";
        this->hp -= c1.mp;
        if (this->hp <=0)   {
            cout<< this->klasse <<"hat verloren!\n";
            break;
        }
    }
}
void character::getStatus() const {
    cout<<klasse<<" (hp :"<<hp<<" (mp :"<<mp<<")";
}

55 F6 B7