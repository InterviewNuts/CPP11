#include "test_unique_ptr.h"

test_unique_ptr::test_unique_ptr()
{
    //this->dg=new Dog();
}
Dog * test_unique_ptr::get()
{
    return  new Dog();
}



test_unique_ptr::~test_unique_ptr()
{
    //dtor
}


void test_unique_ptr::bark()
{
    dg->bark();
}

unique_ptr<Dog> test_unique_ptr::testFun()
{
     unique_ptr<Dog> dg(new Dog());
	//! here since the return type is  by value , then by default it is like std::move();
	//! the same is not true while receiving the unique pointe as an argument.
	//! to receive it as an argument, then we need to pass the unique pointer as std::move(up);
	//! return dg;
     return std::move(dg);
}



void test_unique_ptr::test(Dog *dg)
{

 //unique_ptr<Dog> dg=testFun();
}







