#include <iostream>
#include "structures.h"

void prof_input()
{
    int i;
    std::cout<<"No of profs: ";
    std::cin>>pn;
    p=new prof[pn];
    for(i=0;i<pn;++i)
    {
        std::cout<<"Prof "<<i+1<<" name: ";
        std::cin>>p[i].pname;
        p[i].sn=0;
    }
    std::cout<<"No of working days: ";
    std::cin>>days;
    std::cout<<"No of periods in a day: ";
    std::cin>>periods;
}