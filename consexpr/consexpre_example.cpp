/**
 * @file consexpre_example.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/*
1)  The main idea is performance improvement of programs by doing computations at compile time rather than run time.
2) In C++ 11, a constexpr function should contain only one return statement. C++ 14 allows more than one statements.
3) constexpr function should refer only constant global variables.
4) constexpr function can call only other constexpr function not simple function.
5) Function should not be of void type and some operator like prefix increment 
(++v) are not allowed in constexpr function.


constexpr vs inline functions:
=============================
Both are for performance improvements, inline functions request compiler to expand at compile time and 
save time of function call overheads.In inline functions, expressions are always evaluated at run time. 

constexpr is different, here expressions are evaluated at compile time.

*/


#include<iostream>
using namespace std;


constexpr long int fib(int n)
{
    return (n <= 1)? n : fib(n-1) + fib(n-2);
}
  
/*
time a.exe 
bash: a.exe: command not found

real    0m0.082s
user    0m0.000s
sys     0m0.031s

haramohan.sahu@IN-4D1NMT2 MINGW64 ~/Desktop/c++11 (master)
// this after changed ( I mean I have removed const)
$ time a.exe 
bash: a.exe: command not found

real    0m0.163s
user    0m0.000s
sys     0m0.030s

Change,
  const long int res = fib(30);  
To,
  long int res = fib(30);

*/
void call_fib()
{
    // value of res is computed at compile time. 
    const long int res = fib(30);
    cout << res<<"\n";
}


constexpr int product(int x, int y)
{
    return (x * y);
}
  
void call_product()
{
    const int x = product(10, 20);
    cout << x;
}
int main()
{
    call_fib();
    return 0;
}
