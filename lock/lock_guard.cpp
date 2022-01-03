/**
 * @file lock_guard.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
1) The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex 
for the duration of a scoped block.

2) When a lock_guard object is created, it attempts to take ownership of the mutex it is given. 
When control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and 
the mutex is released.

3) The lock_guard class is non-copyable.
*/



#include <thread>
#include <mutex>
#include <iostream>
 
int g_i = 0;
std::mutex g_i_mutex;  // protects g_i

void  safe_increment()
{
    //! get the lock 
    std::lock_guard<std::mutex>lock (g_i_mutex);
    g_i++;
    std::cout<<" Curr thread Id = "<<std::this_thread::get_id()<<" G_I value = "<<g_i<<std::endl;
    //! the autiomaticaly the lock object gets destroyed as, it goes out of the scope, so mutext gets release.
}


int main()
{

    //std::cout<<__FUNCTION__<<g_i<<std::endl;
    std::cout << __func__ << ": " << g_i << '\n';
    std::thread t1(safe_increment);
     std::thread t2(safe_increment);
    t1.join();
    t2.join();
 
    std::cout << __func__ << ": " << g_i << '\n';
    return 0;
}