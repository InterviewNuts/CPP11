/**
 * @file pass_promise_to_thread.cpp
 * @author haramohan sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-16
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
1) std::future is a class template and its object stores the future value.

2) Actually a std::future object internally stores a value that will be assigned in future and it also provides a 
mechanism to access that value i.e. using get() member function. 

3) But if somebody tries to access this associated value of future through get() function before it is available, 
then get() function will block till value is not available.

4) std::promise is also a class template and its object promises to set the value in future. 
Each std::promise object has an associated std::future object that will give the value once set by 
the std::promise object.

5) A std::promise object shares data with its associated std::future object.
*/
#include <iostream>
#include <thread>
#include <future>
using namespace std;

int f(int x)
{
    return x + 10;
}

int main()
{
    // This will be the write-end
    std::promise<int> promise;
    // This will be the read-end
    auto future = promise.get_future();

    std::thread t([&promise](int x)
                  { promise.set_value(f(x)); },
                  4);

    cout << future.get() << std::endl;

    return 0;
}