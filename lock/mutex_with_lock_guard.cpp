/**
 * @file mutex_with_lock_guard.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-18
 *
 * @copyright Copyright (c) 2022
 *
 */
// NOTES:
// 0. It is very light weight wrapper for owning mutex on scoped basis.
// 1. It aquires mutex lock the moment you create the object of lock_guard.
// 2. It automatically removes the lock while goes out of scope.
// 3. You can not explicitly unlock the lock_guard.
// 4. You can not copy lock_guard.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mu;
int counter = 0;

void incr_counter(int forCount)
{
    std::lock_guard<mutex> lock(mu);
    for (int i = 0; i < forCount; i++)
    {
        counter++;
        cout << "By thread " << std::this_thread::get_id() << " Couner value = " << counter << "\n";
    }
}
int main()
{
    thread t1(incr_counter, 10);
    thread t2(incr_counter, 10);
    t1.join();
    t2.join();
    return 0;
}
