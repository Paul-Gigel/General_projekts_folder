//
// Created by paul on 09.09.22.
//

#include "Reihe.h"
template<typename T, int max>
Reihe<T, max>::Reihe() {
    daten = max;
}
template<typename T, int max>
T &Reihe<T, max>::getDaten() const {
    return daten;
}
template<typename T, int max>
void Reihe<T, max>::setDaten(const T & in) {
    daten =in;
}