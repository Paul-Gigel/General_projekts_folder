#include <iostream>
#include "Atomkraft.h"
#include "Windkraft.h"
#include "Stromanbieter.h"

int main()  {
    Stromanbieter anbieter01;;
    anbieter01.Atomkraft::setCo2KWh(22);
    anbieter01.Atomkraft::setCt4KWh(2.65f);
    anbieter01.Windkraft::setCo2KWh(10);
    anbieter01.Windkraft::setCt4KWh(2.5f);
    anbieter01.setQuelle("Atomkraft und Windkraft");
    anbieter01.setKWh(12000);
    anbieter01.print();
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