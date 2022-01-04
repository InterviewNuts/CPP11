/**
 * @file Condition_Variable_Using_Threads.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
NOTES:
1. Condition variables allow us to synchronize threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronize two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition

*/

#include<iostream>
#include<iostream>
#include <mutex>
#include <condition_variable>
#include<thread>
using namespace std;
using namespace chrono;


mutex mu;
condition_variable cv;
int balance=0;

void add_money(int money)
{
    lock_guard<mutex> guard(mu);
    balance+=money;
    cout<<"Money "<<money<<" is addeed to balance & your Balance Now = "<<balance<<"\n";
    cv.notify_one();
}

void withdraw_money(int money)
{
    unique_lock<mutex>lock(mu);
    cv.wait(lock,[&money](){
        if (balance!=0) 
        {
            return true;

        }
        else
        {
            cout<<" Sorry you can not withdraw "<<money<< " more then balance & your Balance  = "<<balance<<endl;
            //cout<<" Sorry you can not withdraw more then balance = "<<balance<<endl;
            return false;  
        }
    });

    balance-=money;
    cout<<" Afeter withdraw of = "<<money <<" your Balance = "<<balance<<endl;
    lock.unlock();
    cv.notify_one();

}

int main()
{
    thread t1(withdraw_money,500);
    thread t2(add_money,1500);
    t1.join();
    t2.join();
    return 0;
}