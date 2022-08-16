#include <iostream>
#include "rollenspiel.h"

using namespace std;

typedef character Character;
int main()  {
    character einHeld("held", 20, 5);
    character guteHexe("guteHexe", 10, 11);
    //character Allianz = einHeld + guteHexe;
    Character einBoesewicht("bösewicht", 18, 15);
    //Allianz.inDenKampf(einBoesewicht);
    einHeld += guteHexe;
    einHeld.inDenKampf(einBoesewicht);
    return 0;
}