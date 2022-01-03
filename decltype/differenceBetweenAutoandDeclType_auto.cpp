/**
 * @file differenceBetweenAutoandDeclType_auto.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include <typeinfo>
#include <type_traits>
/*
1)
decltype gives the declared type of the expression that is passed to it. auto does the same thing as template type deduction. 
So, for example, if you have a function that returns a reference, auto will still be a value (you need auto& to get a reference), 
but decltype will be exactly the type of the return value.

2) auto follows the template argument deduction rules and is always an object type; 
decltype(auto) follows the decltype rules for deducing reference types based on value categories. 
So if we have

int x;
int && f();
then

expression    auto       decltype(auto)
----------------------------------------
10            int        int
x             int        int
(x)           int        int &
f()           int        int &&


*/
using namespace std;

int global{};
int& foo()
{
   return global;
}


void deduce_type()
{
    decltype(foo()) a = foo(); //a is an `int&`
    auto b = foo(); //b is an `int`
    b = 2;

    std::cout << "a: " << a << '\n'; //prints "a: 0"
    std::cout << "b: " << b << '\n'; //prints "b: 2"

    std::cout << "---\n";
    decltype(foo()) c = foo(); //c is an `int&`
    c = 10;

    std::cout << "a: " << a << '\n'; //prints "a: 10"
    std::cout << "b: " << b << '\n'; //prints "b: 2"
    std::cout << "c: " << c << '\n'; //prints "c: 10"
}
auto add (int a, int b)
{
    return (a+b);
}

auto& increment (int &a)
{
    return (++a);
}

decltype(auto) increment_ref (int &a)
{
    ++a;
    return (a);
}
int main()
{
    int xx=9;
    //cout << typeid(add(5,7)).name() << endl;
    //! it will show error as increment , either you use decltype(auto) or
    //! auto& , solves the proble. 
    int &p=increment(xx);
    int &p1=increment_ref(xx);
    //cout << typeid(p).name() << endl;
    //cout << typeid(p1).name() << endl;

    const int x=90;
    auto x_type=x;
    decltype(auto) x_decl_type=x;

    decltype(auto) p_decl_type=p;


    cout <<"x_type = "<< typeid(x_type).name() << endl;
    cout <<"x_decl_type = "<< typeid(x_decl_type).name() << endl;

    cout <<"p_decl_type = "<< typeid(p_decl_type).name() << endl;

    
 
    struct A { double x; };
    const A* a;
 
    decltype(a->x) y;       // type of y is double (declared type)
    decltype((a->x)) z = y; // type of z is const double& (lvalue expression)


  deduce_type();


    
}
