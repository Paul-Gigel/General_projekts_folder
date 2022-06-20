#include <iostream>
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
    Spielzeug Dennis("ABC-Würfel",basketball);
    ref1.printAll();
    ref2.set_string("lol");
    ref2.printAll();
    ref3.set_string("luul");
    ref3.printAll();
    ref4[0].printAll();


    return 0;
}