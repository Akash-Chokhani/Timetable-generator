struct sub
{
    char sname[10];
    int cred;
    int pc;
    int lab;
};

struct table
{
    int** scode;
};

struct prof
{
    char pname[10];
    int sn;
    int* sc;
    table pt;
};

struct classes
{
    int dn;
    int sn;
    table* ct;
};

inline int yn;
inline int pn;
inline int days;
inline int periods;

inline sub** s;
inline prof* p;
inline classes* c;