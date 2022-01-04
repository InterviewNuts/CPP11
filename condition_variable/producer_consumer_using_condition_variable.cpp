/**
 * @file producer_consumer_using_condition_variable.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<mutex>
#include<deque>
#include <condition_variable>
#include <thread>
using namespace  std;




std::mutex mu;
std::condition_variable cond;
deque<int> buf;
const unsigned bufSize=50;

void producer(int val)
{
    while(val)
    {
        std::unique_lock<mutex> lock(mu);
        cond.wait(lock,[](){return buf.size() < bufSize;});
        cout<<" Value Produced by Producer = "<<val<<endl;
        buf.push_back(val);
        --val;
        lock.unlock();
        cond.notify_one();
    }
}

void consumer()
{
    while(true)
    {
        std::unique_lock<mutex> lock(mu);
        cond.wait(lock,[](){return buf.size()>0;});
        cout<<" Consumed Value = "<<buf.back()<<endl;
        buf.pop_back();
        lock.unlock();
        cond.notify_one();
    }
}

int main()
{
    thread t1(producer,60);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}


