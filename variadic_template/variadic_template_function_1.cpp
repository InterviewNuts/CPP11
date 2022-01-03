/**
 * @file variadic_template_function_1.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
A good way to illustrate the variadic template function mechanism is to use it in a re-write of some of the 
functionality of printf:
*/
#include <iostream>

using namespace std;

void print() {
    cout << endl;
}

template <typename T> 
void print(const T& t) {
    cout << t << endl;
}

template <typename First, typename... Rest> 
void print(const First& first, const Rest&... rest) {
    cout << first << ", ";
    print(rest...); // recursive call using pack expansion syntax
}

int main()
{
    print(); // calls first overload, outputting only a newline
    print(1); // calls second overload

    // these call the third overload, the variadic template,
    // which uses recursion as needed.
    print(10, 20);
    print(100, 200, 300);
    print("first", 2, "third", 3.14159);
}
