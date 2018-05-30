#ifndef __PRISON_H__
#define __PRISON_H__
#include"prisoner.h"
#include"guard.h"
#include<ctime>

/**
 * A class for prison objects.
 * Every prison has guards, prisoners and 4 floors with 20 cells on each.
 */
class Prison{
    private:
        bool cells[4][20];
        int number_guards, number_prisoners;
        Guard** guards;
        Prisoner** prisoners;
        void copyPrison(const Prison&);
    public:
        Prison();
        ~Prison();
        Prison(const Prison&);
        Prison& operator=(const Prison&);
        void hire_guard(Guard&);
        void accept_prisoner(Prisoner&);
        void hire_guard();
        void accept_prisoner();
        void iterate_days(int)const;
        void prison_break(const Prisoner&);
};
void Prison::copyPrison(const Prison& other){
    number_guards = other.number_guards;
    number_prisoners = other.number_prisoners;
    guards = new Guard*[number_guards];
    for (int i=0; i<number_guards; i++)
        guards[i] = other.guards[i];
    prisoners = new Prisoner*[number_prisoners];
    for(int i=0; i<number_prisoners; i++)
        prisoners[i] = other.prisoners[i];
    for(int i=0; i<4; i++)
        for(int j=0; j<20; j++)cells[i][j] = other.cells[i][j];
}


Prison::Prison(){
    number_guards = 0;
    number_prisoners = 0;
    guards = new Guard*[0];
    prisoners = new Prisoner*[0];
    for(int i=0; i<4; i++)
        for(int j=0; j<20; j++)cells[i][j]=0;

}
Prison::~Prison(){
    delete guards;
    delete prisoners;
}
Prison::Prison(const Prison& other){
    copyPrison(other);
}
Prison& Prison::operator=(const Prison& other){
    delete guards;
    delete prisoners;
    copyPrison(other);
}

void Prison::accept_prisoner(Prisoner& p){
    int i=0, j=0;
    while(cells[i][j]==1){
        j++;
        if(j==20){
            j=0;
            i++;
            if(i==4){
                cout<<"Not enought space!\n";
                return ;
            }
        }
    }
    cells[i][j]=1;

    Prisoner** tmp = new Prisoner*[number_prisoners+1];
    for(int i=0; i<number_prisoners; i++){
        tmp[i] = prisoners[i];
    }
    delete prisoners;
    prisoners = tmp;
    prisoners[number_prisoners] = &p;
    number_prisoners++;
}

void Prison::hire_guard(Guard& g){
    Guard** tmp = new Guard*[number_guards+1];
    for(int i=0; i<number_guards; i++){
        tmp[i] = guards[i];
    }
    delete guards;
    guards = tmp;
    guards[number_guards] = &g;
    number_guards++;
}

void Prison::accept_prisoner(){
    char name[10];
    cout<<"enter name: ";
    cin>>name;
    int conviction;
    cout<<"enter conviction: ";
    cin>>conviction;
    Prisoner* p = new Prisoner(name, conviction);
    accept_prisoner(*p);
}

void Prison::hire_guard(){
    char name[10];
    cout<<"enter name: ";
    cin>>name;
    Guard* g = new Guard(name);
    hire_guard(*g);
}

/**
 * Simulates time without events.
 */
void Prison::iterate_days(int days)const{
    int exp = days/4;
    for(int i=0; i<number_guards; i++){
        guards[i]->gain_experience(exp);
    }
    for(int j=0; j<days/365; j++){
        for(int i=0; i<number_prisoners; i++)
            prisoners[i]->reduce_convistion();
    }

}

/**
 * A prisoner tries to escape.
 * If he has more experience that the guard two other members of the same gang try too.
 * Else the guard gains experience.
 */
void Prison::prison_break(const Prisoner& p){
    Guard* g = guards[(p.get_gang()->get_members()*7)%number_guards];
    if(p.get_experience() > g->get_experience()){
        bool flag = 0;
        for(int i=0; i<number_prisoners; i++){
            if(flag)prisoners[i-1] = prisoners[i];
            if(prisoners[i] == &p)flag = 1;
        }
        number_prisoners--;
        srand(0);
        for(int i=0; i<2; i++){
            Prisoner* p1;
            do{
                p1 = prisoners[rand()%number_prisoners];
            }while(p1->get_gang() != p.get_gang());
            prison_break(*p1);
        }
    }
    else{
        g->catch_prisoner();
    }
}


#endif //__PRISON_H__
