#include <iostream>
#include <string>
#include "Strom.h"
#ifndef ERBEN_STROM_ATOMKRAFT_H
#define ERBEN_STROM_ATOMKRAFT_H
class Atomkraft : public Strom  {
private:
    unsigned int Co2KWh;
    float Ct4KWh;
public:
    Atomkraft(unsigned int co2 =0, float ct =0.0,
              std::string q ="", unsigned int k =0) :Strom(q, k), Co2KWh(co2), Ct4KWh(ct) {};
    unsigned int getCo2KWh() const  {
        return Co2KWh;
    }
    float getCt4KWh() const {
        return Ct4KWh;
    }
    void setCo2KWh(unsigned int co2)    {
        Co2KWh = co2;
    }
    void setCt4KWh(float ct)    {
        Ct4KWh = ct;
    }
    void print() const  {
        std::cout<<"Co2 pro KWh : "<<getCo2KWh()<<std::endl;
        std::cout<<"Cent pro KWh : "<<getCt4KWh()<<std::endl;
        Strom::print();
    }
    void xprint() const  {
        std::cout<<"Co2 pro KWh : "<<Co2KWh<<std::endl;
        std::cout<<"Cent pro KWh : "<<Ct4KWh<<std::endl;
        std::cout<<"Cent pro KWh : "<<quelle<<std::endl;
        std::cout<<"Cent pro KWh : "<<KWh<<std::endl;
    }
};
#endif //ERBEN_STROM_ATOMKRAFT_H
