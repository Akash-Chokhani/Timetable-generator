#include <iostream>
#include "structures.h"

void class_input()
{
    int i,j;
    std::cout<<"No of years: ";
    std::cin>>yn;
    c=new classes[yn];
    s=new sub*[yn];
    for(i=0;i<yn;++i)
    {
        std::cout<<"Div in year "<<i+1<<": ";
        std::cin>>c[i].dn;
        std::cout<<"No of subjects in year "<<i+1<<": ";
        std::cin>>c[i].sn;
        s[i]=new sub[c[i].sn];
        for(j=0;j<c[i].sn;++j)
        {
            std::cout<<"Subject "<<j+1<<": ";
            std::cin>>s[i][j].sname;
            std::cout<<"Credits: ";
            std::cin>>s[i][j].cred;
            std::cout<<"Is lab (0/1): ";
            std::cin>>s[i][j].lab;
        }
        std::cout<<'\n';
    }
}