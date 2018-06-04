#ifndef __COMPUTER_H__
#define __COMPUTER_H__
#include"contestor.h"

/**
 * A Computer class - inheritances Contestor class.
 * Computer is a computer generated contestor.
 */
class Computer: public Contestor{
    private:
    public:
        Computer(const Car&, double);
        void setSkills();
        void print()const;
        char* getName()const;
};

/**
 * Constructor - each Computer has a Car and skills.
 * The Computer is non human Contestor.
 */
Computer::Computer(const Car& car, double skills):Contestor(car, skills){
    is_human = false;
}
/**
 * A skills setter - calculates how many skills a contestor will gain.
 */
void Computer::setSkills(){
    double _skills = skills/5 + rand()%20;
    Contestor::setSkills(_skills);
}

/**
 * Print function - prints Computer's data.
 */
void Computer::print()const{
    cout<<"Name: Computer"<<endl;
    cout<<"Car: "<<car<<"\nSkills: "<<skills<<endl;
}

char* Computer::getName()const{
    return "Computer";
}


#endif // __COMPUTER_H__

