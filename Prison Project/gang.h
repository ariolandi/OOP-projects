#ifndef __GANG_H__
#define __GANG_H__"
#include<cstring>

/**
 * A class for gang objects.
 * Contains gang's name and number of its members.
 */
class Gang{
    private:
        char* name;
        int members;
    public:
        Gang(const char*);
        ~Gang();
        void add_member();
        char* get_name()const;
        int get_members()const;
};

Gang::Gang(const char* _name){
    name = new char(strlen(_name)+1);
    strcpy(name, _name);
    members = 0;
}
Gang::~Gang(){
    delete name;
}

void Gang::add_member(){
    members++;
}

char* Gang::get_name()const{
    return name;
}

int Gang::get_members()const{
    return members;
}

#endif // __GANG_H__
