// polynom_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "polynom_dll.h"
#include <cstring>
using namespace std;
int len(const char *a)
{
    int l=0;
    while (*(a++)) ++l;
    return l;
}
bool bigger(const char *a, const char*b)
{
    int la(len(a)),lb(len(b));
    if (la<lb) return false;
    int ds = la-lb;
    for (int i=0;i<ds;++i)
        if (*(a+i)-48) return 1;
    for (int i=0;i<lb;++i)
        if (*(a+ds+i)!=*(b+i))
            return (*(a+ds+i)>*(b+i));
    return 1;
}
char * cutleft(const char * b) // делтель будет начинаться с единицы
{
	const char *a = b;
    int l = len(a);
    //bool t =true;
    char *r = new char[l+1];
    a--;
    while (!((*(++a))-48));
    strcpy(r,a);
    return r;
}
char * __stdcall divP(const char *d, const char *e, char *r)
{
    char *b = cutleft(e);
    int la(len(d)),lb(len(b));
    char * a = new char[la+1];
	if (!lb){r=0;return "\n";}	//if divide by zero
	r[la]=0;
    strcpy(a,d);
    int sa(-1),i;
    while (bigger(a,b))
    {
        while (!(*(++sa+a)-48)); // search first '1' in *a and save index to sa
        for (i = 0;i<lb;++i)
            *(a+sa+i)=((*(a+sa+i)-48)^(*(b+i)-48))+48;
        r[sa+i-1]=49;
    }
	char * t = cutleft(r);
	strcpy(r,t);
	++r;
	t = cutleft(a);
	delete [] a;
    return t;
}

