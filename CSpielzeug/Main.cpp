#include <iostream>
#include "Headers/Spielzeug.h"
int main()
{
    Spielzeug ref1 = Spielzeug("halloweltstring","halloweltptr");
    Spielzeug ref2 = ref1;
    Spielzeug ref3 = ref2;
    ref1.printAll();
    ref2.set_string("lol");
    ref2.printAll();
    ref3.set_string("luul");
    ref3.printAll();
    return 0;
}