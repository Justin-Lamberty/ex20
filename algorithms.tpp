#include "algorithms.hpp"

#include <iostream>



template <template<typename> class ListType, typename T, typename F>
void foreach(ListType<T> & iterable, F & func){
    
    typename ListType<T>::Iterator it = iterable.begin();

    while(!it.isAtEnd()){
        it.get() = func(it.get());
        it.next();
    }
    
}

template <template<typename> class ListType, typename T, typename F>
ListType<T> transform(ListType<T> & iterable, F & func){
    
    ListType<T> output(iterable.getLength());
    
    typename ListType<T>::Iterator init = iterable.begin();
    typename ListType<T>::Iterator outit = ouput.begin();
    
    while(!init.isAtEnd() && !outit.isAtEnd()){
        outit.get() = func(init.get());
        init.next();
        outit.next();
    }
    
    return output; // will use RVO
}

// TODO
template <template<typename> class ListType, typename T, typename F>
std::size_t countif(ListType<T> & iterable, F & func){
    
typename ListType<T>::Iterator it = iterable.begin();
   
   std::size_t count = 0;
   while(!it.isAtEnd()){
        if(func(it.get())){
            count++;
        }
        it.next();
    }
    return count;
}

template <template<typename> class ListType, typename T, typename F>
bool allof(ListType<T> & iterable, F & func){
    
    typename ListType<T>::Iterator it = iterable.begin();

    std::size_t count = 0;
    while(!it.isAtEnd()){
        if(func(it.get())){
            count++;
        }
        it.next();
    }
    return count == iterable.getLength();
}

template <template<typename> class ListType, typename T, typename F>
bool noneof(ListType<T> & iterable, F & func){
    
    typename ListType<T>::Iterator it = iterable.begin();

    std::size_t count = 0;
    while(!it.isAtEnd()){
        if(!func(it.get())){
            count++;
        }
        it.next();
    }
    return count == iterable.getLength();
}

template <template<typename> class ListType, typename T, typename F>
bool anyof(ListType<T> & iterable, F & func){
    
    typename ListType<T>::Iterator it = iterable.begin();

    while(!it.isAtEnd()){
        if(func(it.get())){
            return true;
        }
        it.next();
    }
    return false;
}