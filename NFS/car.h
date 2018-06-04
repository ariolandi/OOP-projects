#ifndef __CARS_H__
#define __CARS_H__
#include<cstring>
#include<iostream>
using namespace std;

/**
 * A Car class.
 */
class Car{
    private:
        char* name;     /** A string which contains car's name (id). */
        bool nitro;     /** A bool variable which indicates if a car has nitro or not. */
        double power;   /** A variable which contains the anound of power a car has. */
    public:
        Car(const char*, bool, int);
        Car(const Car&);
        ~Car();
        Car& operator=(const Car&);
        bool operator==(const Car&)const;
        bool operator!=(const Car&)const;

        double getPower()const;

        friend ostream& operator<<(ostream&, const Car&);
};

/**
 * A constructor.
 * Each car has a name, a nitro indicator and a power amound.
 */
Car::Car(const char *_name, bool _nitro, int _power){
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    nitro = _nitro;
    power = _power;
}
/**
 * A Copy constuctor.
 */
Car::Car(const Car& other){
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    nitro = other.nitro;
    power = other.power;
}
/**
 * A destructor.
 */
Car::~Car(){
    delete name;
}

/**
 * Assignment operator (=):
 * Deletes current data of a car and it gets other car's data.
 */
Car& Car::operator=(const Car& other){
    if(this!=&other){
        delete name;
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
        nitro = other.nitro;
        power = other.power;
    }
}

/**
 * Equal operator (==):
 * Check if two cars are with equal data.
 */
bool Car::operator==(const Car& other)const{
    return (!strcmp(name, other.name) && nitro==other.nitro && power==other.power);
}
/**
 * Not equal operator (!=):
 * Check if two cars are with different data.
 */
bool Car::operator!=(const Car& other)const{
    return !operator==(other);
}
/**
 * A power getter - returns the power of a car.
 */
double Car::getPower()const{
    return power;
}

/**
 * Ostream operator for Car class.
 */
ostream& operator<<(ostream& os, const Car& car){
    os<<car.name<<" ";
    if(car.nitro)os<<"nitro ";
    os<<car.power;
    return os;
}

/**
 * A function which generates a random car.
 */
Car generateCar(const int start_power, int range){
    const char* charrange = "abcdefghijklmnopqrstuvwxyz0123456789";
    int power = start_power + rand()%range;
    bool nitro = rand()%2;
    char name[8];
    for(int j=0; j<8; j++)name[j]=charrange[rand()%strlen(charrange)];
    return Car(name, nitro, power);
}



#endif // __CARS_H__
