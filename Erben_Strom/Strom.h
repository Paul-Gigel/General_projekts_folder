#include <iostream>
#include <string>
#ifndef ERBEN_STROM_STROM_H
#define ERBEN_STROM_STROM_H
class Strom {
protected:
    std::string quelle;
    unsigned int KWh;
public:
    Strom():quelle(""), KWh(0)  {};
    Strom(std::string q, unsigned int k):quelle(q), KWh(k)  {};

    void setQuelle(const std::string& q)   {
        quelle =q;
    }
    void setKWh(unsigned int k) {
        KWh =k;
    }

    std::string getQuelle() const   {
        return quelle;
    }

    unsigned int getKWh() const {
        return KWh;
    }

    void print() const  {
        std::cout<<"Stromquelle : "<<getQuelle()<<std::endl;
        std::cout<<"KWh : "<<getKWh()<<std::endl;
    }
};
#endif