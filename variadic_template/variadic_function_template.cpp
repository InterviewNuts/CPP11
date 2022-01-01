/*
Variadic Template is introduced in C++11. Variadic Template allows a function to take variable number of arguments of any type

1.) It should accept any type of arguments.
2.) It should accept variable number of arguments.

Vardiac Template Function: 
Creating function that accepts variable number of arguments of ant type

template<typename T, typename ... Args>
void log(T first, Args ... args);


 Here, Args… represents variable number of template parameters.


Declaring a vardiac template function is easy but its definition is little tricky. 
We cann’t access the the passed variable number of arguments directly. We need to use the c++ 
type deduction mechanism & recursion to achieve this. 

Let’s define the variadic function i.e.

 * Variadic Template Function that accepts variable number
 * of arguments of any type.
 
template<typename T, typename ... Args>
void log(T first, Args ... args) {
    // Print the First Element
    std::cout<<first<<" , ";
    // Forward the remaining arguments
    log(args...);
}


now call it like below:
log(2, 3.4 , "aaa");

=======================

As we have passed 3 arguments of int, double & const char * type. 
So, using template type deduction mechanism, compiler will internally create following function out of the given 
variadic template function i.e.
void log(int first, double b, const char * c)
{
  std::cout<<first<<" , ";
  log(b, c);
}


It will print the first parameter and forward other 2 parameters to another log function. Now using template type 
deduction mechanism,  compiler will internally create following function out of the 
given variadic template function i.e.
void log(double first, const char * c)
{
  std::cout<<first<<" , ";
  log(c);
}

It will print the first parameter and forward other 1 parameters to another log function. 
Now using template type deduction mechanism, compiler will internally create following function out of the 
given variadic function i.e.
void log(const char * first)
{
  std::cout<<first<<" , ";
  log();
}

It will print the first parameter and as no other argument is received, it will call the log() function 
with no parameter i.e. then returns back. That’s why we defined a log() function with no parameter.

So, this will be stack trace of calling above variadic template function is as follows,
void log();
void log(const char * first);
void log(double first, const char * c);
void log(int first, double b, const char * c);


*/

#include <iostream>
// Function that accepts no parameter
// It is to break the recursion chain of vardiac template function
void log()
{
}
/*
 * Variadic Template Function that accepts variable number
 * of arguments of any type.
 */
template<typename T, typename ... Args>
void log(T first, Args ... args) {
    // Print the First Element
    std::cout<<first<<" , ";
    // Forward the remaining arguments
    log(args ...);
}
int main() {
    log(2, 3.4, "aaa");
    return 0;
}