


/*
what is Variadic templates?

Before C++11, templates had a fixed number of parameters that must be specified in the 
declaration of the templates. Templates could not directly express a class or function template that had a 
variable number of parameters.

With the variadic templates feature, you can define class or function templates that have any number (including zero) of parameters. 
To achieve this goal, this feature introduces a kind of parameter called parameter pack to represent a list of zero or more parameters for templates.

The variadic template feature also introduces pack expansion to indicate that a parameter pack is expanded.

A template parameter pack is a template parameter that represents any number (including zero) of template parameters.
Syntactically, a template parameter pack is a template parameter specified with an ellipsis. 
Consider the following example.

template<class...A> struct container{}; 
template<class...B> void func();

In this example, A and B are template parameter packs.
According to the type of the parameters contained in a template parameter pack, there are three kinds of template parameter packs:
1) Type parameter packs
2) Non-type parameter packs
3) Template template parameter packs

The following example shows a type parameter pack:
------------------------------------------------
template<class...T> class X{};

X<> a;                    // the parameter list is empty 
X<int> b;                 // the parameter list has one item
X<int, char, float> c;    // the parameter list has three items 
In this above example, the type parameter pack T is expanded into a list of zero or more type template parameters.


The following example shows a Non-type parameter pack:
------------------------------------------------
template<bool...A> class X{};

X<> a;                    // the parameter list is empty 
X<true> b;                // the parameter list has one item
X<true, false, true> c;   // the parameter list has three items 

Default arguments cannot be used for a template parameter pack. Consider the following example:
template<typename...T=int> struct foo1{};


Function parameter packs:
==========================
A function parameter pack is a function parameter that represents zero or more function parameters. 
Syntactically, a function parameter pack is a function parameter specified with an ellipsis.

In the definition of a function template, a function parameter pack uses a template parameter pack in the function 
parameters. The template parameter pack is expanded by the function parameter pack. 
Consider the following example:

template<class...A> 
void func(A...args) 
{
    
}

In this example, A is a template parameter pack, and args is a function parameter pack.
You can call the function with any number (including zero) of arguments:
func();                  // void func(); 
func(1);                 // void func(int); 
func(1,2,3,4,5);         // void func(int,int,int,int,int);
func(1,'x', aWidget);    // void func(int,char,widget);       


*/


#include <cassert>
#include<iostream>
using namespace std;
/*
A function parameter pack is a trailing function parameter pack if it is the last function parameter of a 
function template. Otherwise, it is a non-trailing function parameter pack. A function template can have 
trailing and non-trailing function parameter packs. A non-trailing function parameter pack can be deduced only 
from the explicitly specified arguments when the function template is called. If the function template is 
called without explicit arguments, the non-trailing function parameter pack must be empty, 
as shown in the following example:
*/
template<class...A, class...B> 
void func(A...arg1,int sz1, int sz2, B...arg2)  
{
   //assert( sizeof...(arg1) == sz1);
  // assert( sizeof...(arg2) == sz2);

   cout<<" sz1 = "<<sz1<<"\n";
   cout<<" sz2 = "<<sz2<<"\n";

   cout<<" size of 1st function call param = "<<sizeof...(arg1) <<endl;
   cout<<" size of 2st function call param = "<<sizeof...(arg2) <<endl;

}

int main(void)
{
   //A:(int, int, int), B:(int, int, int, int, int,int) -> 6 arguments 
   // when the function gets instantiated, 
   // A:(int,int,int)-> 3 arguments , so sizeof...(arg1)  will be = 3
   // B:(int,int,int,int,int,int)-> 3 arguments , so sizeof...(arg2)  will be = 6
   //! this values 1,2,3 will be for A and 
   //! sz1 = 31 and sz2=51, 
   //! rest of the values will be for B:(1,2,3,4,5,6), hence sizeof...(arg2)=6
    func<int,int,int>(1,2,3,31,51,1,2,3,4,5,6);


   //A: empty, B:(int, int, int, int, int)
  // func(0,5,1,2,3,4,5);
   return 0;
}