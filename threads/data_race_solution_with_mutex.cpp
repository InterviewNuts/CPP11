/**
 * @file data_race_solution_with_mutex.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>
#include <vector>
#include<mutex>

using namespace std;
std::mutex incr_mt;

void count_even(vector<int>& numbers,int &numEven)
{
    for(auto num:numbers)
    {
        if((num%2)==0)
        {
            incr_mt.lock();
            ++numEven;
            incr_mt.unlock();
        }   
    }

}

int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v2= {11, 12, 13, 14, 15, 16, 17, 18};
    int numEven = 0;
    thread t1(std::ref(count_even),ref(v1),ref(numEven));
    thread t2(std::ref(count_even),ref(v2),ref(numEven));
    t1.join();
    t2.join();
    std::cout << "Total number of even numbers is: " << numEven << std::endl;
    return 0;
}
