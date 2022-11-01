//
// Created by paul on 09.09.22.
//

#ifndef REIHE_REIHE_H
#define REIHE_REIHE_H

/*--------------------------------------------------------------------------------------------------------------------*/
template<typename T ,int max = 35>
class Reihe {
private:
    T daten;
public:
    Reihe();
    void setDaten(const T&);
    T& getDaten() const;
};
/*--------------------------------------------------------------------------------------------------------------------*/
typedef Reihe<int> Reihe_int;
typedef Reihe<double> Reihe_double;
#endif //REIHE_REIHE_H