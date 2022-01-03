/**
 * @file constexpr_with_class_constructor.cpp.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
A constructor that is declared with a constexpr specifier is a constexpr constructor. Previously, only expressions of built-in types could be valid constant expressions. With constexpr constructors, objects of user-defined types can be included in valid constant expressions.

Definitions of constexpr constructors must satisfy the following requirements:
The containing class must not have any virtual base classes.
Each of the parameter types is a literal type.
Its function body is = delete or = default; otherwise, it must satisfy the following constraints:
It is not a function try block.
The compound statement in it must contain only the following statements:
null statements
static_assert declarations
typedef declarations that do not define classes or enumerations
using directives
using declarations
Each nonstatic data member and base class subobject is initialized.
Each constructor that is used for initializing nonstatic data members and base class subobjects is a constexpr constructor.
Initializers for all nonstatic data members that are not named by a member initializer identifier are constant expressions.
When initializing data members, all implicit conversions that are involved in the following context must be valid in a constant expression:
Calling any constructors
Converting any expressions to data member types
The implicitly defined default constructor performs the set of initializations of the class that would be performed by a user-written default constructor for that class with no initializer and an empty compound-statement. If that user-defined default constructor would satisfy the requirements of a constexpr constructor, the implicitly defined default constructor is a constexpr constructor.

A constexpr constructor is implicitly inline.
*/




struct BASE {
};

struct B2 {
  int i;
};

//NL is a non-literal type.
struct NL {     
  virtual ~NL() {   
  }
};    

int i = 11;

/*
what is literal in C++?
Ans:
The values assigned to each constant variables are referred to as the literals. 
Generally, both terms, constants and literals are used interchangeably. 
For eg, “const int = 5;“, is a constant expression and the value 5 is referred to as constant integer literal. 
There are four types of literals in C and five types of literals in C++.

*/

struct D1 : public BASE {
  //OK, the implicit default constructor of BASE is a constexpr constructor.
  constexpr D1() : BASE(), mem(55) { }
  
  //OK, the implicit copy constructor of BASE is a constexpr constructor.
  constexpr D1(const D1& d) : BASE(d), mem(55) { } 

  //OK, all reference types are literal types.
  constexpr D1(NL &n) : BASE(), mem(55) { }

  //The conversion operator is not constexpr.
  operator int() const { return 55; }      

private:    
  int mem;
};  

struct D2 : virtual BASE { 
  //error, D2 must not have virtual base class.
  constexpr D2() : BASE(), mem(55) { }    

private:
  int mem; 
};  

struct D3 : B2 {
  //error, D3 must not be a function try block.   
  constexpr D3(int) try : B2(), mem(55) { } catch(int) { }

  //error, illegal statement is in body.
  constexpr D3(char) : B2(), mem(55) { mem = 55; } 
  
  //error, initializer for mem is not a constant expression. 
  constexpr D3(double) : B2(), mem(i) { }

  //error, implicit conversion is not constexpr. 
  constexpr D3(const D1 &d) : B2(), mem(d) { }                   

  //error, parameter NL is a non-literal type.
  constexpr D3(NL) : B2(), mem(55) { } 

private: 
  int mem;
};
