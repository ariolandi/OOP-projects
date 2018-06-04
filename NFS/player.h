#ifndef __PLAYER_H__
#define __PLAYER_H__
#include<iostream>
#include<cstring>
#include"contestor.h"

/**
 * A Player class - inheritates Contestor class.
 * Player is human-controled Contestor.
 */
class Player: public Contestor{
    private:
        double money;       /** A variable which contains the amound of money a Player has. */
        char *name;         /** A string which contains Player's username. */
    public:
        Player(const char*, const Car&, double);
        Player(const Player&);
        ~Player();
        Player& operator=(const Player&);

        void setMoney(double);
        void setSkills();
        void print()const;
        double getMoney()const;
        char* getName()const;
};
/**
 * A constructor.
 * Each Player has a name, a Car and skills.
 * Player is human Contestor.
 * In the beginning the PLayer has no money.
 */
Player::Player(const char* _name, const Car& car, double skills):Contestor(car, skills){
    is_human = true;
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    money = 0;
}
/**
 * A Copy constructor.
 */
Player::Player(const Player& other):Contestor(other){
    name = new char[strlen(other.name)+1];
    strcpy(name, other.name);
    money = other.money;
}
/**
 * A destructor.
 */
Player::~Player(){
    delete name;
}

/**
 * Assignment operator (=):
 * Deletes current data of a Player and it gets other Player's data.
 */
Player& Player::operator=(const Player& other){
    if (this != &other){
        Contestor::operator=(other);
        delete name;
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
        money = other.money;
    }
}

/**
 * A money setter - adds certain amound of money to a Player.
 */
void Player::setMoney(double _money){
    money += _money;
}

/**
 * A skills setter - calculates how many skills a contestor will gain.
 */
void Player::setSkills(){
    double _skills = skills/5 + rand()%10;
    Contestor::setSkills(_skills);
    setMoney(_skills*100);
}

/**
 * A print function - prints Player's data.
 */
void Player::print()const{
    cout<<"Name: "<<name<<endl;
    cout<<"Car: "<<car<<"\nSkills: "<<skills<<endl;
}

double Player::getMoney()const{
    return money;
}

char* Player::getName()const{
    return name;
}



#endif // __PLAYER_H__
