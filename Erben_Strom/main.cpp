#include <iostream>
#include "Atomkraft.h"

int main()  {
    Atomkraft meilerl;
    meilerl.setQuelle("Atomkraft");
    meilerl.setKWh(1000);
    meilerl.setCo2KWh(16);
    meilerl.setCt4KWh(2.64f);
    meilerl.xprint();
    return 0;
}
/*
#define Zugriffsrecht public
class Basisklasse   {
private     : int pri;
public      : int pub;
protected   : int pro;
};
class UnterKlasse : Zugriffsrecht Basisklasse {

};
class UnterUnterKlasse : public UnterKlasse {
    void init() {
        pri = 1;
        pub = 2;
        pro = 3;
    }
};
void test() {
    UnterUnterKlasse obj;
    obj.pri = 0;
    obj.pub = 0;
    obj.pro = 0;
}
*/