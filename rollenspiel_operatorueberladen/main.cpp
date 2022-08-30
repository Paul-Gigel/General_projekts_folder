#include <iostream>
#include "rollenspiel.h"

using namespace std;

int main()  {
    character einHeld("held", 20, 5);
    character guteHexe("guteHexe", 10, 11);
    character Allianz = einHeld + guteHexe;
    Character einBoesewicht("bösewicht", 18, 15);
    einHeld.inDenKampf(einBoesewicht);
    for (character i = 100; i>0; i--) {
        std::cout<<i;
    }
    einHeld += guteHexe;
    std::cout<<(einHeld==einHeld)<<std::endl;
    int ival{einHeld};
    character* ref = new character(15);
    std::cout<<einHeld<<std::endl;
    std::cin>>einBoesewicht;
    return 0;
}