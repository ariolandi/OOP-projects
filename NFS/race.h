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
        Contestor* compete(const Pair<Contestor*, Contestor*>&);
        Vector<Player*> getPlayers()const;
        Contestor* getPlayer(const int)const;
        Contestor* getWinner()const;
        void contestorsPrint()const;
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
Contestor* Race::compete(const Pair<Contestor*, Contestor*>& competitors){
    Contestor* c1 = competitors.first;
    Contestor* c2 = competitors.second;
    used[c1] = current_round;
    used[c2] = current_round;
    Contestor *winner, *loser;
    if(c1->compete() > c2->compete()){
        winner = c1;
        loser = c2;
    }
    else{
        winner = c2;
        loser = c1;
    }
    cout<<"Winner!\n"<<*winner;
    cout<<loser->getName()<<" lost"<<endl<<endl;
    winner->setSkills();

    return winner;
}

/**
 * A function which indicates if a race is finished.
 */
bool Race::finished()const{
    return current_round == rounds;
}

/**
 * A function which returns a list of all human contestors.
 */
Vector<Player*> Race::getPlayers()const{
    Vector<Player*> p;
    for(Vector<Contestor*>::Iterator it=contestors.begin(); it!=contestors.end(); ++it){
        if((*it)->isHuman())p.push((Player*)(*it));
    }
    return p;
}

/**
 * A contestor getter.
 */
Contestor* Race::getPlayer(const int idx)const{
    if(idx >= 0 && idx < contestors.size()){
        return contestors[idx];
    }
    return NULL;
}

/**
 * A race winner getter.
 */
Contestor* Race::getWinner()const{
    if(finished()){
        return contestors[0];
    }
    else cout<<"Not finished yet!\n";
}

/**
 * Print function.
 */
void Race::contestorsPrint()const{
    for(int i=0; i<contestors.size(); i++){
        cout<<"["<<i<<"]: "<<*contestors[i]<<endl;
    }
}

#endif // __RACE_H__
