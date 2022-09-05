#include <iostream>
#ifndef REIHE_REIHE_H
#define REIHE_REIHE_H
template<typename T>
struct Data {
    T data;
    T* nextdata;
    T& operator=(const T d)   {

    }
};
template<typename T, size_t Max =5>
class Reihe {
private:
    Data<T>* data;
    Data<T>* startData;
    Data<T>* helpData;
public:
    Reihe() : startData(nullptr), helpData(nullptr) {
        *data = new Data<T>;
        //data->data = d;
        startData = data;
        startData->nextdata = nullptr;
        for (size_t i =0;i<=Max;i++)    {
            helpData = startData;
            while (helpData->nextdata != nullptr)   {
                helpData = helpData->nextdata;
            }
            helpData->nextdata = data;
            data->nextdata = nullptr;
        }
    }
    //T& operator[](size_t);
    //void setDaten(const T&);
    //T getDaten();
};
/*template<typename T, size_t Max>
T &Reihe<T>::operator[](size_t size) {
    return ;
}

template<typename T>
T Reihe<T>::getDaten() {
    return data;
}
template<typename T>
void Reihe<T>::setDaten(const T &ival) {
    data = ival;
}
*/
typedef Reihe<int> Reihe_int;
typedef Reihe<double> Reihe_double;
#endif