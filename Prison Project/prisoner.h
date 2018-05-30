#ifndef __PRISONER_H__
#define __PRISONER_H__
#include<iostream>
#include<cmath>
#include"person.h"
#include"gang.h"
using namespace std;


/**
 * A class for prisoner objects.
 * Every prisoner is a person, i.e. has a name and an experience.
 * Every prisoner has a conviction (years).
 * A prisoner may be a member of a prison gang.
 */
class Prisoner:public Person{
    private:
        double conviction;
        Gang* gang;
    public:
        Prisoner(const char*, const double);
        ~Prisoner();
        Prisoner(const Prisoner&);
        Prisoner& operator=(const Prisoner&);
        void reduce_convistion();
        void set_gang(Gang*);
        Gang* get_gang()const;

        void operator+=(const Prisoner&);

        friend istream& operator>>(istream&, Prisoner&);
        friend ostream& operator<<(ostream&, const Prisoner&);
        friend void join_gang(Prisoner&, const Prisoner&);

};
Prisoner::Prisoner(const char* _name, const double _conviction):
Person(_name, 0){
    conviction = _conviction;
    gang = NULL;
}
Prisoner::~Prisoner(){}
Prisoner::Prisoner(const Prisoner& other):Person(other){
    conviction = other.conviction;
    gang = other.gang;
}
Prisoner& Prisoner::operator=(const Prisoner& other){
    if(this != &other){
        Person::operator=(other);
        conviction = other.conviction;
        gang = other.gang;
    }
}


void Prisoner::reduce_convistion(){
    conviction--;
}
void Prisoner::set_gang(Gang* g){
    gang = g;
    experience = pow(2, gang->get_members()/2);
}

Gang* Prisoner::get_gang()const{
    return gang;
}


void Prisoner::operator+=(const Prisoner& other){
    gang = other.gang;
    gang->add_member();
    experience = pow(2, gang->get_members()/2);
}


istream& operator>>(istream& is, Prisoner& p){
    cin>>p.name>>p.conviction;
    return is;
}

ostream& operator<<(ostream& os, const Prisoner& p){
    cout<<"name: "<<p.name<<" experience: "<<p.experience<<" conviction: "<<p.conviction<<endl;
    if(p.gang != NULL){
        cout<<"gang: "<<p.gang->get_name()<<endl;
    }
    return os;
}


void join_gang(Prisoner& p1, const Prisoner& p2){
    p1.set_gang(p2.gang);
}


#endif //__PRISONER_H__
