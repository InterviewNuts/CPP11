#include <iostream>
#include <thread>
// #include<future>
#include <mutex>

using namespace std;

int counter = 0;
std::mutex mu;

/*
Here the actual lock is not happening , like batch it works so we up 200 value
*/
void incrementCounter_1()
{
    for (int i = 0; i < 100; ++i)
    {
        mu.try_lock();
        counter++;
        cout << "By thread " << std::this_thread::get_id() << " Couner value = " << counter << "\n";
        mu.unlock();
    }
}

void incrementCounter()
{
    for (int i = 0; i < 100; ++i)
    {
        /*
            Here the actual lock is happening , like batch it works so we up 100 value.
            once it is lock , other tread will wait
        */
        if (mu.try_lock())
        {
            counter++;
            cout << "By thread " << std::this_thread::get_id() << " Couner value = " << counter << "\n";

            mu.unlock();
        }
    }
}

int main()
{
    thread t1(incrementCounter_1);
    thread t2(incrementCounter_1);
    //! here we get the thread id of t1 and t2 which is same as in t incrementCounter () function.
    cout << " Id = " << t1.get_id() << "\n";
    cout << " Id = " << t2.get_id() << "\n";
    t1.join();
    t2.join();
    return 0;
}