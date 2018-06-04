#ifndef __VECTOR_H__
#define __VECTOR_H__

/**
 * A templated structure which is used for linked list implementation.
 * Each node contains a value field and a pointer to te next node.
 * If a node is not connected to other, the pointer is equal to NULL.
 */
template <typename T>
struct Node{
    T value;
    Node<T>* next;
    Node(const T&);
};
template <typename T>
Node<T>::Node(const T& _value):value(_value){
    next = NULL;
}

/**
 * A templated implementation of vector class.
 * Vector is a dynamic array, implemented with linked list of nodes.
 */
template <typename T>
class Vector{
    private:
        Node<T> *first;     /** A pointer to the first node of the list. */
        Node<T> *last;      /** A pointer to the last node of the list. */
        int s;              /** A variable that contains the current size (number of nodes) of the vector. */
    public:
        Vector();
        bool empty()const;
        int size()const;
        void push(const T&);
        T& getRandom()const;
        void erase(T&);
        void eraseAll();

        Vector<T>& operator=(const Vector<T>&);
        Vector<T>& operator+=(const Vector<T>&);
        T& operator[](int)const;

        class Iterator{
            private:
                Node<T> *element;
            public:
                Iterator(Node<T> *_smth){
                    element = _smth;
                }

                void operator ++(){
                    element = element->next;
                }

                T& operator *()const{
                    return element->value;
                }

                bool operator !=(const Iterator& other)const{
                    return element!=other.element;
                }
        };
        Iterator begin()const{
            return Iterator(first);
        }
        Iterator end()const{
            return Iterator(NULL);
        }
};
/**
 * A constructor.
 * When a vector is constructed, it is empty, i.e. there is no nodes in it.
 */
template <typename T>
Vector<T>::Vector(){
    first = NULL;
    last = NULL;
    s=0;
}

/**
 * A function which check if a vector is empty, i.e. is thete any nodes in it.
 */
template <typename T>
bool Vector<T>::empty()const{
    return first == NULL;
}

/**
 * A size getter - returns the current size of a vector.
 */
template <typename T>
int Vector<T>::size()const{
    return s;
}

/**
 * A function which adds a new node to a vector.
 * If the vector is empty, the node becomes its first element.
 * In other case, connects the last element with the new node.
 */
template <typename T>
void Vector<T>::push(const T& _value){
    Node<T>* node = new Node<T>(_value);
    if(empty())first = node;
    else last->next = node;
    last = node;
    s++;
}

/**
 * A function which returns the element of a vector on random position.
 */
template <typename T>
T& Vector<T>::getRandom()const{
    int position = rand()%s;
    return operator[](position);
}

/**
 * A function which removes an node from a vector.
 */
template<typename T>
void Vector<T>::erase(T& node){
    if(node == first->value){
        first = first->next;
        delete &node;
        s--;
        return ;
    }
    Node<T>*element = first, *previous = NULL;
    while(node != element->value && element != last){
        previous = element;
        element = element->next;
    }
    if(element == last)
        throw out_of_range("Index out of range");
    previous->next = element->next;
    delete element;
    s--;
}

/**
 * A function which clears a vector, removing all its elements.
 */
template<typename T>
void Vector<T>::eraseAll(){
    while(!empty())erase(first->value);
}


/**
 * Assignment operator (=):
 * Makes the current vector equal to other.
 */
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    eraseAll();
    for(int i=0; i<other.size(); i++){
        push(other[i]);
    }
}

/**
 * Plus assignment operator (+=):
 * Adds te nodes from another vector to the current.
 */
template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other){
    for(int i=0; i<other.size(); i++){
        push(other[i]);
    }
}

/**
 * Subscripting operator([]):
 * Returns the element in a certain possition of a vector.
 */
template <typename T>
T& Vector<T>::operator[](int position)const{
    if (position >= s)
        throw out_of_range("Index out of range");
    int p=0;
    Node<T>* element = first;
    while(p<position){
        element = element->next;
        p++;
    }
    return element->value;
}


#endif // __VECTOR_H__
