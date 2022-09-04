#include "Reihe.h"

template<typename T>
T Reihe<T>::getDaten() {
    return data;
}
template<typename T>
void Reihe<T>::setDaten(const T &ival) {
    data = ival;
}
template<>
void Reihe<int>::setDaten(const int& ival) {
    data = ival;
}