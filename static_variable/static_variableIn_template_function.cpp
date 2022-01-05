/**
 * @file static_variableIn_template_function.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include<iostream>
using namespace std;

/*
So when you call print() templatised function 2 ttimes with 2 iferent type,
 as expected, there will be a 2 different instantiation for INT and CHAR.
 and as a static variable , ( the meaning of statics variable is it will share the same copy),
 But this notion is not hold true for Template function as well as template class.
 It will have a different copy for that instantiation. 
 Becaus eof this unrelated thing , one function increasing the static variable X, does not get refected in other's
 static x as both are not related.


*/
template<typename T>
void print(T a)
{
static int x=89;
 cout<<"Print static variable X ="<<++x<<endl;
    cout<<"Print Template variable A ="<<a<<endl;
}

int main()
{

    print(12);
    print('B');
    return 0;
}