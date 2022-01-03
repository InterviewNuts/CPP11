/**
 * @file shared_ptr_with_Thread.cpp
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
#include<thread>
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


void foo(shared_ptr<Dog>sp)
{
    cout<<" In Foo = "<<sp.use_count()<<"\n";
}

int main()
{

    shared_ptr<Dog>p(new Dog("puppy"));
    //! shared pointer is  thread safe is partly yes,
    //! as A std::shared_ptr consists of a control block and its resource , where CB( control block is thread safe but not the resource.)
    // as resource will be deleted once.
    /*
    std::shared_ptr is not thread safe.

A shared pointer is a pair of two pointers, one to the object and one to a control block (holding the ref counter, 
links to weak pointers ...).
There can be multiple std::shared_ptr and whenever they access the control block to change the reference counter 
it's thread-safe but the std::shared_ptr itself is NOT thread-safe or atomic.
If you assign a new object to a std::shared_ptr while another thread uses it, 
it might end up with the new object pointer but still using a pointer to the control block of the old object => CRASH.
*/



thread t1(foo,p),t2(foo,p),t3(foo,p);


t1.join();
t2.join();
t3.join();
cout<<"\nIn Main: "<<p.use_count()<<"\n";
    return 0;
}
