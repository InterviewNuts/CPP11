/**
 * @file lambda_example.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<string>
using namespace std;

/*
1) The key word auto is a compile time type deduction.
2) Since compile time, ,hence during compile time only , 2 types of methods gets instantiated .
*/
int main()
{
    //! auto inside lambda was no allowed in c++11, but it was introduced in c++14 onwards.
    auto add = [](auto a, auto b){return a+b;};

   cout<< add(2,4)<<endl;
   string str1="Haramohan ";
   string str2="Sahu";
   cout<< add(str1,str2);

    return 0;
}
