#include "catch.hpp"

#include "array_list.hpp"
#include "linked_list.hpp"
#include "algorithms.hpp"

// Functors for test cases below
template<typename T> 
class Linspace{
public:
  Linspace(T start, T increment): m_value(start), m_inc(increment){};

  T operator()(T x){
    x = m_value;
    m_value += m_inc;
    return x; 
  }
  
private:
  T m_value;
  T m_inc;
};

template<typename T> 
class Accumulator{
public:
  T operator()(T x){
    m_sum += x;
    return x; 
  }

  T result(){ return m_sum; }
  
private:
  T m_sum = T();
};

template<typename T> 
class Square{
public:
  T operator()(T x){
    return x*x; 
  }
};

TEMPLATE_PRODUCT_TEST_CASE("Test foreach", "[algorithms]", (ArrayList, LinkedList), (int, float, double)) {

  // Example: write a functor and foreach call to fill a list with
  // 10 value in sequence 0, 100, 200, ...
  TestType list(10);  
  Linspace<typename TestType::Value> f(0,100);
  foreach(list, f);

  REQUIRE(list.getEntry(1) == 0);
  REQUIRE(list.getEntry(2) == 100);
  REQUIRE(list.getEntry(3) == 200);
  REQUIRE(list.getEntry(10) == 900);

  // Example: then write a functor with foreach to sum the values in the list
  Accumulator<typename TestType::Value> a;
  foreach(list, a);

  REQUIRE(a.result() == 4500);
}
