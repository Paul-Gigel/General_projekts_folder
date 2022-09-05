#include <iostream>
#include "Reihe.h"
using namespace std;

int main()	{
	Reihe<int> intis[5];
	for( int i=0; i<5; i++) {
		intis[i].setDaten(i);
	}
	for( int i=0; i<5; i++) {
		cout << intis[i].getDaten() << endl;
	}
    Reihe_double doublis[5];
    for( int i=0; i<5; i++) {
        double d = i+1.5;
        doublis[i].setDaten(d);
    }
    for( int i=0; i<5; i++) {
        cout <<doublis[i].getDaten() << endl;
    }

}
