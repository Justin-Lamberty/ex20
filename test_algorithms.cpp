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

//TEMPLATE_PRODUCT_TEST_CASE("Test transform", "[algorithms]", (ArrayList, LinkedList), (int, float, double)) {
TEMPLATE_PRODUCT_TEST_CASE("Test transform", "[algorithms]", (ArrayList), (int, float, double)) {

  // Example: write a functor and forach call to fill a list with
  // 100 values in sequence 0, 1, 2, ...
  TestType list(100);  
  Linspace<typename TestType::Value> f(0,1);
  foreach(list, f);

  // Example: transform the list to create a new one with each entry squared
  Square<typename TestType::Value> s;
  TestType list2 = transform(list, s);

  typename TestType::Value temp = 0;
  for(std::size_t i = 0; i < 100; ++i){
    REQUIRE(list2.getEntry(i+1) == temp*temp);
    temp += 1;
  }
}

template<typename T>
class Even{
public:
  bool operator()(const T& x){
	  // TODO
      // write some code to check to see if x is even with the mod function
      return true; 
  }
};

TEST_CASE("Test countif", "[algorithms]") {

  ArrayList<int> list(100);  
  Linspace<int> f(1,1);
  foreach(list, f);
  
  // TODO: write a functor to use with countif to count the number of even
  // values between 1 and 100

}

template<typename T>
struct DivisibleBy3{
  bool operator()(const T& x){
    return ( (x % 3) == 0 );
  }
};

TEST_CASE("Test allof, noneof, anyof", "[algorithms]") {

  LinkedList<int> list;
  list.insert(1, 3);
  list.insert(1, 14);
  list.insert(1, 130);
  list.insert(1, 1302);
  
  // TODO: write a functor to use with
 
  
  // allof to test if all entries are evenly divisible by 3
  
  
  // noneof to test if no entries are evenly divisible by 3
  
  
  // anyof to test if any entries are evenly divisible by 3
  
}