#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template<typename T> T werIstGroeser(T val1, T val2)   {
    if(val1>val2)   {
        return val1;
    }
    return val2;
}
template<> std::string werIstGroeser(std::string val1, std::string val2)    {
    if (val1.length()==val2.length())    {
        return "-1";
    } else if (val1.length()>val2.length()) {
        return val1;
    }
    return val2;
}

int main()  {
    string mystring = "Hall";
    string my2string = "Welt";
    std::cout<<werIstGroeser<int>('A',64)<<"\n";
    char x =5;
    std::cout<< typeid(x).name()<<"\n";
}