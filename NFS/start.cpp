#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include"car.h"
#include"player.h"
#include"computer.h"
#include"contestor.h"
#include"vector.h"
#include"pair.h"
#include"race.h"
using namespace std;

void generateCarsList(Vector<Car> &cars, const int N){
    const int start_power = rand()%1024;
    srand(time(0));
    for(int i=0; i<N; i++){
        Car c = generateCar(start_power, 10);
        cars.push(c);
    }
}

void generateCarStore(Vector<Pair<Car, int> > &store, const int N){
    srand(time(0));
    const int start_power = rand()%1024;
    const int start_price = 1024 + start_power%100;
    for (int i=0; i<N; i++){
        Car c = generateCar(start_power, 1000);
        int price = start_price + rand()%100;
        store.push(Pair<Car, int>(c, price));
    }
}

Computer generateContestor(const Vector<Car> &cars){
    Car c = cars.getRandom();
    double skills = rand()%100;
    return Computer(c, skills);
}

void play(Race& race, const Vector<Pair<Car, int> >& store){
    while(!race.finished()){
        int k=0, id=0, m;
        for(Vector<Player*>::Iterator it=race.getPlayers().begin(); it!=race.getPlayers().end(); ++it){
            id++;
            cout<<"Player "<<id<<": "<<(*it)->getName()<<endl;
            bool flag=0;
            while(!flag){
                flag=1;
                cout<<"1. Buy a new car\n";
                cout<<"2. Play against oponent of your choice\n";
                cout<<"3. Play against random oponent\n";
                cout<<"What whould you like to do? >>"; cin>>m;
                if(m==1){
                    flag=0;
                    cout<<"**STORE**\n";
                    for(int i=0; i<store.size(); i++){
                        cout<<i+1<<": "<<store[i].first<<" :: "<<store[i].second<<"$"<<endl;
                    }
                    cout<<"You have "<<(*it)->getMoney()<<"$"<<endl;
                    int s;
                    cout<<"Choose a car: (-1 for another choice) >>"; cin>>s;
                    if(s!=-1 && s<store.size()){
                        if((*it)->getMoney() >= store[s].second){
                            (*it)->setCar(store[s].first);
                            (*it)->setMoney(store[s].second*(-1));
                        }
                        else{
                            cout<<"You don't have enought money to buy this\n";
                        }
                    }
                }
                else if(m==2){
                    char name[20];
                    cout<<"Enter player's name: >>";
                    cin.ignore();
                    cin.getline(name, 20);
                    cout<<"("<<name<<")\n";
                    Contestor* p = race.getPlayer(name);
                    if(p!=NULL){
                        Pair<Contestor*, Contestor*> pr(*it, race.getPlayer(name));
                        race.compete(pr);
                        k++;
                    }
                    else{
                        cout<<"This player doesn't exist\n";
                        flag=0;
                    }
                }
                else if(m==3){
                    continue;
                }
                else{
                    cout<<"Invalid command!\n";
                    flag=0;
                }
            }
            cout<<endl;
        }
        race.start(k);
    }
    cout<<"Race finished!\n";
    cout<<race.getWinner()->getName()<<" Wins!"<<endl;


}

void game(){
    Vector<Car>cars;
    generateCarsList(cars, 5);
    Vector<Pair<Car, int> >store;
    generateCarStore(store, 5);
    Vector<Contestor*>contestors;

    cout<<"Welcome!\n";
    int n, m;
    cout<<"How many players would you like to create? >>"; cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        char name[20];
        cout<<"Enter your name: >>";
        cin.getline(name, 20);
        double skills = rand()%100;
        Car c = cars.getRandom();
        Player* p = new Player(name, c, skills);
        contestors.push(p);
    }
    cout<<"How many rounds would you like to play? >>"; cin>>m;
    for(int i=0; i<2*m-n; i++){
        Computer* c = new Computer(generateContestor(cars));
        contestors.push(c);
    }
    Race race(contestors, m);
    play(race, store);
}


int main()
{
    game();

    return 0;
}
