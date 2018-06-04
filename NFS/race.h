#ifndef __RACE_H__
#define __RACE_H__
#include"vector.h"
#include"car.h"
#include"contestor.h"
#include"player.h"
#include"computer.h"
#include"pair.h"


/**
 * A Race class which simulates a race.
 * Each race has a list of contestors for each round.
 */
class Race{
    private:
        int rounds;                                 /** Number of rounds for the race. */
        int current_round;                          /** Round counter - indicates the round in a current moment. */
        int number_of_contestors;                   /** Indicates how many contestor will take part in the current round. */
        Map<Contestor*, int>used;                   /** Indicates which contestor has already complete in the current round. */
        Vector<Contestor*> contestors;              /** Contains contestors for the current round. */
        Vector<Contestor*> winners;                 /** Contains winners for the current round. */

        Pair<Contestor*, Contestor*> getPair()const;
    public:
        Race(const Vector<Contestor*>&, int);

        bool finished()const;
        void start(int);
        Contestor* compete(const Pair<Contestor*, Contestor*>&)const;
        Vector<Player*> getPlayers()const;
        Contestor* getPlayer(const char*)const;
        Contestor* getWinner()const;
};

/**
 * A constructor.
 * Each race has a list of contestors and number of rounds.
 * Each race starts from round 0.
 */
Race::Race(const Vector<Contestor*>& _contestors, int _rounds):contestors(_contestors){
    rounds = _rounds;
    current_round = 0;
    number_of_contestors = contestors.size();
    for(int i=0; i<number_of_contestors; i++)used.set(contestors[i], 0);
}

/**
 * A function which gets two random contestor to compete.
 */
Pair<Contestor*, Contestor*> Race::getPair()const{
    Contestor *c, *c1, *c2;
    do{
        c = contestors.getRandom();
    }while(used[c] == current_round);
    c1 = c;
    do{
        c = contestors.getRandom();
    }while(used[c] == current_round);
    c2 = c;
    return Pair<Contestor*, Contestor*>(c1, c2);
}

/**
 * A start function - simulates every round.
 */
void Race::start(int k=0){
    current_round ++;
    for(int i=0; i<(number_of_contestors/2)-k; i++){
        Pair<Contestor*, Contestor*> competitors = getPair();
        winners.push(compete(competitors));
    }
    contestors = winners;
    winners.eraseAll();
}

/**
 * A function which simulates a duel between two contestors.
 */
Contestor* Race::compete(const Pair<Contestor*, Contestor*>& competitors)const{
    Contestor* c1 = competitors.first;
    Contestor* c2 = competitors.second;
    used[c1] = current_round;
    used[c2] = current_round;
    double coef_c1 = (c1->getSkills() + c1->getCarPower())*(100 + rand()%20);
    double coef_c2 = (c2->getSkills() + c2->getCarPower())*(100 + rand()%20);
    Contestor *winner, *loser;
    if(coef_c1 > coef_c2){
        winner = c1;
        loser = c2;
    }
    else{
        winner = c2;
        loser = c1;
    }
    winner->setSkills();
    cout<<"Winner!\n"<<*winner;
    cout<<loser->getName()<<" lost"<<endl<<endl;

    return winner;
}

/**
 * A function which indicates if a race is finished.
 */
bool Race::finished()const{
    return current_round == rounds;
}


Vector<Player*> Race::getPlayers()const{
    Vector<Player*> p;
    for(int i=0; i<contestors.size(); i++){
        if(contestors[i]->isHuman())p.push((Player*)contestors[i]);
    }
    return p;
}

Contestor* Race::getPlayer(const char* _name)const{
    for(int i=0; i<contestors.size(); i++){
        if(!strcmp(_name, contestors[i]->getName()))
            return contestors[i];
    }
    return NULL;
}

Contestor* Race::getWinner()const{
    if(finished()){
        return contestors[0];
    }
    else cout<<"Not finished yet!\n";
}

#endif // __RACE_H__
