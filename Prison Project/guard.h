#ifndef __GUARD_H__
#define __GUARD_H__
#include"person.h"
#include<iostream>

/**
 * A class for guard objects.
 * Every guard is a person, i.e. has a name and an experience.
 */
class Guard:public Person{
    private:
    public:
        Guard(const char*);
        ~Guard();
        Guard(const Guard&);
        Guard& operator=(const Guard&);

        void catch_prisoner();

        friend istream& operator>>(istream&, Guard&);
        friend ostream& operator<<(ostream&, const Guard&);
};

Guard::Guard(const char* _name):
Person(_name, 10){}
Guard::~Guard(){}
Guard::Guard(const Guard& other):Person(other){}
Guard& Guard::operator=(const Guard& other){
    if(this != &other){
        Person::operator=(other);
    }
}

void Guard::catch_prisoner(){
    experience += 20;
}

istream& operator>>(istream& is, Guard& g){
    cin>>g.name;
    return is;
}

ostream& operator<<(ostream& os, const Guard& g){
    cout<<"name: "<<g.name<<" experience: "<<g.experience<<endl;
    return os;
}

#endif // __GUARD_H__
