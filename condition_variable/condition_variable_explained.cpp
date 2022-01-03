/**
 * @file condition_variable_explained.cpp
 * @author  Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include<thread>
using namespace std;
using namespace chrono;

class Application
{
    bool m_bDataLoaded=false;
    mutex mt;
    condition_variable mCondi;
    
    public:
      Application()
    {
        m_bDataLoaded = false;
    }

    bool isDataLoaded()
    {
        return m_bDataLoaded;
    }

    
    void loadData()
    {
        //! load Data ( write some text into file
        std::this_thread::sleep_for(chrono::microseconds(1000));
        std::cout<<"Loading Data from XML"<<std::endl;
        //! take the lock;
        std::lock_guard<mutex> guard(mt);
        //! set the variable
        m_bDataLoaded=true;
        //! now notify to other thread on this conditional variable.
        mCondi.notify_one();
    }

    void main_task()
    {
        //! do some hand shaking with server
        std::cout<<"Do Some Handshaking"<<std::endl;
        //! Now aquire lock
        std::unique_lock<mutex> mlock(mt);
        // Start waiting for the Condition Variable to get signaled
        // Wait() will internally release the lock and make the thread to block
        // As soon as condition variable get signaled, resume the thread and
        // again acquire the lock. Then check if condition is met or not
        // If condition is met then continue else again go in wait.
        mCondi.wait(mlock,std::bind(&Application::isDataLoaded,this));
        std::cout<<"Do Processing On loaded Data"<<std::endl;
    }


};

int main()
{

Application app;
    thread t1(&Application::main_task,&app);
    thread t2(&Application::loadData,&app);

    t1.join();
    t2.join();


    return 0;
}

