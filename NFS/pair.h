#ifndef __PAIR_H__
#define __PAIR_H__
#include "vector.h"


/**
 * A templated structure which is used to hold two elements together.
 */
template <typename T1, typename T2>
struct Pair{
    T1 first;
    T2 second;
    Pair(const T1&, const T2&);
};
template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& _first, const T2& _second):
first(_first), second(_second){}


/**
 * A templated structure which contains a vector of Pair.
 * It is used for fast access to a current node from the vector.
 */
template<typename T1, typename T2>
struct Map{
    private:
        Vector<Pair<T1, T2> >arr;
    public:
        T2& operator[](const T1&)const;
        void set(const T1&, const T2&);
};

template<typename T1, typename T2>
T2& Map<T1, T2>::operator[](const T1& _key)const{
    for(int i=0; i<arr.size(); i++){
        if(arr[i].first == _key) return arr[i].second;
    }
}
/**
 * A function which adds a new node to a map.
 */
template<typename T1, typename T2>
void Map<T1, T2>::set(const T1& _key, const T2& _value){
    arr.push(Pair<T1, T2>(_key, _value));
}


#endif // __PAIR_H__
