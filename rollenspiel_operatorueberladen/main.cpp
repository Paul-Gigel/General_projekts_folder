#include <iostream>
#include "rollenspiel.h"

using namespace std;

int main()  {
    character einHeld("held", 20, 5);
    character guteHexe("guteHexe", 10, 11);
    character Allianz = einHeld + guteHexe;
    Character einBoesewicht("bösewicht", 18, 15);
    Allianz.inDenKampf(einBoesewicht);
    for (character i = 0; i<10; i++) {

    }
    einHeld += guteHexe;
    std::cout<<einHeld+1000<<std::endl;
    std::cout<<1000+einHeld<<std::endl;

    return 0;
}