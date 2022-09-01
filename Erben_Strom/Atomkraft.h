#include <iostream>
#include <string>
#include "Strom.h"
#ifndef ERBEN_STROM_ATOMKRAFT_H
#define ERBEN_STROM_ATOMKRAFT_H
class Atomkraft : public Strom  {
private:
    unsigned int Co2KWh;
    float ct4KWh;
public:
    Atomkraft(unsigned int co2 =0, float ct =0.0,
              std::string q ="", unsigned int k =0) :Strom(q, k), Co2KWh(co2), ct4KWh(ct) {};
    unsigned int getCo2KWh() const  {
        return Co2KWh;
    }
    float getCt4KWh() const {
        return ct4KWh;
    }
    void setCo2KWh(unsigned int co2)    {
        Co2KWh = co2;
    }
    void setCt4KWh(float ct)    {
        ct4KWh = ct;
    }
    void print() const  {
        std::cout<<"Co2 pro KWh : "<<getCo2KWh()<<std::endl;
        std::cout<<"Cent pro KWh : "<<getCt4KWh()<<std::endl;
        Strom::print();
    }
};
#endif //ERBEN_STROM_ATOMKRAFT_H