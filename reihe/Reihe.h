#ifndef REIHE_REIHE_H
#define REIHE_REIHE_H
template<typename T>
class Reihe {
private:
    T data;
public:
    void setDaten(const T&);
    T getDaten();
};

template<typename T>
T Reihe<T>::getDaten() {
    return data;
}
template<typename T>
void Reihe<T>::setDaten(const T &ival) {
    data = ival;
}
#endif