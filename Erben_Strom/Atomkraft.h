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
    void calc(float& ct, unsigned int& Co2) const{
        unsigned int KWh = getKWh();
        ct = Ct4KWh*KWh;
        Co2 = Co2KWh*KWh;
        //Ct4KWh =0; ->thats what "const" saves me from
    }
    void print() const  {
        std::cout<<"Co2 pro KWh : "<<getCo2KWh()<<std::endl;
        std::cout<<"Cent pro KWh : "<<getCt4KWh()<<std::endl;
        Strom::print();
        float ct;
        unsigned int Co2;
        calc(ct, Co2);
        std::cout<<"Co2 gesamt : "<<Co2<<std::endl;
        std::cout<<"Cent gesamt : "<<ct<<std::endl;
    }
};
#endif //ERBEN_STROM_ATOMKRAFT_H
