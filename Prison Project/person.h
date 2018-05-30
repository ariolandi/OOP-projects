#ifndef __PERSON_H__
#define __PERSON_H__
#include<cstring>

/**
 * A base class for person objects - prisoner and guardian.
 * Contains some common data and methods.
 */
class Person{
    protected:
        int experience;
        char* name;
    public:
        Person(const char*, const int);
        ~Person();
        void gain_experience(const int);
        double get_experience()const;
        char* get_name()const;
};
Person::Person(const char* _name, const int _experience){
    name = new char(strlen(_name)+1);
    strcpy(name, _name);
    experience = _experience;
}
Person::~Person(){
    delete name;
}

void Person::gain_experience(const int _experience){
    experience += _experience;
}

double Person::get_experience()const{
    return experience;
}

char* Person::get_name()const{
    return name;
}



#endif // __PERSON_H__
