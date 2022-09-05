#include <iostream>
#ifndef REIHE_REIHE_H
#define REIHE_REIHE_H

template<typename T, size_t Max =5>
class Reihe {
private:
    size_t size =Max;
    T date[Max];
public:
    void setDaten(const T&);
    T& getDaten();
    Reihe<T, 1> operator[](const T&);
};

template<typename T, size_t Max>
T& Reihe<T, Max>::getDaten() {
    return date[0];
}
template<typename T, size_t Max>
void Reihe<T, Max>::setDaten(const T &ival) {
    date[0] = ival;
}
template<typename T, size_t Max>
Reihe<T, 1> Reihe<T, Max>::operator[](const T &i) {
    if (i>Max||i<0) {
        std::cerr<<"out of Bound\n";
        exit(1);
    }
    Reihe<T, 1> tmp;
    tmp.date[0] = this->date[i];
    return tmp;
}

typedef Reihe<int> Reihe_int;
typedef Reihe<double> Reihe_double;
#endif