#include <iostream>
#include "structures.h"

void class_input();
void prof_input();
void assign_sub();

table create()
{
    int i,j;
    table* t=new table;
    t->scode=new int*[days];
    t->scode[0]=new int[days*periods];
    for(i=1;i<days;++i)
        t->scode[i]=&(t->scode[0][i*periods]);
    for(i=0;i<days;++i)
        for(j=0;j<periods;++j)
            t->scode[i][j]=0;
    return *t;
}

void timetable()
{
    int i,j,k,l,m;
    int* a;
    for(i=0;i<pn;++i)
        p[i].pt=create();
    for(i=0;i<yn;++i)
    {
        a=new int[c[i].sn];
        c[i].ct=new table[c[i].dn];
        for(j=0;j<c[i].dn;++j)
        {
            c[i].ct[j]=create();
            for(m=0;m<c[i].sn;++m)
                a[m]=s[i][m].cred;
            for(l=0;l<periods;++l)
            {
                for(k=0;k<days;++k)
                {
                    for(m=0;m<c[i].sn;++m)
                    {
                        if(a[m] && p[s[i][m].pc].pt.scode[k][l]==0)
                        {
                            p[s[i][m].pc].pt.scode[k][l]=(i+1)*100+m+1;
                            c[i].ct[j].scode[k][l]=(i+1)*100+m+1;
                            --a[m];
                            m=c[i].sn;
                        }
                    }
                }
            }
        }
        delete[] a;
    }
}

void display_table()
{
    int i,j,k,l,m;
    if(system("cls"))
        system("clear");
    
    for(i=0;i<yn;++i)
    {
        for(j=0;j<c[i].dn;++j)
        {
            std::cout<<"Year "<<i+1<<", Div "<<j+1<<":\n";
            for(k=0;k<days;++k)
            {
                for(l=0;l<periods;++l)
                {
                    m=c[i].ct[j].scode[k][l];
                    if(m)
                        std::cout<<s[m/100-1][m%100-1].sname;
                    std::cout<<"\t\t";
                }
                std::cout<<'\n';
            }
            std::cout<<'\n';
        }
    }
    
    for(i=0;i<pn;++i)
    {
        std::cout<<p[i].pname<<":\n";
        for(j=0;j<days;++j)
        {
            for(k=0;k<periods;++k)
            {
                m=p[i].pt.scode[j][k];
                if(m)
                    std::cout<<s[m/100-1][m%100-1].sname;
                std::cout<<"\t\t";
            }
            std::cout<<'\n';
        }
        std::cout<<'\n';
    }
}

int main()
{
    class_input();
    prof_input();
    assign_sub();
    timetable();
    display_table();
    return 0;
}