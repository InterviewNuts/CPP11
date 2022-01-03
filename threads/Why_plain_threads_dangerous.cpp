/**
 * @file Why_plain_threads_dangerous.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
When we start a thread, there are two options. 
1) Either we will wait for the thread to finish or 
2) we will not wait for it. 

A mechanism for waiting is a .join() member function. 
The .detach() member function is the other option: not waiting for the thread to finish.

Therefore, we must choose between these two options. If we don’t detach or join the thread, 
the program will crash! 
Just comment a .join() call , compile and run the program. 
You should get an error message:



*/
#include<iostream>
#include<thread>
using namespace std;
void f()
{
    cout<<" f called \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{
    std::thread t1(f);
    std::thread t2(f);
    std::thread t3(f);
    t1.join();
    t2.join();
    t3.join();
    cout<<" Main ends here "<<this_thread::get_id<<endl;
    return 0;
}