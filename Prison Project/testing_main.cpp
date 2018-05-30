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
    Prisoner p2 = p;
    Prisoner p3("ahgd", 5);
    p3 = p;
    cout<<p2<<p3;

    Guard guard("James");
    prison.hire_guard(guard);




    return 0;
}
