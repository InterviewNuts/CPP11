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
     return std::move(dg);
}



void test_unique_ptr::test(Dog *dg)
{

 //unique_ptr<Dog> dg=testFun();
}







