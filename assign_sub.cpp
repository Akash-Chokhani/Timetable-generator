#include <iostream>
#include "structures.h"

void assign_sub()
{
    int i,j,x;
    if(system("cls"))
        system("clear");
    std::cout<<"Assign profs to subjects\n\n";
    std::cout<<"Id\tProf name\n";
    for(i=0;i<pn;++i)
        std::cout<<i+1<<'\t'<<p[i].pname<<'\n';
    std::cout<<"\nEnter Id of prof to subjects\n";
    for(i=0;i<yn;++i)
    {
        for(j=0;j<c[i].sn;++j)
        {
            std::cout<<s[i][j].sname<<": ";
            std::cin>>x;
            s[i][j].pc=x-1;
            ++p[x-1].sn;
        }
    }
    for(i=0;i<pn;++i)
    {
        p[i].sc=new int[p[i].sn];
        p[i].sn=0;
    }
    for(i=0;i<yn;++i)
    {
        for(j=0;j<c[i].sn;++j)
        {
            x=s[i][j].pc;
            p[x].sc[p[x].sn]=100*(i+1)+j+1;
            ++p[x].sn;
        }
    }
}