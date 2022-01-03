/**
 * @file cyclic_reference_problem.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<memory>
using namespace std;
class make_friend
{
    private:
    shared_ptr<make_friend>fren;
    public:
    void make_my_friend(shared_ptr<make_friend>f)
    {
        fren=f;
    }

make_friend()
{
cout<<" make_friend Cotr called \n";
}
~make_friend()
{
    cout<<" make_friend Dotr called \n";
}
};

/*
What is cyclic reference problem with shared_pointer and how it can be solved using weak_ptr?
==============================================================================================
1) Cyclic dependancy will occur when you have two classes A and B where A has a reference to B 
which has a reference to A.
2) So the use count will not be zero and hence they will not be deleted.

In this situation, use weal_ptr. As it will not hold the ownership of the object and 
the reference count will not be increased.
*/

int main()
{
  shared_ptr<make_friend>f1(new make_friend() );
  shared_ptr<make_friend>f2(new make_friend() );
  //!  make_friend Cotr called  twice , But never destuctor callecd.
  // The reason is cyclic reference, can be solved by weak_ptr
 
  f1->make_my_friend(f2);
  f2->make_my_friend(f1);
}
