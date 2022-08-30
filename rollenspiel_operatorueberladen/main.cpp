#include <iostream>
#include "rollenspiel.h"

using namespace std;

int main()  {
    character einHeld("held", 20, 5);
    character guteHexe("guteHexe", 10, 11);
    character Allianz = einHeld + guteHexe;
    Character einBoesewicht("bösewicht", 18, 15);
    einHeld.inDenKampf(einBoesewicht);
    /*for (character i = 0; i<10; i++) {
        std::cout<<i;
    }*/
    einHeld += guteHexe;
    std::cout<<(einHeld==einHeld)<<std::endl;
    std::cout<<(guteHexe==einBoesewicht)<<std::endl;
    int ival =2, fval = 9999999;
    fval>>ival;
    std::cout<<fval<<"\n";
    return 0;
}