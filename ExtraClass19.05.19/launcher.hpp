#ifndef LAUNCHER_H_
#define LAUNCHER_H_
#include"item.hpp"
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Launcher{
    protected:
    vector<vector<Item> >matrix;
    int n, m;
    bool isEmpty(const int, const int)const;
    public:
    Launcher(const int, const int);
    bool addElement(const Item&, const int, const int);
    bool removeElement(const int, const int);
    bool moveElement(const int, const int, const int, const int);
    void clear();
    friend ostream& operator<<(ostream&, const Launcher&);
};

bool Launcher::isEmpty(const int x, const int y) const{
    return (matrix[x][y]==Item());
}

Launcher::Launcher(const int _n, const int _m){
    n=_n;
    m=_m;
    matrix.resize(n);
    for(int i=0; i<n; i++){
        matrix[i].resize(m);
    }
}

bool Launcher::addElement(const Item& item, const int x, const int y){
    if(x>=n || y>=m || !isEmpty(x, y)){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isEmpty(i, j)){
                    matrix[i][j]=item;
                    return true;
                }
            }
        }
        return false;
    }
    matrix[x][y]=item;
    return true;
}

bool Launcher::removeElement(const int x, const int y){
     if(x>=n || y>=m || isEmpty(x, y) || !matrix[x][y].canMove()){
        return false;
     }
     matrix[x][y]=Item();
     return true;
}

bool Launcher::moveElement(const int x, const int y, const int u, const int v){
    if(x>=n || y>=m || u>=n || v>=m || isEmpty(x, y) || !matrix[x][y].canMove()){
        return false;
    }
    if(isEmpty(u, v)){
        Item item=matrix[x][y];
        removeElement(x, y);
        addElement(item, u, v);
    }
    else if(matrix[u][v].canMove()){
        Item item=matrix[x][y], item2=matrix[u][v];
        removeElement(x, y);
        removeElement(u, v);
        addElement(item, u, v);
        addElement(item2, x, y);
    }
    else return false;
    return true;
}

void Launcher::clear(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrix[i][j]=Item();
        }
    }
}


ostream& operator<<(ostream& os, const Launcher& l){
    for(int i=0; i<l.n; i++){
        for(int j=0; j<l.m; j++){
            os<<"| "<<setw(15)<<l.matrix[i][j].getTitle()<<" ";
        }
        os<<"|"<<endl;
    }
    return os;
}



#endif // LAUNCHER_H_
