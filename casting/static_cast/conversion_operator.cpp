/**
 * @file conversion_operator.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<string>
#include <iostream>
using namespace std;
class Int
{
    int x=90;
    
    public:
    Int(int a=88):x(a){
        cout<< " cotr called \n";
    }
    operator string()
    {
        cout<< " Operator  called \n";
        return to_string(x);
    }
};

//! Q: why do we need static cast, where c-style cast is already there.?
// Ans: It is very hard to know or find in large scale project , where is the c style cast. But we can easily find 
//! static_cast <>() , by search.
//! it is one of the iuse case. 


class Base
{

};
class Derive : public Base{

};
int main()
{
    Int obj;
    //! this below statement will call operator string()
    string value = obj;
    cout<<" Value after conversion called = "<<value<<endl;
    //! This below statement will call  constructor as is the case of constructor conversion
    obj=350;
    //! This below statement will call operator as it will convert object to string
    value = obj;
    //cout<<" Value after conversion called = "<<value<<endl;


    //! but now look at the below code , which is more clener and louder
    string s= static_cast<string>(obj);
    cout<<" After static cast = "<<s<<endl;

// concept 2 for static -cast
//! stati_cast is more restrictive then c_style cast.

    char ch='A';
    int *p= (int*)&ch;

    //! This will give you compile time error.
    // int *p1 =  static_cast<int*>(&ch);

    Derive d1;
    Derive d2;

//! static_cast<> should not be used for confused downcast.
//! if you are not sure of the pointer type , then avoid using static_cast, as It it  will not twon error.
    Base *bp1 = static_cast<Base*>(&d1);

    Derive*dp1=static_cast<Derive*>(bp1);



    return 0;
}