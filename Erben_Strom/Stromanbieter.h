#include <iostream>
#include <string>
#include "Atomkraft.h"
#include "Windkraft.h"
#ifndef ERBEN_STROM_STROMANBIETER_H
#define ERBEN_STROM_STROMANBIETER_H
class Stromanbieter : public Atomkraft, public Windkraft{
private:
    std::string anbieter;
public:
    Stromanbieter(unsigned int co2 =0, float ct =0.0f,
                  std::string q ="", unsigned int k =0,
                  unsigned int co2_2 =0, float ct_2 =0.0f,
                  std::string q_2 ="", unsigned int k_2 =0,
                  std::string a ="") :
                    Atomkraft(co2, ct, q, k),
                    Windkraft(co2_2, ct_2, q_2, k_2),
                    anbieter(a) {};
    void setStromanbieter(std::string a)    {
        anbieter =a;
    }
    std::string getStromanbieter(void) const    {
        return anbieter;
    }
    void print() const  {
        std::cout<<"Stromanbieter : "<<getStromanbieter()<<std::endl;
        Atomkraft::print();
        Windkraft::print();
    }
};
#endif