/**
 * @file call_once.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
std::call_once ensures execution of a function exactly once by competing threads. 
It throws std::system_error in case it cannot complete its task.

Used in conjunction with std::once_flag.

Points:
1) so with above exaplanation, we can say that call_once executes the function only once ,
even if it is called from several thread.

Each group of call_once invocations that receives the same std::once_flag object will meet the 
following requirements:

1) Exactly one execution of exactly one of the functions (passed as f to the invocations in the group) is performed. 
It is undefined which function will be selected for execution. 
The selected function runs in the same thread as the call_once invocation it was passed to.

No invocation in the group returns before the above mentioned execution of the selected function is 
completed successfully, that is, doesn't exit via an exception.

If the selected function exits via exception, it is propagated to the caller. 
Another function is then selected and executed.

*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
std::once_flag flag;


void  call_once_function()
{
    //! cout<<" Call once function called \n";
    //! if you comment out below code , then it will be pring the message 4 times.
    std::call_once(flag,[](){cout<<" Call once function called \n";});
}

int main()
{
    thread T1(call_once_function);
    thread T2(call_once_function);
    thread T3(call_once_function);
    thread T4(call_once_function);

    T1.join();
    T2.join();
    T3.join();
    T4.join();
    return 0;
}
