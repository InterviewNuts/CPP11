/**
 * @file shared_ptr.cppp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// cpp11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<memory>
#include<string>
#include<iostream>
using namespace std;


class Dog
{
private:
    string name = "Tommy";
public:
    Dog() = default;
    Dog(string n) :name(n) {
        cout << "Dog Cort called \n";
    }
    ~Dog()
    {
        cout << " Dog Dotr called \n";
    }

    void DogName()
    {
        cout << " Dog Name = " << name << "\n";
    }

};


int main()
{
    shared_ptr<Dog>p(new Dog("puppy"));
    //! shared pointer's reference count gets incremented, 
    //! if it is referenced again by some other shared ptr.
    //! It will print 1
    cout<<p.use_count() <<"\n";

    shared_ptr<Dog>p1=p;
    //! It will print 2
    cout<<p.use_count() <<"\n";
    return 0;
}
