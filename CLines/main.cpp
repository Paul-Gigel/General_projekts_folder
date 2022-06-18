#include <iostream>
#include "headers/Lines.h"
int main()
{
    Lines einfacherStrich('#',20);
    einfacherStrich.printDash();

    Lines nocheinStrich = 30;
    nocheinStrich.printDash();

    Lines einfacherStrich_Kopie(einfacherStrich);
    einfacherStrich_Kopie.printDash();
    return 0;
}
