//
// Created by paul on 15.06.22.
//

#ifndef CLINES_LINES_H
#define CLINES_LINES_H
#include <iostream>
class Lines
{
private:
    char dash;
    unsigned int length;
public:
    Lines():dash('-'),length(10) {};
    explicit Lines(const Lines& L)
    {
        dash = 'c';
        length = L.length * 2;
    }
    Lines(char d,unsigned int l):dash(d),length(l) {};
    Lines(unsigned int l):dash('-'),length(l) {};
    void printDash()
    {
        for (int i = 0; i < length; ++i) {
            std::cout<<dash;
        };
        std::cout<<std::endl;
    }
};
#endif //CLINES_LINES_H
