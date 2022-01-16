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
/*
// THE PROBLEM STATEMENT:
// 1. Producer will produce and consumer will consume with synchronization of a common buffer.
// 2. Until producer thread produces any data consumer thread can't consume.
// 3. Threads will use condition_variable to notify each other.
// 4. We need mutex if we use condition_variable because CV waits on mutex.
// 5. This is one of the example of producer consumer there are many.

// PRODUCER thread steps:
// 1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
// 2. check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce.
// 3. insert item in buffer.
// 4. unlock mutex. 
// 5. notify consumer.

// CONSUMER thread steps:
// 1. lock mutex, if success then go ahead and consume otherwise wait for mutex to get free.
// 2. check if buffer is empty and if it is, then unlock the mutex and sleep, if not thean go ahead and consume.
// 3. consume item from buffer.
// 4. unlock mutex.
// 5. notify producer.
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


