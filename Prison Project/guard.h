#ifndef __GUARD_H__
#define __GUARD_H__
#include"person.h"

/**
 * A class for guard objects.
 * Every guard is a person, i.e. has a name and an experience.
 */
class Guard:public Person{
    private:
    public:
        Guard(const char*);
        void catch_prisoner();

        friend istream& operator>>(istream&, Guard&);
        friend ostream& operator<<(ostream&, Guard&);
};

Guard::Guard(const char* _name):
Person(_name, 10){}

void Guard::catch_prisoner(){
    experience += 20;
}

istream& operator>>(istream& is, Guard& g){
    cin>>g.name;
    return is;
}

ostream& operator<<(ostream& os, Guard& g){
    cout<<"name: "<<g.name<<" experience:"<<g.experience<<endl;
    return os;
}

#endif // __GUARD_H__
