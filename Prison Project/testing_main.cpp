#include<iostream>
#include<cstring>
#include"prisoner.h"
#include"gang.h"
#include"prison.h"
using namespace std;

int main()
{
    Prisoner p("Sam", 4);
    Gang g1("gang1");
    p.set_gang(&g1);
    cout<<p;
    Prison prison;
    prison.accept_prisoner(p);
    prison.iterate_days(400);
    cout<<p;


    return 0;
}
