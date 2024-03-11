#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "abstract_iterator.hpp"

// apply functor to each element of list
template <template<typename> class ListType, typename T, typename F>
void foreach(ListType<T> & iterable, F & func);

// apply functor to each element of list, returning new list
template <template<typename> class ListType, typename T, typename F>
ListType<T> transform(ListType<T> & iterable, F & func);

// apply functor to each element of list, counting number of times it
// it returns true
template <template<typename> class ListType, typename T, typename F>
std::size_t countif(ListType<T> & iterable, F & func);

// apply functor to each element of list, return true if all return true
template <template<typename> class ListType, typename T, typename F>
bool allof(ListType<T> & iterable, F & func);

// apply functor to each element of list, return true if none return true
template <template<typename> class ListType, typename T, typename F>
bool noneof(ListType<T> & iterable, F & func);

// apply functor to each element of list, return true if any return true
template <template<typename> class ListType, typename T, typename F>
bool anyof(ListType<T> & iterable, F & func);

#include "algorithms.tpp"

#endif