/**
 * @file promiseandFutute.cpp
 * @author your name (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
promise and future is used to carry an information bewtween two threads.
An object can be ferried between two threads.

1)A std::promise object is set by the thread which generates the result.
2) A std::future object can be used to retrieve a value, to test to see if a value is available, or 
to halt execution until the value is available.

there may a situation here we want a thread to return a result or a thread to receive a result, then we can 
use promise and thread


promise is nothing but to promise something by seting its value.
and future will get the value set by promise otherwise it will wait for promise.


1) std::future is a class template and its object stores the future value.
Actually a std::future object internally stores a value that will be assigned in future and 
it also provides a mechanism to access that value i.e. using get() member function. 
But if somebody tries to access this associated value of future through get() function before it is available, 
then get() function will block till value is not available.

2) std::promise is also a class template and its object promises to set the value in future. 
Each std::promise object has an associated std::future object that will give the value once set by the 
std::promise object.

Example:
So , a std::promise object shares data with its associated std::future object.

Every std::promise object has an associated std::future object, through which others can fetch the value set by promise.
So, Thread 1 will create the std::promise object and then fetch the std::future object from it before 
passing the std””promise object to thread 2 i.e.  std::future<int> futureObj = promiseObj.get_future();

Now Thread 1 will pass the promiseObj to Thread 2.
Then Thread 1 will fetch the value set by Thread 2 in std::promise through std::future’s get function,
  int val = futureObj.get();

*/

#include <iostream>
#include <thread>
#include <future>
void initiazer(std::promise<int> * promObj)
{
    std::cout<<"Inside Thread"<<std::endl;     
    //! Here in thread 2 , value is set by promise object which will be available in main thread.
    promObj->set_value(35);
}
int main()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread th(initiazer, &promiseObj);
    std::cout<<futureObj.get()<<std::endl;
    th.join();
    return 0;
}
