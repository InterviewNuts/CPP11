/**
 * @file callable_objects.cpp
 * @author Haramohan Sahu(hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>
#include <future>
#include <functional>
using namespace std;

std::once_flag flag;

struct AddObj
{
int x=10;
int add(int n)
{
    this->x=10;
    this->x=this->x+n;
    cout<<" Value from add = "<< this->x<<"\n";
    return this->x;
}

void result()
{
    cout<<" Value = "<< this->x<<"\n";
}

int operator()(int n)
{
    this->x=10;
    this->x=this->x+n;
    cout<<" Value from operator = "<< this->x<<"\n";
    return this->x;
}
};

int main()
{
    AddObj obj;
    //! we call call these AddObjj class in various ways.
    thread T1(obj,20); // this is copy of object passed to thread
    thread T2(std::ref(obj),20); // refereence  mean the same object
    thread T3([](int x){return x+x;},1002); // this a lambda function call


    thread T4(&AddObj::add,obj,1002); // copy of Obj.add(1002)
    thread T5(&AddObj::add,&obj,1002); // copy of Obj.add(1002)


    T2.join();
    T1.join();
    T4.join();
    T3.join();
    T5.join();
    cout<<" 1 st call\n";
    obj.result();

    std::async(std::launch::async,std::ref(obj),30);
    cout<<" 2nd call\n";
    obj.result();

    std::bind(std::ref(obj),60);
    cout<<"3 rd call\n";
    obj.result();

    std::call_once(flag,std::ref(obj),100);
    cout<<" 4th  call\n";
    obj.result();
    
    
}