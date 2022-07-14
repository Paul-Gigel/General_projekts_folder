#include <iostream>
#include <string>
#include "Headers/Spielzeug.h"
int main()
{
    char football[] = {"Football"};
    char basketball[] = {"Basketball"};
    Spielzeug ref1 = Spielzeug("halloweltstring","halloweltptr");
    Spielzeug ref2 = ref1;
    Spielzeug ref3 = ref2;
    Spielzeug ref4[15];
    Spielzeug Hans("Fussball",football);
    Spielzeug Dennis("Tennisball",basketball);
    Hans.tauschMich(&Hans);
    Hans.printAll();
    Dennis.printAll();


    return 0;
}