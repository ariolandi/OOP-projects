#ifndef __CONTESTOR_H__
#define __CONTESTOR_H__
#include<iostream>
#include"car.h"

/**
 * A Contestor class - base class for race contestors.
 * Contains common data and class methods.
 */
class Contestor{
    protected:
        bool is_human;      /** A bool variable which indicates if the contestor is a Player or a Computer. */
        Car car;            /** A Car with which the Contestor takes part in races. */
        double skills;      /** A variable which indicates how skilled is the Contestor. */
    public:
        Contestor(const Car&, double);
        double getSkills()const;
        double getCarPower()const;
        void setSkills(double);
        void setCar(const Car&);
        virtual void setSkills() = 0;
        virtual void print()const;
        bool isHuman()const;
        virtual char* getName()const = 0;
        double compete()const;

        friend ostream& operator<<(ostream&, const Contestor&);
};
/**
 * A constructor.
 * Each Contestor has a Car and skills.
 */
Contestor::Contestor(const Car& _car, double _skills):car(_car){
    skills = _skills;
}
/**
 * Skills getter - returns how skilled is the Contestor.
 */
double Contestor::getSkills()const{
    return skills;
}
/**
 * Car power getter - returns the power of the current Car of the Contestor.
 */
double Contestor::getCarPower()const{
    return car.getPower();
}

/**
 * Skills setter - adds certain amound of skills to the Contestor.
 */
void Contestor::setSkills(double _skills){
    skills += _skills;
}
/**
 * Car setter - gives the Contestor a new Car.
 */
void Contestor::setCar(const Car& _car){
    car = _car;
}
/**
 * A player indicator
 */
bool Contestor::isHuman()const{
    return is_human;
}

/**
 * Print function - prints Contestor's data.
 */
void Contestor::print()const{
    cout<<"Car: "<<car<<"\nSkills: "<<skills<<endl;
}

/**
 * Competition coeficient getter.
 */
double Contestor::compete()const{
    return (getSkills() + getCarPower())*(100 + rand()%20);
}

/**
 * Ostream operator for Contestor class.
 */
ostream& operator<<(ostream& os, const Contestor& c){
    c.print();
    return os;
}



#endif // __CONTESTOR_H__
